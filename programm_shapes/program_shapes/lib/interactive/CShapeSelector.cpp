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

bool CShapeSelector::IsClickInsideShape(const sf::Vector2i& mousePos, std::shared_ptr<IShape> shape)
{
	Parser parser;
	Shape type = parser.StrTypeInEnum(shape->GetType());
	switch (type)
	{
		case CIRCLE:
			break;
		case RECTANGLE:
			break;
		case TRIANGLE:
			break;
	default:
		break;
	}
}
