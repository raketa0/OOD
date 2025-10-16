#pragma once
#include <memory>
#include "CShape.h"
#include "../gfx/ICanvas.h"
#include <vector>

namespace shapes
{
	class CPicture
	{
	public:
		void AddShape(std::shared_ptr<CShape>& shape);
		void DeleteShape(std::string id);
		void MovePicture(double dx, double dy);
		void DrawPicture(gfx::ICanvas& canvas);
		std::shared_ptr<CShape> GetShape(std::string id);
		void List();
		virtual ~CPicture() = default;

	private:
		std::vector<std::shared_ptr<CShape>> m_shapes;
	};

}
