#pragma once
#include "ISaveStrategy.h"
#include <map>
#include <memory>
#include "../shapes/IShape.h"

class TextSaveStrategy : public ISaveStrategy
{
public:
	TextSaveStrategy(std::map<int, std::shared_ptr<IShape>>& shapes);
	void Save(std::string& filename) override;

private:
	std::map<int, std::shared_ptr<IShape>>& m_shapes;
};
