#include "CPicture.h"
#include "../tools/Constants.h"
#include "../tools/Parser.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
#include <string>

void CPicture::AddShape(std::unique_ptr<IShape> shape)
{
	m_shapes.push_back(std::move(shape));
}

void CPicture::DrawPicture(ICanvas& canvas)
{
	for (auto& shape : m_shapes)
	{
		shape->DrawShape(canvas);
	}
}

void CPicture::LoadFromFile(const std::string& filename)
{
    std::ifstream fin(filename);
    if (!fin.is_open()) 
    {
        std::cout << ERROR_OPENING_FILE << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(fin, line)) 
    {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string typeStr;
        ss >> typeStr;
		Parser parser;
        Shape enumType = parser.StrTypeInEnum(typeStr);

        switch (enumType)
        {
        case CIRCLE:
        {
            Point centerCircle{0, 0};
            int radius = 0;
            std::string type = CIRCLE_TYPE;

            parser.ParserCircle(line, centerCircle, radius);
            AddShape(std::make_unique<CircleAdapter>(centerCircle, radius, type));
            break;
        }
        case RECTANGLE:
        {
            Point leftTop{0,0};
            int width = 0;
            int height = 0;
            std::string type = RECTANGLE_TYPE;

            parser.ParserRectangle(line, leftTop, width, height);
            AddShape(std::make_unique<RectangleAdapter>(leftTop, width, height, type));
            break;
        }
        case TRIANGLE:
        {
            Point p1{0,0}, p2{0,0}, p3{0,0};
            std::string type = TRIANGLE_TYPE;

            parser.ParserTriangle(line, p1, p2, p3);
            AddShape(std::make_unique<TriangleAdapter>(p1, p2, p3, type));
            break;
        }
        default:
            break;
        }
    }

    fin.close();
}

void CPicture::OutCharacteristics()
{
    std::ofstream fout(OUTPUT_FILE);
    if (!fout.is_open())
    {
        std::cerr << OUTPUT_FILE_ERROR << std::endl;
        return;
    }

    for (auto& shape : m_shapes)
    {
        fout << shape->GetType() << PERIMETER_LABEL << shape->Perimeter() << AREA_LABEL << shape->Area() << NEWLINE;
    }

    std::cout << RESULTS_WRITTEN;
}
