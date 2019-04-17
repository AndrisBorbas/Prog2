/*
 * \file point.h
 *
 */


#ifndef POINT_H
#define POINT_H

/// Point oszt�ly
/// Sz�nd�kosan egyszer� (buta)
class Point {
    int x;
    int y;
public:
    Point(int x = 0, int  y = 0) :x(x), y(y) { }
    int getX() const { return x; }
    int getY() const { return y; }
};

#endif // POINT_H
