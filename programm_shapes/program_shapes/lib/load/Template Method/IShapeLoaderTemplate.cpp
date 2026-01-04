#include "IShapeLoaderTemplate.h"
#include "../Builder/GroupShapeBuilder.h"
#include "../Builder/RectangleBuilder.h"
#include "../Builder/CircleBuilder.h"
#include "../Builder/TriangleBuilder.h"
#include <vector>
#include <memory>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <charconv>
#include <SFML/Graphics.hpp>

const std::string GROUP_KEY = "Group Characteristics";
const std::string RECTANGLE_KEY = "Rectangle:";
const std::string CIRCLE_KEY = "Circle:";
const std::string TRIANGLE_KEY = "Triangle:";
const std::string FIRST_POINT_KEY = "First Point";
const std::string SECOND_POINT_KEY = "Second Point";
const std::string THIRD_POINT_KEY = "Third Point";
const std::string LEFT_TOP_CORNER_KEY = "Left Top Corner";
const std::string CENTER_KEY = "Center";
const std::string WIDTH_KEY = "Width:";
const std::string HEIGHT_KEY = "Height:";
const std::string RADIUS_KEY = "Radius:";
const std::string FILL_COLOR_KEY = "Fill Color:";
const std::string OUTLINE_COLOR_KEY = "Outline Color:";
const std::string OUTLINE_THICKNESS_KEY = "Outline Thickness:";

const char OPEN_PAREN = '(';
const char CLOSE_PAREN = ')';
const char COMMA = ',';
const char DOT = '.';
const char COMMA_IN_FLOAT = ',';
const char PLUS = '+';
const char MINUS = '-';
const char NULL_CHAR = '\0';

int ExtractInt(const std::string& text, const std::string& key)
{
    auto pos = text.find(key);
    if (pos == std::string::npos) return 0;
    pos += key.length();

    while (pos < text.size() && std::isspace((unsigned char)text[pos])) ++pos;
    if (pos >= text.size()) return 0;

    size_t start = pos;
    if (text[start] == PLUS || text[start] == MINUS) ++start;
    if (start >= text.size() || !std::isdigit((unsigned char)text[start])) return 0;

    size_t end = start;
    while (end < text.size() && std::isdigit((unsigned char)text[end])) ++end;

    int value = 0;
    auto first = text.data() + pos;
    auto last = text.data() + end;
    auto res = std::from_chars(first, last, value);
    if (res.ec != std::errc()) return 0;
    return value;
}

float ExtractFloat(const std::string& text, const std::string& key)
{
    auto pos = text.find(key);
    if (pos == std::string::npos) return 0.f;
    pos += key.length();

    while (pos < text.size() && std::isspace((unsigned char)text[pos])) ++pos;
    if (pos >= text.size()) return 0.f;

    size_t end = pos;
    while (end < text.size() &&
        (std::isdigit((unsigned char)text[end]) ||
            text[end] == DOT ||
            text[end] == COMMA_IN_FLOAT ||
            text[end] == PLUS ||
            text[end] == MINUS))
    {
        ++end;
    }

    std::string tmp(text.data() + pos, end - pos);
    std::replace(tmp.begin(), tmp.end(), COMMA_IN_FLOAT, DOT);

    float value = 0.f;
    auto r = std::from_chars(tmp.data(), tmp.data() + tmp.size(), value);
    if (r.ec != std::errc()) return 0.f;
    return value;
}

Point ExtractPoint(const std::string& text, size_t fromPos)
{
    size_t open = text.find(OPEN_PAREN, fromPos);
    size_t comma = (open == std::string::npos) ? std::string::npos : text.find(COMMA, open);
    size_t close = (comma == std::string::npos) ? std::string::npos : text.find(CLOSE_PAREN, comma);
    if (open == std::string::npos || comma == std::string::npos || close == std::string::npos) 
        return { 0, 0 };

    int x = ExtractInt(text.substr(open + 1, comma - open - 1), "");
    int y = ExtractInt(text.substr(comma + 1, close - comma - 1), "");
    return { x, y };
}

sf::Color ExtractColor(const std::string& text, const std::string& key)
{
    auto pos = text.find(key);
    if (pos == std::string::npos) return sf::Color::White;
    pos += key.length();

    size_t end = text.find_first_of(",)", pos);
    std::string tmp = text.substr(pos, end - pos);
    try {
        uint32_t colorInt = static_cast<uint32_t>(std::stoul(tmp));
        return sf::Color(colorInt);
    }
    catch (...) {
        return sf::Color::White;
    }
}

