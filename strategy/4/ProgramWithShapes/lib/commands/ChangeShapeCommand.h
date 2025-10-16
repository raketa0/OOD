#pragma once
#include"ICommand.h"
#include <string>
#include "../shapes/CPicture.h"

namespace command
{
    class ChangeShapeCommand : public ICommand
    {
    public:
        ChangeShapeCommand(shapes::CPicture& picture,
            const std::string& id,
            std::unique_ptr<shapes::IShapeStrategy> && shapeStrategy)
            : m_picture(picture),
            m_id(id),
            m_shapeStrategy(std::move(shapeStrategy)) {}

        void Execute() override 
        {
            auto shape = m_picture.GetShape(m_id);
            if (shape) 
            {
                shape->ChangeShape(std::move(m_shapeStrategy));
            }
        }

    private:
        shapes::CPicture& m_picture;
        std::string m_id;
        std::unique_ptr<shapes::IShapeStrategy>  m_shapeStrategy;
    };
}
