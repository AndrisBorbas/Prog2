/*
Copyright (c) 2017, 2018 Sir Kane

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


/*
Compile as x64
Put oo2core_3_win64.dll in the same folder as the exe
Requires bcrypt.lib
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <Windows.h>
#include <bcrypt.h>
#include <vector>
#include <map>
#include <string>

/*
You need to fill these in
*/

const static uint8_t g_AESKey0[16] = {

};

const static uint8_t g_AESKey1[16] = {

};

static const uint8_t s_NonceInit[12] = {

};

class CBlob{
protected:
	void*	m_pData = nullptr;
	size_t	m_Size = 0;
	size_t	m_Capacity = 0;
public:
	inline CBlob(){
	}
	inline ~CBlob(){
		if (m_pData != nullptr){
			free(m_pData);
		}
	}
	CBlob(const CBlob &) = delete;
	CBlob(CBlob&&) = delete;
	CBlob &operator=(const CBlob&) = delete;
	CBlob &operator=(CBlob&&) = delete;
	inline bool Resize(size_t size){
		if (size <= m_Capacity && m_pData != nullptr){
			m_Size = size;
			return true;
		}
		m_pData = realloc(m_pData, size);
		m_Capacity = m_Size = size;

		return m_pData != nullptr;
	}
	inline void* GetPointer(){
		return m_pData;
	}
	inline const void* GetPointer() const{
		return m_pData;
	}
	inline size_t Size() const{
		return m_Size;
	}
};

bool LoadFileToBlob(const char* pFileName, CBlob &blob){
	FILE* pFile;
	if (fopen_s(&pFile, pFileName, "rb") != 0){
		return false;
	}
	if (fseek(pFile, 0, SEEK_END) != 0){
		fclose(pFile);
		return false;
	}
	long length = ftell(pFile);
	if (length == -1){
		fclose(pFile);
		return false;
	}
	if (!blob.Resize((size_t)length)){
		fclose(pFile);
		return false;
	}
	if (fseek(pFile, 0, SEEK_SET) != 0){
		fclose(pFile);
		return false;
	}
	if (fread(blob.GetPointer(), 1, blob.Size(), pFile) == blob.Size()){
		fclose(pFile);
		return true;
	}
	fclose(pFile);
	return false;
}


bool WriteBlobToFile(const wchar_t* pFileName, const CBlob &blob){
	FILE* pFile;
	if (_wfopen_s(&pFile, pFileName, L"wb") != 0){
		return false;
	}
	if (blob.Size() != 0 &&
		fwrite(blob.GetPointer(), blob.Size(), 1, pFile) != 1){
		fclose(pFile);
		return false;
	}
	fclose(pFile);
	return true;
}

struct SOodleDecodeInfo {
	uint32_t	OutputGenerated;
	uint32_t	InputConsumed;
	uint32_t	B[6];
};

typedef int32_t(*pfnOodleLZDecoder_MemorySizeNeeded)(uint32_t a, int64_t b);

typedef void* (*pfnOodleLZDecoder_Create)(uint32_t a, int64_t b, void* pBuffer, size_t bufferSize);
typedef uint32_t(*pfnOodleLZDecoder_DecodeSome)(void* pDecoder /*rcx*/, SOodleDecodeInfo* pInfo /*rdx*/, void*a /*r8*/,
	uint32_t b /*r9*/, size_t c/*+20*/, size_t d /*+28*/, const void*e /*+30*/, size_t f /*+38*/, uint32_t g  /*+40*/,
	uint32_t h /*+48*/, uint32_t i /*+50*/, uint32_t j /*+58*/);

typedef void(*pfnOodleLZDecoder_Destroy)(void* pDecoder);




struct SOodle{
	HMODULE	hOodleDll;
	pfnOodleLZDecoder_Create			OodleLZDecoder_Create;
	pfnOodleLZDecoder_Destroy			OodleLZDecoder_Destroy;
	pfnOodleLZDecoder_DecodeSome		OodleLZDecoder_DecodeSome;
	pfnOodleLZDecoder_MemorySizeNeeded	OodleLZDecoder_MemorySizeNeeded;
};

