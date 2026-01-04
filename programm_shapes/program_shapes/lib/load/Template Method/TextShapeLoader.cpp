#include "TextShapeLoader.h"
#include <stdexcept>

const std::string kCannotOpenFileError = "Cannot open text file: ";
const std::string kGroupKey = "Group Characteristics";
const char kNewLine = '\n';

void TextShapeLoader::OpenFile(std::string& filename)
{
    m_file.open(filename);
    if (!m_file.is_open())
        throw std::runtime_error(kCannotOpenFileError + filename);

    m_nextBlock.clear();
}

bool TextShapeLoader::HasNextShape()
{
    return static_cast<bool>(std::getline(m_file, m_nextBlock));
}

std::string TextShapeLoader::ReadNextShapeText()
{
    std::string block = m_nextBlock;

    if (block.find(kGroupKey) != std::string::npos)
    {
        std::string line;
        while (std::getline(m_file, line))
        {
            if (line.empty() || m_file.eof())
                break;
            block += kNewLine + line;
        }
    }

    return block;
}

void TextShapeLoader::CloseFile()
{
    m_file.close();
}
