#include "CShapeSelector.h"
#include "../tools/Parser.h"

//sf::Mouse::getPosition(window)


CShapeSelector::CShapeSelector(std::shared_ptr<CÑompositionShapes> composition)
	: m_composition(composition), m_selectedShape(nullptr){}

void CShapeSelector::OnClick(const sf::Vector2i& mousePos)
{
}

void CShapeSelector::DrawSelection(sf::RenderWindow& window)
{
}

bool CShapeSelector::IsClickInsideShape(const sf::Vector2i& mousePos)
{
	Parser parser;
	for (auto& [id, shape] : m_composition->GetÑompositionShapes())
	{
		Shape type = parser.StrTypeInEnum(shape->GetType());
		auto sh = m_composition->FindShapeById(id);
			switch (type)
			{
				case CIRCLE:
					CircleAdapter 
					double dx = mousePos.x - sh->GetCenterCircle;
					break;
				case RECTANGLE:
					break;
				case TRIANGLE:
					break;
			default:
				break;
			}
	}
	
}
