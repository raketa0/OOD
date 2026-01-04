#include "TextSaveStrategy.h"
#include <fstream>

TextSaveStrategy::TextSaveStrategy(std::map<int, std::shared_ptr<IShape>>& shapes)
	: m_shapes(shapes){}

const char NEWLINES = '\n';

void TextSaveStrategy::Save(std::string& filename)
{
	std::ofstream outFile(filename);

	for (const auto& [id, shape] : m_shapes)
	{
		outFile << id << " "
			<< shape->GetCharacteristics()
			<< NEWLINES;
	}

	outFile.close();
}
