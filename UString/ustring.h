#ifndef USTRING_H
#define USTRING_H

#include "string5.h"

class UString : public String {

public:
	UString(const char* p = "") :String(p) {}
	UString(char ch) :String(ch) {}
	UString(const String& s1) :String(s1) {}

};

#endif // USTRING_H