bool InitOodle(SOodle &oodle){
	oodle.hOodleDll = LoadLibraryA("oo2core_3_win64.dll");
	if (oodle.hOodleDll == nullptr){
		return false;
	}
	oodle.OodleLZDecoder_Create = (pfnOodleLZDecoder_Create)GetProcAddress(oodle.hOodleDll,
		"OodleLZDecoder_Create");
	oodle.OodleLZDecoder_Destroy = (pfnOodleLZDecoder_Destroy)GetProcAddress(oodle.hOodleDll,
		"OodleLZDecoder_Destroy");
	oodle.OodleLZDecoder_DecodeSome = (pfnOodleLZDecoder_DecodeSome)GetProcAddress(oodle.hOodleDll,
		"OodleLZDecoder_DecodeSome");
	oodle.OodleLZDecoder_MemorySizeNeeded = (pfnOodleLZDecoder_MemorySizeNeeded)GetProcAddress(oodle.hOodleDll,
		"OodleLZDecoder_MemorySizeNeeded");

	return oodle.OodleLZDecoder_Create != nullptr &&
		oodle.OodleLZDecoder_Destroy != nullptr &&
		oodle.OodleLZDecoder_DecodeSome != nullptr &&
		oodle.OodleLZDecoder_MemorySizeNeeded != nullptr;
}

SOodle	g_Oodle;

struct SPkgHeader{
	uint16_t	Version;
	uint16_t	Platform;
	uint16_t	PackageID;
	uint16_t	field_6; //Possibly padding
	uint32_t	field_8;
	uint32_t	field_C;
	uint32_t	field_10;
	uint32_t	field_14;
	uint32_t	field_18;
	uint32_t	field_1C;
	uint16_t	PatchID;
	uint16_t	field_22;
	uint32_t	BuildString; //char[], unknown size
	uint32_t	field_28;
	uint32_t	field_2C;
	uint32_t	field_30;
	uint32_t	field_34;
	uint32_t	field_38;
	uint32_t	field_3C;
	uint32_t	field_40;
	uint32_t	field_44;
	uint32_t	field_48;
	uint32_t	field_4C;
	uint32_t	field_50;
	uint32_t	field_54;
	uint32_t	field_58;
	uint32_t	field_5C;
	uint32_t	field_60;
	uint32_t	field_64;
	uint32_t	field_68;
	uint32_t	field_6C;
	uint32_t	field_70;
	uint32_t	field_74;
	uint32_t	field_78;
	uint32_t	field_7C;
	uint32_t	field_80;
	uint32_t	field_84;
	uint32_t	field_88;
	uint32_t	field_8C;
	uint32_t	field_90;
	uint32_t	field_94;
	uint32_t	field_98;
	uint32_t	field_9C;
	uint32_t	field_A0;
	uint32_t	field_A4;
	uint32_t	field_A8;
	uint32_t	field_AC;
	uint32_t	SignatureOffset;
	uint32_t	EntryTableSize;
	uint32_t	EntryTableOffset;
	uint8_t		EntryTableHash[20];
	uint32_t	BlockTableSize;
	uint32_t	BlockTableOffset;
	uint8_t		BlockTableHash[20];
	uint32_t	UnkTableSize;
	uint32_t	UnkTableOffset;
	uint32_t	UnkTableEntrySize;
	uint8_t		UnkTableHash[20];
	uint32_t	field_10C;
	uint32_t	field_110;
	uint32_t	field_114;
	uint32_t	field_118;
	uint32_t	field_11C;
	uint32_t	field_120;
	uint32_t	field_124;
	uint32_t	field_128;
	uint32_t	field_12C;
	uint32_t	field_130;
	uint32_t	field_134;
	uint32_t	field_138;
	uint32_t	field_13C;
	uint32_t	field_140;
	uint32_t	field_144;
	uint32_t	field_148;
	uint32_t	field_14C;
	uint32_t	field_150;
	uint32_t	field_154;
	uint32_t	field_158;
	uint32_t	field_15C;
	uint32_t	field_160;
	uint32_t	field_164;
	uint32_t	field_168;
	uint32_t	field_16C;
};

