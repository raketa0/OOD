#include "Parser.h"
#include "Constants.h"



Shape StrTypeInEnum(std::string type)
{
    if (type == CIRCLE_TYPE)
    {
        return CIRCLE;
    }
    else if (type == RECTANGLE_TYPE)
    {
        return RECTANGLE;
    }
    else if (type == TRIANGLE_TYPE)
    {
        return TRIANGLE;
    }
    else
    {
        return ERROR;
    }
}

Circle ParserCircle(std::string line)
{
    Circle circle;
    char ch;
    char chSecond;

    std::stringstream ss(line);
    while (ss >> ch)
    {
        if (ch == C_PREFIX)
        {
            ss >> ch;
            if (ch == EQUAL_SIGN)
            {
                ss >> circle.centerCircle.x;
            }
        }
        if (ch == COMMA_CHAR)
        {
            ss >> circle.centerCircle.y;
        }
        if (ch == RADIUS_PREFIX)
        {
            ss >> ch;
            if (ch == EQUAL_SIGN)
            {
                ss >> circle.radius;
            }
        }
    }
    return circle;
}

Rectangle ParserRectangle(std::string line)
{
    Rectangle rectangle;
    char ch;
    int countFirst = ZERO;
    int countSecond = ZERO;
    int x1 = ZERO, y1 = ZERO, x2 = ZERO, y2 = ZERO;
    std::stringstream ss(line);

    while (ss >> ch)
    {
        if (ch == EQUAL_SIGN)
        {
            if (countFirst == FIRST_COORD_COUNT)
            {
                ss >> x1;
            }
            else if (countFirst == SECOND_COORD_COUNT)
            {
                ss >> x2;
            }
            countFirst++;
        }
        else if (ch == COMMA_CHAR)
        {
            if (countSecond == FIRST_COORD_COUNT)
            {
                ss >> y1;
            }
            else if (countSecond == SECOND_COORD_COUNT)
            {
                ss >> y2;
            }
            countSecond++;
        }
    }
    rectangle.leftTopCorner.x = std::min(x1, x2);
    rectangle.leftTopCorner.y = std::min(y1, y2);
    rectangle.width = std::abs(x2 - x1);
    rectangle.height = std::abs(y2 - y1);

    return rectangle;
}

Triangle ParserTriangle(std::string line)
{
    Triangle triangle;
    char ch;
    std::stringstream ss(line);

    int nums[TOTAL_COORDS] = { ZERO };
    int i = ZERO;

    while (ss >> ch)
    {
        if (ch == EQUAL_SIGN)
        {
            ss >> nums[i++];
        }
        if (ch == COMMA_CHAR)
        {
            ss >> nums[i++];
        }
    }

    triangle.firstPoint.x = nums[FIRST_X_INDEX];
    triangle.firstPoint.y = nums[FIRST_Y_INDEX];
    triangle.secondPoint.x = nums[SECOND_X_INDEX];
    triangle.secondPoint.y = nums[SECOND_Y_INDEX];
    triangle.thirdPoint.x = nums[THIRD_X_INDEX];
    triangle.thirdPoint.y = nums[THIRD_Y_INDEX];

    return triangle;
}