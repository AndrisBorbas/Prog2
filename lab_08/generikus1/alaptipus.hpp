#pragma once

template </*int S, */typename T = double>
class Alaptipus {
	T adat;
public:
	Alaptipus(T i = 0) :adat(i) {}  /// konstruktor �s egyben konverzi�s oper�tor
	operator T&() { return adat; }/// cast
	operator T() const { return adat; } /// const cast
	T* operator&() { return &adat; }
	const T* operator&() const { return &adat; }
	virtual ~Alaptipus() {}
};