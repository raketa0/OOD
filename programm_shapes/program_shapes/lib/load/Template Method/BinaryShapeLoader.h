#pragma once
#include "IShapeLoaderTemplate.h"
#include <fstream>
#include <memory>
#include "../../canvas/ICanvasSFML.h"
#include "../../shapes/CÑompositionShapes.h"
const size_t ZERO_SIZE_T = 0;
const size_t ZERO_SIZE_T_TWO = 0;


class BinaryShapeLoader : public IShapeLoaderTemplate
{
public:
	BinaryShapeLoader() = default;

protected:
    void OpenFile(std::string& filename) override;
    bool HasNextShape() override;
    std::string ReadNextShapeText() override;
    void CloseFile() override;

private:
    std::ifstream m_file;
    size_t m_shapesCount = ZERO_SIZE_T;
    size_t m_readCount = ZERO_SIZE_T_TWO;
};