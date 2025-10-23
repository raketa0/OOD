#include "Parser.h"
#include "Constants.h"

Shape Parser::StrTypeInEnum(const std::string& type)
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

void Parser::ParserCircle(const std::string& line, Point& centerCircle, int& radius)
{
    char ch;
    std::stringstream ss(line);
    while (ss >> ch)
    {
        if (ch == C_PREFIX)
        {
            ss >> ch;
            if (ch == EQUAL_SIGN)
            {
                ss >> centerCircle.x;
            }
        }
        if (ch == COMMA_CHAR)
        {
            ss >> centerCircle.y;
        }
        if (ch == RADIUS_PREFIX)
        {
            ss >> ch;
            if (ch == EQUAL_SIGN)
            {
                ss >> radius;
            }
        }
    }
}

void Parser::ParserRectangle(const std::string& line, Point& leftTopCorner, int& width, int& height)
{
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
    leftTopCorner.x = std::min(x1, x2);
    leftTopCorner.y = std::min(y1, y2);
    width = std::abs(x2 - x1);
    height = std::abs(y2 - y1);
}

void Parser::ParserTriangle(const std::string& line, Point& firstPoint, Point& secondPoint, Point& thirdPoint)
{
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

    firstPoint.x = nums[FIRST_X_INDEX];
    firstPoint.y = nums[FIRST_Y_INDEX];
    secondPoint.x = nums[SECOND_X_INDEX];
    secondPoint.y = nums[SECOND_Y_INDEX];
    thirdPoint.x = nums[THIRD_X_INDEX];
    thirdPoint.y = nums[THIRD_Y_INDEX];
}