struct SPkgBlock{
	uint32_t	Offset;
	uint32_t	Size;
	uint16_t	PatchID;
	uint16_t	Flags;
	uint8_t		Hash[20];
	uint8_t		GCMTag[16];
};

enum : uint8_t {
	PKG_BLOCK_FLAG_COMPRESSED = 1,
	PKG_BLOCK_FLAG_ENCRYPTED = 2,
	PKG_BLOCK_FLAG_ALTERNATE_KEY = 4,
};

/*


uint64_t a = (entry.B >> 0) & 0x3FFF; //14, start block
uint64_t b = (entry.B >> 0xE) & 0x3FFF; //14, in block offset
uint64_t c = (entry.B >> 0x1C) & 0x3FFFFFFF; //30
uint64_t d = (entry.B >> 0x3A) & 0x3F; //6
*/
struct SPkgEntry{
	uint64_t	A;
	uint64_t	StartBlock : 14;
	uint64_t	BlockOffset : 14; //0x10 byte chunk count
	uint64_t	Size : 30;
	uint64_t	Unknown : 6;
};

#define NT_SUCCESS(Status)          (((NTSTATUS)(Status)) >= 0)

static void MakeNonce(uint8_t nonce[12], uint16_t packageID /*?*/){
	memcpy(nonce, s_NonceInit, 12);
	nonce[11] ^= (uint8_t)(packageID & 0xFF);
	nonce[1] ^= 0x26;
	nonce[0] ^= (uint8_t)(((int16_t)packageID >> 8) & 0xFF);
}

bool DecryptBlock(CBlob &inputBuffer, CBlob &outputBuffer,
	uint16_t packageId, const uint8_t* pTag, bool useAlternateKey){
	BCRYPT_ALG_HANDLE hAesAlg;
	if (!NT_SUCCESS(BCryptOpenAlgorithmProvider(&hAesAlg, BCRYPT_AES_ALGORITHM, nullptr, 0))){
		return false;
	}
	NTSTATUS status;
	if (!NT_SUCCESS(status = BCryptSetProperty(hAesAlg, BCRYPT_CHAINING_MODE, (PUCHAR)BCRYPT_CHAIN_MODE_GCM,
		sizeof(BCRYPT_CHAIN_MODE_GCM), 0))){
		BCryptCloseAlgorithmProvider(hAesAlg, 0);
		return false;
	}
	outputBuffer.Resize(inputBuffer.Size());
	alignas(alignof(BCRYPT_KEY_DATA_BLOB_HEADER)) unsigned char keyData[sizeof(BCRYPT_KEY_DATA_BLOB_HEADER)
		+ sizeof(g_AESKey0)];

	BCRYPT_KEY_DATA_BLOB_HEADER* pHeader = (BCRYPT_KEY_DATA_BLOB_HEADER*)keyData;
	pHeader->dwMagic = BCRYPT_KEY_DATA_BLOB_MAGIC;
	pHeader->dwVersion = BCRYPT_KEY_DATA_BLOB_VERSION1;
	pHeader->cbKeyData = sizeof(g_AESKey0);
	memcpy(pHeader + 1, useAlternateKey ? g_AESKey1 : g_AESKey0, sizeof(g_AESKey0));
	BCRYPT_KEY_HANDLE hAesKey;

	if (!NT_SUCCESS(status = BCryptImportKey(hAesAlg, nullptr, BCRYPT_KEY_DATA_BLOB, &hAesKey,
		nullptr, 0, keyData, sizeof(keyData), 0))){
		BCryptCloseAlgorithmProvider(hAesAlg, 0);
		return false;
	}
	ULONG decryptionResult;

	BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO cipherModeInfo;


	uint8_t nonce[12];
	MakeNonce(nonce, packageId);
	BCRYPT_INIT_AUTH_MODE_INFO(cipherModeInfo);


	cipherModeInfo.pbTag = (PUCHAR)pTag;
	cipherModeInfo.cbTag = 0x10;

	cipherModeInfo.pbNonce = nonce;
	cipherModeInfo.cbNonce = sizeof(nonce);

	if (!NT_SUCCESS(status = BCryptDecrypt(hAesKey, (PUCHAR)inputBuffer.GetPointer(),
		(ULONG)inputBuffer.Size(), &cipherModeInfo, nullptr, 0,
		(PUCHAR)outputBuffer.GetPointer(), (ULONG)outputBuffer.Size(), &decryptionResult, 0))){
		BCryptDestroyKey(hAesKey);
		BCryptCloseAlgorithmProvider(hAesAlg, 0);
		return false;
	}
	outputBuffer.Resize(decryptionResult);
	BCryptDestroyKey(hAesKey);
	BCryptCloseAlgorithmProvider(hAesAlg, 0);


	//BCryptImportKey(hAesAlg,
	return true;
}

