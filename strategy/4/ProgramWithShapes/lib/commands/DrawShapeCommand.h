#pragma once
#include"ICommand.h"
#include <string>
#include "../shapes/CPicture.h"

namespace command
{
    class DrawShapeCommand : public ICommand 
    {
    public:
        DrawShapeCommand(shapes::CPicture& picture,
            const std::string& id,
            gfx::ICanvas& canvas)
            : m_picture(picture), m_id(id), m_canvas(canvas) {}

        void Execute() override 
        {
            auto shape = m_picture.GetShape(m_id);
            if (shape) 
            {
                shape->DrawShape(m_canvas);
            }
        }

    private:
        shapes::CPicture& m_picture;
        std::string m_id;
        gfx::ICanvas& m_canvas;
    };

}