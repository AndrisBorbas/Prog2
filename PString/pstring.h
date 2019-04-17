#pragma once

#include "string5.h"
#include "serializable.h"

class PString : public String, public Serializable {

public:
	PString(const char* p = "") :String(p) {}
	PString(char ch) :String(ch) {}
	PString(const String& s1) :String(s1) {}

	void write(std::ostream&);
	void read(std::istream&);

};

std::ostream& operator<<(std::ostream& os, const PString& s0);

std::istream& operator>>(std::istream& is, PString& s0);