static const uint32_t BlockSize = 0x40000;

bool BlockDecompress(const CBlob &inputBuffer, CBlob &outputBuffer){
	size_t sizeRequired = g_Oodle.OodleLZDecoder_MemorySizeNeeded(0, -1);
	void* pBuffer = alloca(sizeRequired);
	void* pDecoder = g_Oodle.OodleLZDecoder_Create(0, BlockSize, pBuffer,
		sizeRequired);


	bool result = true;

	uint32_t inputOffset = 0;
	uint32_t outputOffset = 0;
	const char* pInput = (const char*)inputBuffer.GetPointer();
	outputBuffer.Resize(BlockSize);
	char* pOutput = (char*)outputBuffer.GetPointer();


	for (; inputOffset < inputBuffer.Size();){
		SOodleDecodeInfo decodeInfo;
		if (g_Oodle.OodleLZDecoder_DecodeSome(
			pDecoder, &decodeInfo, pOutput, outputOffset, BlockSize,
			BlockSize - outputOffset, pInput + inputOffset,
			inputBuffer.Size() - inputOffset, 0, 1, 0, 3) == 0){
			result = false;
			break;
		}
		inputOffset += decodeInfo.InputConsumed;
		outputOffset += decodeInfo.OutputGenerated;
	}
	if (outputOffset < BlockSize){
		memset(pOutput + outputOffset, 0, BlockSize - outputOffset);
	}
	g_Oodle.OodleLZDecoder_Destroy(pDecoder);
	return result;
}

static inline uint32_t ComputeBlockCount(uint32_t offset, uint32_t size){
	return (offset + size + BlockSize - 1) / BlockSize;
}


template<typename T> class TDefer  {
protected:
	T		m_Callback;
	bool	m_NoCall;
public:
	TDefer(T&callback) : m_Callback(callback){
		m_NoCall = false;
	}
	TDefer(TDefer<T> &&rhs){
		m_NoCall = false;
		rhs.m_NoCall = true;
		m_Callback = rhs.m_Callback;
	}
	TDefer(const TDefer<T> &rhs) = delete;
	TDefer &operator=(TDefer<T> &&rhs){
		if (&rhs != this){
			rhs.m_NoCall = true;
			m_Callback = rhs.m_Callback;
		}
		return *this;
	}
	TDefer &operator=(const TDefer<T> &rhs) = delete;
	~TDefer(){
		if (!m_NoCall){
			m_Callback();
		}
	}
};

template<typename T> TDefer<T> Defer(T &callback){
	return TDefer<T>(callback);
}

