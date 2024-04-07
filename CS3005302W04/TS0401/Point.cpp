#include "Point.h"

void Point::Set(int vertical, int horizontal)
{
	this->vertical = vertical;
	this->horizontal = horizontal;
}

void Point::Move(int x, int y)
{
	this->vertical += x;
	this->horizontal += y;
}
void Point::Rotate()
{
	int ver = this->vertical;
	int hor = this->horizontal;
	this->vertical = hor;
	this->horizontal = -ver;
}
