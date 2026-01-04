#pragma once
#include "IShapeLoaderTemplate.h"

class TextShapeLoader : public IShapeLoaderTemplate
{
public:
	TextShapeLoader() = default;
protected:
    void OpenFile(std::string& filename) override;
    bool HasNextShape() override;
    std::string ReadNextShapeText() override;
    void CloseFile() override;

private:
    std::ifstream m_file;
    std::string m_nextBlock;
};