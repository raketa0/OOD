#pragma once
#include <string>
#include <sstream>
#include "ShapesStruct.h"

Shape StrTypeInEnum(std::string type);
Circle ParserCircle(std::string line);
Rectangle ParserRectangle(std::string line);
Triangle ParserTriangle(std::string line);

