#include "pstring.h"

std::ostream& operator<<(std::ostream& os, const PString& s0) {
	os << s0.c_str();
	return os;
}

std::istream& operator>>(std::istream& is, PString& s0) {
	unsigned char ch;
	s0 = String("");            // üres string, ehhez fűzünk hozzá
	std::ios_base::fmtflags fl = is.flags(); // eltesszük a régi flag-eket
	is.setf(std::ios_base::skipws);			// az elején eldobjuk a ws-t
	while (is >> ch) {
		is.unsetf(std::ios_base::skipws);	// utána pedig már nem
		if (isspace(ch)) {
			is.putback(ch);             // na ezt nem kérjük
			break;
		}
		else {
			s0 = s0 + ch;               // végére fűzzük a karaktert
		}
	}
	is.setf(fl);						// visszaállítjuk a flag-eket
	return is;
}

void PString::write(std::ostream& os) {
	os << size() << " " << c_str();
}

void PString::read(std::istream& is) {
	size_t tempsize;
	PString asd="";
	unsigned char ch;
	std::ios_base::fmtflags fl = is.flags();
	is >> tempsize;
	is.unsetf(std::ios_base::skipws);
	is >> ch;
	while (tempsize>0){
		is >> ch;
		asd = asd + ch;
		tempsize--;
	}
	PString wasd(asd);
	*this = wasd;
	is.setf(fl);
}
