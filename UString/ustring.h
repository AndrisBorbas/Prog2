#ifndef USTRING_H
#define USTRING_H

#include "string5.h"

class UString : public String {
	static bool isUpper;
public:
	UString(const char* p = "") :String(p) {}
	UString(char ch) :String(ch) {}
	UString(const String& s1) :String(s1) {}

	bool UCase();
	bool UCase() const;
	static void UCase(bool isBig);
};

std::ostream& operator<<(std::ostream& os, const UString& s0);

#endif // USTRING_H
