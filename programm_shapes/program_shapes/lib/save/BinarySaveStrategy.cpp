#include "BinarySaveStrategy.h"
#include <fstream>

BinarySaveStrategy::BinarySaveStrategy(std::map<int, std::shared_ptr<IShape>>& shapes)
	: m_shapes(shapes){}

void BinarySaveStrategy::Save(std::string& filename)
{
	std::ofstream outFile(filename, std::ios::binary);

	size_t length = m_shapes.size();
	outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));

	for (auto& [id, shape] : m_shapes)
	{
		outFile.write(reinterpret_cast<const char*>(&id), sizeof(id));

		std::string data = shape->GetCharacteristics();
		length = data.size();

		outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));
		outFile.write(data.c_str(), length);
	}

	outFile.close();
}
