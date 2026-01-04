#pragma once

#include <string>
#include <memory>
#include "../../shapes/CÑompositionShapes.h"



class IShapeLoaderTemplate
{
public:
    void BuildFromText(std::string text, std::shared_ptr<CÑompositionShapes> composition);

   virtual void Load(std::string& filename,
        std::shared_ptr<CÑompositionShapes> composition);

protected:
    virtual void OpenFile(std::string& filename) = 0;
    virtual bool HasNextShape() = 0;
    virtual std::string ReadNextShapeText() = 0;
    virtual void CloseFile() = 0;

};