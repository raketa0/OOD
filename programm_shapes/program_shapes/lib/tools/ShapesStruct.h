
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
};

struct Rectangle
{
	Point leftTopCorner;
	int width;
	int	height;
};

struct Triangle
{
	Point firstPoint;
	Point secondPoint;
	Point thirdPoint;
};

