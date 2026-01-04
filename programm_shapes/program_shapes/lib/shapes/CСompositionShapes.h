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
#include "../visitor/IShapeVisitor.h"


class C—ompositionShapes : public IShape
{
public:
	C—ompositionShapes(std::shared_ptr<ICanvasSFML> canvas, int curentShapeId = ZERO);

	void Draw() override;
	void CloseAllShapes();
	void AddShape(std::shared_ptr<IShape> shape);
	void RemoveShapeById(int id);

	void LoadFromFile(const std::string& filename);
	void OutCharacteristics();
	std::map<int, std::shared_ptr<IShape>> Get—ompositionShapes();
	std::shared_ptr<IShape> FindShapeById(int id);
	std::map<int, std::shared_ptr<IShape>> GetSelectedShapes();
	void ChangeFillColor(const sf::Color& color);
	void ChangeOutlineColor(const sf::Color& color);
	void ChangeOutlineThickness(float thickness);
	std::string GetCharacteristics() override;
	void ApplyFill(sf::Vector2i pos);
	void ApplyOutlineColor(sf::Vector2i pos);
	void ApplyOutlineThickness(sf::Vector2i pos);
	sf::Color GetFillColor() const { return m_fillColor; }
	sf::Color GetOutlineColor() const { return m_outlineColor; }
	float GetOutlineThickness() const { return m_outlineThickness; }
	std::shared_ptr<IMementoShapes> CreateMement();
	void SetCompositionShapes(std::map<int, std::shared_ptr<IShape>>& shapes);
	void ApplyVisitor(IShapeVisitor& visitor);
	void ApplyVisitorToClickedShape(const sf::Vector2i& pos, IShapeVisitor& visitor);
	std::shared_ptr<ICanvasSFML> GetCanvas() { return m_canvas; }
private:
	std::map<int, std::shared_ptr<IShape>> m_shapes;
	std::shared_ptr<ICanvasSFML> m_canvas;
	int m_curentShapeId;
	sf::Color m_fillColor = sf::Color::Red;
	sf::Color m_outlineColor = sf::Color::Black;
	float m_outlineThickness = 2.f;
};
