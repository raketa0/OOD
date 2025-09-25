#pragma once

#include"ICommand.h"
#include <string>
#include "../shapes/CPicture.h"

namespace command
{
    class DrawPictureCommand : public ICommand 
    {
    public:
        DrawPictureCommand(shapes::CPicture& picture,
            gfx::ICanvas& canvas)
            : m_picture(picture), m_canvas(canvas) {}

        void Execute() override 
        {
            m_picture.DrawPicture(m_canvas);
        }

    private:
        shapes::CPicture& m_picture;
        gfx::ICanvas& m_canvas;
    };
}