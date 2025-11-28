#include "C—ompositionShapes.h"
#include "../tools/Constants.h"
#include "../tools/Parser.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <cassert>

C—ompositionShapes::C—ompositionShapes(std::shared_ptr<ICanvasSFML> canvas, int curentShapeId) 
    : m_canvas(std::move(canvas)),
	m_curentShapeId(curentShapeId)
{
    assert(m_canvas);
}

void C—ompositionShapes::AddShape(std::shared_ptr<IShape> shape)
{
    int id = ++m_curentShapeId;
    m_shapes[id] = std::move(shape);
}

void C—ompositionShapes::RemoveShapeById(int id)
{
	m_shapes.erase(id);
}

void C—ompositionShapes::Draw()
{
    for (auto& [id, shape] : m_shapes)
    {
        shape->Draw();
    }
}

void C—ompositionShapes::LoadFromFile(const std::string& filename)
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
            Point centerCircle{ ZERO, ZERO };
            int radius = ZERO;
            std::string type = CIRCLE_TYPE;

            parser.ParserCircle(line, centerCircle, radius);
            AddShape(std::make_shared<CircleAdapter>(centerCircle, radius, type, m_canvas));
            break;
        }
        case RECTANGLE:
        {
            Point leftTop{ ZERO, ZERO };
            int width = ZERO;
            int height = ZERO;
            std::string type = RECTANGLE_TYPE;

            parser.ParserRectangle(line, leftTop, width, height);
            AddShape(std::make_shared<RectangleAdapter>(leftTop, width, height, type, m_canvas));
            break;
        }
        case TRIANGLE:
        {
            Point p1{ ZERO, ZERO }, p2{ ZERO, ZERO }, p3{ ZERO, ZERO };
            std::string type = TRIANGLE_TYPE;

            parser.ParserTriangle(line, p1, p2, p3);
            AddShape(std::make_shared<TriangleAdapter>(p1, p2, p3, type, m_canvas));
            break;
        }
        default:
            break;
        }
    }

    fin.close();
}

void C—ompositionShapes::OutCharacteristics()
{
    std::ofstream fout(OUTPUT_FILE);
    if (!fout.is_open())
    {
        std::cerr << OUTPUT_FILE_ERROR << std::endl;
        return;
    }

    for (auto& [id, shape] : m_shapes)
    {
        fout << id << SPACE_CHAR << shape->GetType() << PERIMETER_LABEL << shape->Perimeter() << AREA_LABEL << shape->Area() << NEWLINE;
    }

    std::cout << RESULTS_WRITTEN;
}

std::map<int, std::shared_ptr<IShape>> C—ompositionShapes::Get—ompositionShapes()
{
    return m_shapes;
}

std::shared_ptr<IShape> C—ompositionShapes::FindShapeById(int id)
{
    for (auto& pair : m_shapes)
    {
        if (pair.first == id)
        {
            return pair.second;
        }
    }
    return nullptr;
}

std::map<int, std::shared_ptr<IShape>> C—ompositionShapes::GetSelectedShapes()
{
	std::map<int, std::shared_ptr<IShape>> selectedShapes;
    for (auto& [id, shape] : m_shapes)
    {
        if (shape->IsSelected())
        {
            selectedShapes[id] = shape;
        }
    }
	return selectedShapes;
}

void C—ompositionShapes::ChangeFillColor(const sf::Color& color)
{
    for (auto& [id, shape] : m_shapes)
    {
        if (shape->IsSelected())
        {
            shape->ChangeFillColor(color);
        }
	}
}

void C—ompositionShapes::ChangeOutlineColor(const sf::Color& color)
{
    for (auto& [id, shape] : m_shapes)
    {
        if (shape->IsSelected())
        {
            shape->ChangeOutlineColor(color);
        }
	}
}

void C—ompositionShapes::ChangeOutlineThickness(float thickness)
{
    for (auto& [id, shape] : m_shapes)
    {
        if (shape->IsSelected())
        {
            shape->ChangeOutlineThickness(thickness);
        }
	}
}
