#pragma once
#include <stdlib.h>
#include <memory>

class Point		// class for representing points
{
public:
	Point(int x, int y) : xCoord(x), yCoord(y) {}
	void setX(int newVal)	{ xCoord = newVal; }
	void setY(int newVal) { yCoord = newVal; }
	int getX() const { return xCoord; }
	int getY() const { return yCoord; }
private:
	int xCoord;
	int yCoord;
};

struct RectData		// Point data for a Rectangle
{
	RectData(const Point& coord1, const Point& coord2) : ulhc(coord1.getX(), coord1.getY()), lrhc(coord2.getX(), coord2.getY()) {}
	Point ulhc;		// ulhc = "upper left-hand corner"
	Point lrhc;		// lrhc = "lower right-hand corner"
};

class GUIObject
{
public:
	GUIObject(const Point& coord1, const Point& coord2) : ulhc(coord1.getX(), coord1.getY()), lrhc(coord2.getX(), coord2.getY()) {}
	const Point& upperLeft() const { return ulhc; }
	const Point& lowerRight() const { return lrhc; }

private:
	Point ulhc;		// ulhc = "upper left-hand corner"
	Point lrhc;		// lrhc = "lower right-hand corner"
};

class Rectangle
{
public:
	Rectangle(const Point& upperLeft, const Point& lowerRight);
	const Point& upperLeft() const { return pData->ulhc; }
	const Point& lowerRight() const { return pData->lrhc; }
private:
	std::shared_ptr<RectData> pData;
};