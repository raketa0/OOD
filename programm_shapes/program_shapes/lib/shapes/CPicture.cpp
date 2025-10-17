#include "CPicture.h"
#include "CircleAdapter.h"
#include "RectangleAdapter.h"
#include "TriangleAdapter.h"
#include <fstream>
#include <iostream>
#include <string>
#include <memory>
#include <sstream>
#include "../tools/Parser.cpp"
#include "../tools/ShapesStruct.h"


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
        std::cout << "Не удалось открыть " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(fin, line)) 
    {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string type;
        ss >> type;

        Shape enumType = StrTypeInEnum(type);

        switch (enumType)
        {
        case CIRCLE:
        {
            auto circle = ParserCircle(line);
            AddShape(std::make_unique<CircleAdapter>(circle));
            break;
        }
        case RECTANGLE:
        {
            auto rectange = ParserRectangle(line);
            AddShape(std::make_unique<RectangleAdapter>(rectange));
            break;
        }
        case TRIANGLE:
        {
            auto triangle = ParserTriangle(line);
            AddShape(std::make_unique<TriangleAdapter>(triangle));
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
    std::ofstream fout("output.txt");
    if (!fout.is_open())
    {
        std::cerr << "Ошибка открытия output.txt" << std::endl;
        return;
    }

    for (auto& shape : m_shapes)
    {
        fout << ": P=" << (int)shape->Perimeter() << "; S=" << (int)shape->Area() << "\n";
    }

    std::cout << "Результаты записаны в output.txt\n";
}
