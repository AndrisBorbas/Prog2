#include "ustring.h"

bool UString::isUpper = false;

void UString::UCase(bool isBig) {
	isUpper = isBig;
}

bool UString::UCase() {
	return isUpper;
}

bool UString::UCase() const {
	return isUpper;
}

std::ostream& operator<<(std::ostream& os, const UString& s0) {
	if (false == (s0.UCase())) {
		os << s0.c_str();
	}
	else {
		for (size_t i = 0; i < s0.size(); i++) {
			os << static_cast<char>(toupper(s0[i]));
		}
	}
	return os;
}