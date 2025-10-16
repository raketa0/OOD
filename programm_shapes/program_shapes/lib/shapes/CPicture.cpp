#include "CPicture.h"
#include "CircleAdapter.h"
#include "RectangleAdapter.h"
#include "TriangleAdapter.h"
#include <fstream>
#include <iostream>
#include <string>
#include <memory>

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
    if (!fin.is_open()) {
        std::cerr << "Не удалось открыть файл " << filename << std::endl;
        return;
    }

    std::string type;
    while (fin >> type) {
        if (type == "CIRCLE:") {
            char c_eq, r_eq, comma, semicolon;
            int cx, cy, r;
            fin >> c_eq >> cx >> comma >> cy >> semicolon >> r_eq >> r;
            AddShape(std::make_unique<CircleAdapter>(cx, cy, r));
        }
        else if (type == "RECTANGLE:") {
            char p1_eq, p2_eq, comma1, comma2, semicolon1, semicolon2;
            int x1, y1, x2, y2;
            fin >> p1_eq >> x1 >> comma1 >> y1 >> semicolon1
                >> p2_eq >> x2 >> comma2 >> y2 >> semicolon2;
            AddShape(std::make_unique<RectangleAdapter>(x1, y1, x2, y2));
        }
        else if (type == "TRIANGLE:") {
            char p1_eq, p2_eq, p3_eq;
            char comma1, comma2, comma3;
            char semicolon1, semicolon2;
            int x1, y1, x2, y2, x3, y3;
            fin >> p1_eq >> x1 >> comma1 >> y1 >> semicolon1
                >> p2_eq >> x2 >> comma2 >> y2 >> semicolon2
                >> p3_eq >> x3 >> comma3 >> y3;
            AddShape(std::make_unique<TriangleAdapter>(x1, y1, x2, y2, x3, y3));
        }
    }
}

void CPicture::OutCharacteristics()
{
    std::ofstream fout("output.txt");
    if (!fout.is_open()) {
        std::cerr << "Ошибка открытия output.txt" << std::endl;
        return;
    }

    for (auto& shape : m_shapes)
    {
        fout << ": P=" << (int)shape->Perimeter() << "; S=" << (int)shape->Area() << "\n";
    }

    std::cout << "Результаты записаны в output.txt\n";
}
