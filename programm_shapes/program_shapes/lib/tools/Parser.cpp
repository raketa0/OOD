#include "Parser.h"



Shape StrTypeInEnum(std::string type)
{
    if (type == "CIRCLE:")
    {
        return CIRCLE;
    }
    else if (type == "RECTANGLE:")
    {
        return RECTANGLE;
    }
    else if (type == "TRIANGLE:")
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
    std::stringstream ss(line);
    while (ss >> ch)
    {
        if (ch == '=') 
        { 
            ss >> circle.centerCircle.x;
        }
        if (ch == ',') 
        { 
            ss >> circle.centerCircle.y;
        }
        if (ch == 'R')
        {
            ss.ignore(1);
            ss >> circle.radius;
        }
    }
    return circle;
}

Rectangle ParserRectangle(std::string line)
{
    Rectangle rectangle;
    char ch;
    int countFirst = 0;
    int countSecond = 0;
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    std::stringstream ss(line);
    
    while (ss >> ch) 
    {
        if (ch == '=') 
        {
            if (countFirst == 0)
            {
                ss >> x1;
            }
            else if (countFirst == 1)
            {
                ss >> x2;
            }
            countFirst++;
        }
        else if (ch == ',')
        {
            if (countSecond == 0)
            {
                ss >> y1;
            }
            else if (countSecond == 1)
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

    int nums[6] = { 0 };
    int i = 0;

    while (ss >> ch) 
    {
        if (ch == '=')
        {
            ss >> nums[i++];
        }
        if (ch == ',') 
        { 
            ss >> nums[i++]; 
        }
    }

    triangle.firstPoint.x = nums[0]; 
    triangle.firstPoint.y = nums[1];
    triangle.secondPoint.x = nums[2];
    triangle.secondPoint.y = nums[3];
    triangle.thirdPoint.x = nums[4];
    triangle.thirdPoint.y = nums[5];

    return triangle;
}