void IShapeLoaderTemplate::BuildFromText(std::string text, std::shared_ptr<CÑompositionShapes> composition)
{
    std::istringstream stream(text);
    std::string line;

    std::shared_ptr<GroupShapeBuilder> groupBuilder = nullptr;
    int nextShapeId = 0;

    while (std::getline(stream, line))
    {
        if (line.empty()) continue;

        if (line.find(GROUP_KEY) != std::string::npos)
        {
            if (groupBuilder)
                groupBuilder->AddShapeInComposition(composition);

            groupBuilder = std::make_shared<GroupShapeBuilder>(composition->GetCanvas());
            nextShapeId = 0;
            continue;
        }

        std::shared_ptr<IShapeBuilder> builder;

        if (line.find(RECTANGLE_KEY) != std::string::npos)
        {
            Point topLeft = ExtractPoint(line, line.find(LEFT_TOP_CORNER_KEY));
            std::vector<Point> points = { topLeft };
            int width = ExtractInt(line, WIDTH_KEY);
            int height = ExtractInt(line, HEIGHT_KEY);
            sf::Color fill = ExtractColor(line, FILL_COLOR_KEY);
            sf::Color outline = ExtractColor(line, OUTLINE_COLOR_KEY);
            float thickness = ExtractFloat(line, OUTLINE_THICKNESS_KEY);

            auto rectBuilder = std::make_shared<RectangleBuilder>(composition->GetCanvas());
            rectBuilder->SetPoints(points);
            rectBuilder->SetDimensions(width, height);
            rectBuilder->SetColors(fill, outline);
            rectBuilder->SetOutlineThickness(thickness);

            builder = rectBuilder;
        }
        else if (line.find(CIRCLE_KEY) != std::string::npos)
        {
            Point center = ExtractPoint(line, line.find(CENTER_KEY));
            std::vector<Point> points = { center };
            int radius = ExtractInt(line, RADIUS_KEY);
            sf::Color fill = ExtractColor(line, FILL_COLOR_KEY);
            sf::Color outline = ExtractColor(line, OUTLINE_COLOR_KEY);
            float thickness = ExtractFloat(line, OUTLINE_THICKNESS_KEY);

            auto circleBuilder = std::make_shared<CircleBuilder>(composition->GetCanvas());
            circleBuilder->SetPoints(points);
            circleBuilder->SetRadius(radius);
            circleBuilder->SetColors(fill, outline);
            circleBuilder->SetOutlineThickness(thickness);

            builder = circleBuilder;
        }
        else if (line.find(TRIANGLE_KEY) != std::string::npos)
        {
            Point pointOne = ExtractPoint(line, line.find(FIRST_POINT_KEY));
            Point pointTwo = ExtractPoint(line, line.find(SECOND_POINT_KEY));
            Point pointThree = ExtractPoint(line, line.find(THIRD_POINT_KEY));
            std::vector<Point> points = { pointOne, pointTwo, pointThree };

            sf::Color fill = ExtractColor(line, FILL_COLOR_KEY);
            sf::Color outline = ExtractColor(line, OUTLINE_COLOR_KEY);
            float thickness = ExtractFloat(line, OUTLINE_THICKNESS_KEY);

            auto triBuilder = std::make_shared<TriangleBuilder>(composition->GetCanvas());
            triBuilder->SetPoints(points);
            triBuilder->SetColors(fill, outline);
            triBuilder->SetOutlineThickness(thickness);

            builder = triBuilder;
        }

        if (builder)
        {
            auto shape = builder->CreateShape();

            if (groupBuilder)
                groupBuilder->AddShapeToGroup(nextShapeId++, shape);
            else
                composition->AddShape(shape);
        }
    }

    if (groupBuilder)
        groupBuilder->AddShapeInComposition(composition);
}

void IShapeLoaderTemplate::Load(std::string& filename, std::shared_ptr<CÑompositionShapes> composition)
{
    OpenFile(filename);

    while (HasNextShape())
    {
        std::string text = ReadNextShapeText();
        BuildFromText(text, composition);
    }

    CloseFile();
}
