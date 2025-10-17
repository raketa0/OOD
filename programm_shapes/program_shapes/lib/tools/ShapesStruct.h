#pragma once
#include <string>
#include "Constants.h"

struct Point
{
	int x;
	int y;
};

enum Shape
{
	CIRCLE,
	RECTANGLE,
	TRIANGLE,
	ERROR
};

struct Circle
{
	Point centerCircle;
	int radius;
	std::string type = CIRCLE_TYPE;
};

struct Rectangle
{
	Point leftTopCorner;
	int width;
	int	height;
	std::string type = RECTANGLE_TYPE;
};

struct Triangle
{
	Point firstPoint;
	Point secondPoint;
	Point thirdPoint;
	std::string type = TRIANGLE_TYPE;
};

