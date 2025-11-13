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

struct FrameParameters
{
	Point topLeftCorner;
	int width;
	int height;
};

