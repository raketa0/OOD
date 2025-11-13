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


class CPicture
{
public:
	CPicture(std::shared_ptr<ICanvasSFML> canvas);
	void AddShape(std::unique_ptr<IShape> shape);
	void DrawPicture();
	void LoadFromFile(const std::string& filename);
	void OutCharacteristics();
private:
	std::vector<std::unique_ptr<IShape>> m_shapes;
	std::shared_ptr<ICanvasSFML> m_canvas;
};
