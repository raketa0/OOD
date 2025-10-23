#pragma once
#include <string>
#include <sstream>
#include "ShapesStruct.h"

class Parser
{
public:
     Shape StrTypeInEnum(const std::string& type);
     void ParserCircle(const std::string& line, Point& centerCircle, int& radius);
     void ParserRectangle(const std::string& line, Point& leftTopCorner, int& width, int& height);
     void ParserTriangle(const std::string& line, Point& firstPoint, Point& secondPoint, Point& thirdPoint);
};

