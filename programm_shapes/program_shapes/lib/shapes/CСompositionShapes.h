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
#include <map>

//ïåğåèìåíîâàòü

class CÑompositionShapes : public IShape
{
public:
	CÑompositionShapes(std::shared_ptr<ICanvasSFML> canvas, int curentShapeId = 0);

	void Draw() override;

	void AddShape(std::shared_ptr<IShape> shape);
	void RemoveShapeById(int id);

	void LoadFromFile(const std::string& filename);
	void OutCharacteristics();
	std::map<int, std::shared_ptr<IShape>> GetÑompositionShapes();
	std::shared_ptr<IShape> FindShapeById(int id);
	std::map<int, std::shared_ptr<IShape>> GetSelectedShapes();
private:
	std::map<int, std::shared_ptr<IShape>> m_shapes;
	std::shared_ptr<ICanvasSFML> m_canvas;
	int m_curentShapeId;
};