int LoadPackages(const wchar_t* pPath, std::map<int, FILE*> &files){
	int patchID = -1, packageID = -1;
	std::wstring path = pPath;

	size_t lastPath = path.find_last_of(L"\\/");
	if (lastPath == std::wstring::npos){
		lastPath = 0;
	} else {
		++lastPath;
	}

	size_t extension = path.rfind(L'.', std::string::npos);

	if (extension == std::wstring::npos){
		return -1;
	}
	if (path.substr(extension) != L".pkg"){
		return -1;
	}
	if (extension >= lastPath){
		path.erase(extension);
	}

	size_t lastNonDigit = path.find_last_not_of(L"0123456789");

	if (lastNonDigit == std::wstring::npos ||
		lastNonDigit < lastPath){
		return -1;
	}

	path.erase(lastNonDigit+1);
	path.append(L"*.pkg");

	WIN32_FIND_DATAW findData;
	HANDLE hFind = FindFirstFileW(path.c_str(), &findData);
	if (hFind == INVALID_HANDLE_VALUE){
		DWORD le = GetLastError();
		return -1;
	}
	SPkgHeader header;
	do {
		if ((findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0){
			FILE* f;
			path.erase(lastPath);
			path.append(findData.cFileName);

			if (_wfopen_s(&f, path.c_str(), L"rb") == 0){
				if (fread(&header, sizeof(SPkgHeader), 1, f) == 1 &&
					header.Version == 0x26 && header.Platform == 2){
					if (header.PatchID > patchID){
						patchID = header.PatchID;
					}
					if (packageID == -1){
						packageID = header.PackageID;
					}

					if (packageID == header.PackageID){
						files.insert(std::pair<int, FILE*>(header.PatchID, f));
					} else {
						fclose(f);
					}
				} else {
					fclose(f);
				}
			}
		}
	} while (FindNextFileW(hFind, &findData));
	FindClose(hFind);

	return patchID;
}

bool DoPkg(const wchar_t* pPath, const wchar_t* pOutputPath) {

	std::map<int, FILE*> files;
	int mainPackageIndex = LoadPackages(pPath, files);

	auto defer = Defer([&files]() -> void{
		for (auto it : files){
			fclose(it.second);
		}
	});

	if (mainPackageIndex < 0){
		return false;
	}

	if (files.find(mainPackageIndex) == files.end()){
		return false;
	}

	FILE* fMainArchives = files.at(mainPackageIndex);
	_fseeki64(fMainArchives, 0, SEEK_SET);
	SPkgHeader header;
	if (fread(&header, sizeof(header), 1, fMainArchives) != 1){

		return false;
	}

	std::vector<SPkgBlock> blockTable;
	std::vector<SPkgEntry> entryTable;

	_fseeki64(fMainArchives, (long long)header.BlockTableOffset, SEEK_SET);

	blockTable.resize(header.BlockTableSize);

	for (SPkgBlock &block : blockTable){
		if (fread(&block, sizeof(SPkgBlock), 1, fMainArchives) != 1){
			return false;
		}
	}



	_fseeki64(fMainArchives, (long long)header.EntryTableOffset, SEEK_SET);
	entryTable.resize(header.EntryTableSize);

	for (SPkgEntry &entry : entryTable){
		if (fread(&entry, sizeof(SPkgEntry), 1, fMainArchives) != 1){
			return false;
		}
	}


	static CBlob inputBuffer, blockBuffer, decryptedBuffer, fileBuffer;

	uint32_t loadedBlockIndex = (uint32_t)~(uint32_t)0u;


	wchar_t lBuf[1024];
	size_t index = 0;
	for (const SPkgEntry &entry : entryTable){

		uint32_t blockOffset = (uint32_t)entry.BlockOffset * 0x10;

		uint32_t currentBlock = entry.StartBlock;
		const uint32_t blockCount = ComputeBlockCount(blockOffset, entry.Size);
		const uint32_t lastBlock = currentBlock + blockCount;
		fileBuffer.Resize(entry.Size);
		uint32_t fileOffset = 0;
		for (; currentBlock < lastBlock; ++currentBlock){
			if (currentBlock != loadedBlockIndex){
				if (currentBlock >= blockTable.size()){
					wprintf(L"Block %u out of bounds [0,%zu).\r\n", currentBlock, blockTable.size());
					return false;
				}

				const SPkgBlock &block = blockTable[currentBlock];

				auto it = files.find((int)block.PatchID);
				if (it == files.end()){
					wprintf(L"Block %u uses non-loaded patch ID %u.\r\n", currentBlock, block.PatchID);
					return false;
				}
				FILE* fBlockArchive = it->second;

				inputBuffer.Resize(block.Size);
				_fseeki64(fBlockArchive, block.Offset, SEEK_SET);
				if (fread(inputBuffer.GetPointer(), block.Size, 1, fBlockArchive) != 1){
					wprintf(L"Failed to read block data.\r\n");
					return false;
				}

				if ((block.Flags & PKG_BLOCK_FLAG_ENCRYPTED) != 0){
					CBlob buffer;
					buffer.Resize(sizeof(SPkgBlock));
					memcpy(buffer.GetPointer(), &block, sizeof(SPkgBlock));


					if (!DecryptBlock(inputBuffer, decryptedBuffer, header.PackageID, block.GCMTag,
						(block.Flags & PKG_BLOCK_FLAG_ALTERNATE_KEY) != 0)){
						wprintf(L"Failed to decrypt block %u.\r\n", currentBlock);
						return false;
					}
				} else {
					decryptedBuffer.Resize(block.Size);
					memcpy(decryptedBuffer.GetPointer(), inputBuffer.GetPointer(), block.Size);
				}

				if ((block.Flags & PKG_BLOCK_FLAG_COMPRESSED) != 0){
					if (!BlockDecompress(decryptedBuffer, blockBuffer)){
						wprintf(L"Failed to decompress block %u.\r\n", currentBlock);
						return false;
					}
				} else {
					blockBuffer.Resize(BlockSize);
					if (decryptedBuffer.Size() > BlockSize){
						wprintf(L"Decrypted block %u too large.\r\n", currentBlock);
						return false;
					}
					memcpy(blockBuffer.GetPointer(), decryptedBuffer.GetPointer(),
						decryptedBuffer.Size());
					if (decryptedBuffer.Size() != BlockSize){
						memset((char*)blockBuffer.GetPointer() + decryptedBuffer.Size(),
							0, BlockSize - decryptedBuffer.Size());
					}
				}
				loadedBlockIndex = currentBlock;
			}

			const uint32_t dataAvailable =
				(uint32_t)blockBuffer.Size() - blockOffset < (uint32_t)entry.Size - fileOffset ?
				(uint32_t)blockBuffer.Size() - blockOffset : (uint32_t)entry.Size - fileOffset;

			memcpy((char*)fileBuffer.GetPointer() + fileOffset,
				(char*)blockBuffer.GetPointer() + blockOffset, dataAvailable);

			blockOffset = 0;

			fileOffset += dataAvailable;

		}
		swprintf_s(lBuf, L"%s\\%.4X-%.8zX.bin", pOutputPath, header.PackageID, index++);
		if (WriteBlobToFile(lBuf, fileBuffer)){
			wprintf(L"Successfully wrote \"%s\".\r\n", lBuf);
		} else {
			wprintf(L"Failed to write \"%s\".\r\n", lBuf);
		}

	}
	return true;
}
int wmain(int argc, const wchar_t*const*argv){

	if (!InitOodle(g_Oodle)){
		printf("Failed to initialize oodle.\r\n");
		return 0;
	}


	if (argc < 3){
		printf("Usage: Destiny2Extract.exe <input pak file> <output folder>\r\n");
		printf("The output folder needs to exist.\r\n");
		return 0;
	}
	DoPkg(argv[1], argv[2]);

	return 0;
}
