#pragma once
#include "IShapeBuilder.h"
#include "../../shapes/CGroupShape.h"
#include "../../canvas/ICanvasSFML.h"
#include <memory>
#include <map>

class GroupShapeBuilder : public IShapeBuilder 
{
public:
	GroupShapeBuilder(std::shared_ptr<ICanvasSFML> canvas);
	void SetType(std::string& type) override;
	void AddShapeInComposition(std::shared_ptr<CÑompositionShapes> composition) override;
	void AddShapeToGroup(int id, std::shared_ptr<IShape> shape) override;
	std::shared_ptr<IShape> CreateShape() override;
private:
	std::map<int, std::shared_ptr<IShape>> m_groupedShapes;
	std::string m_type;
	std::shared_ptr<ICanvasSFML> m_canvas;
};
