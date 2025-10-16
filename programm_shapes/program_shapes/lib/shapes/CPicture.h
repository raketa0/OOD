#pragma once
#include <memory>
#include <vector>
#include "IShape.h"
#include <string>



class CPicture
{
public:
	void AddShape(std::unique_ptr<IShape> shape);
	void DrawPicture(ICanvas& canvas);
	void LoadFromFile(const std::string& filename);
	void OutCharacteristics();
private:
	std::vector<std::unique_ptr<IShape>> m_shapes;
};
