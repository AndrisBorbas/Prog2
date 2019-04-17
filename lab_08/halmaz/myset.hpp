#pragma once

#define ELKESZULT 4

template <typename T>
bool equal(const T& t1, const T& t2) {
	return (t1 == t2);
}
template <>
bool equal<Point>(const Point& t1, const Point& t2) {
	return ((t1.getX() == t2.getX()));
}

template <typename T, size_t s = 10>
class Set {
	T array[s];
	size_t len;
public:
	Set() :len(0) {}
	virtual ~Set() {}
	size_t size() { return len; }
	bool isElement(T item) {
		for (size_t i = 0; i < len; i++) {
			if (equal(item, array[i])) {
				return true;
			}
		}
		return false;
	}
	void insert(T item) {
		if (len == s) {
			throw "nem fér bele";
		}
		else if (!isElement(item)) {
			array[len] = item;
			len++;
		}
	}
};

bool operator==(const Point& p1, const Point& p2) {
	return ((p1.getX() == p2.getX()) && (p1.getY() == p2.getY()));
}