#include <iostream>
#include "Header.h"

Rectangle::Rectangle(const Point& upperLeft, const Point& lowerRight)
{
	pData = std::shared_ptr<RectData>(new RectData(upperLeft, lowerRight));

}

void PrintRectangle(const Rectangle& rect)
{
	std::cout << "(" << rect.upperLeft().getX() << ", " << rect.upperLeft().getY() << ") - (" << rect.lowerRight().getX() << ", "
		<< rect.lowerRight().getY() << ")\n";

}

const Rectangle boundingBox(const GUIObject& obj)	// returns a rectangle by value;
{													// see Item 3 for why return type is const
	return Rectangle(obj.upperLeft(), obj.lowerRight());
}

int main()
{
	Point coord1(0, 0);
	Point coord2(100, 100);

	const Rectangle rec(coord1, coord2);		// rec is a const rectangle from 
												// (0, 0) to (100, 100)
	PrintRectangle(rec);

	//rec.upperLeft().setX(50);					// now rec goes from
												// (50, 0) to (100, 100)!
	PrintRectangle(rec);

	GUIObject *pgo = new GUIObject(coord1, coord2);						// make pgo point to some GUIObject

	const Point *pUpperLeft =				// get a ptr to the uper left point
		&(boundingBox(*pgo).upperLeft());	// of its bounding box

	std::cout << " x = " << pUpperLeft->getX() << ", y = " << pUpperLeft->getY() << "\n";

	std::system("pause");
}