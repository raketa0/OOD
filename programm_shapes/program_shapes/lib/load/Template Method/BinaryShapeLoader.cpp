#include "BinaryShapeLoader.h"
#include <stdexcept>

const std::string CANNOT_OPEN_BINARY_FILE = "Cannot open binary file: ";
const char NULL_CHAR = '\0';

void BinaryShapeLoader::OpenFile(std::string& filename)
{
    m_file.open(filename, std::ios::binary);
    if (!m_file.is_open())
        throw std::runtime_error(CANNOT_OPEN_BINARY_FILE + filename);

    m_file.read(reinterpret_cast<char*>(&m_shapesCount), sizeof(m_shapesCount));
    m_readCount = 0;
}

bool BinaryShapeLoader::HasNextShape()
{
    return m_readCount < m_shapesCount;
}

std::string BinaryShapeLoader::ReadNextShapeText()
{
    int id;
    size_t length;

    m_file.read(reinterpret_cast<char*>(&id), sizeof(id));
    m_file.read(reinterpret_cast<char*>(&length), sizeof(length));

    std::string text(length, NULL_CHAR);
    m_file.read(text.data(), length);

    ++m_readCount;
    return text;
}

void BinaryShapeLoader::CloseFile()
{
    m_file.close();
}
