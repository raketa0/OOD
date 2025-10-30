#pragma once
#include <memory>
#include <vector>
#include "IShape.h"
#include <string>
#include "CircleAdapter.h"
#include "RectangleAdapter.h"
#include "TriangleAdapter.h"
#include <fstream>
#include <iostream>

#include <sstream>
#include "../tools/Parser.h"
#include "../tools/ShapesStruct.h"


class CÑompositionShapes : public IShape
{
public:
	CÑompositionShapes(std::shared_ptr<ICanvasSFML> canvas);

	double Perimeter() override;
	double Area() override;
	std::string GetType() override;
	void Draw() override;

	void AddShape(std::unique_ptr<IShape> shape);
	void LoadFromFile(const std::string& filename);
	void OutCharacteristics();
private:
	std::vector<std::unique_ptr<IShape>> m_shapes;
	std::shared_ptr<ICanvasSFML> m_canvas;
};
