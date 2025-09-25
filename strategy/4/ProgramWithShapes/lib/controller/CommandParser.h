#pragma once

#include <memory>
#include <sstream>
#include <string>
#include <stdexcept>
#include "../shapes/CPicture.h"
#include "../shapes/ShapeStrategy/IShapeStrategy.h"
#include "../shapes/ShapeStrategy/CircleStrategy.h"
#include "../shapes/ShapeStrategy/LineStrategy.h"
#include "../shapes/ShapeStrategy/RectangleStrategy.h"
#include "../shapes/ShapeStrategy/TextStrategy.h"
#include "../shapes/ShapeStrategy/TriangleStrategy .h"

#include "../gfx/CCanvas.h"
#include "../gfx/Color.h"
#include "../commands/ICommand.h"
#include "../commands/AddShapeCommand.h"
#include "../commands/MoveShapeCommand .h"
#include "../commands/MovePictureCommand.h"
#include "../commands/DeleteShapeCommand.h"
#include "../commands/ChangeColorCommand.h"
#include "../commands/ChangeShapeCommand.h"
#include "../commands/DrawShapeCommand.h"
#include "../commands/DrawPictureCommand.h"
#include "../commands/ListCommand.h"

namespace parser 
{

    class CommandParser 
    {
    public:
        CommandParser(shapes::CPicture& picture, gfx::ICanvas& canvas)
            : m_picture(picture), m_canvas(canvas) {}

        std::unique_ptr<command::ICommand> Parse(const std::string& line);

    private:
        gfx::Color ParseColor(const std::string& hex);
        std::unique_ptr<shapes::IShapeStrategy> ParseStrategy(const std::string& type, std::istringstream& iss);
        
        std::unique_ptr<command::ICommand> ParseAddShape(std::istringstream& iss);
        std::unique_ptr<command::ICommand> ParseMoveShape(std::istringstream& iss);
        std::unique_ptr<command::ICommand> ParseMovePicture(std::istringstream& iss);
        std::unique_ptr<command::ICommand> ParseDeleteShape(std::istringstream& iss);
        std::unique_ptr<command::ICommand> ParseChangeColor(std::istringstream& iss);
        std::unique_ptr<command::ICommand> ParseChangeShape(std::istringstream& iss);
        std::unique_ptr<command::ICommand> ParseDrawShape(std::istringstream& iss);
        std::unique_ptr<command::ICommand> ParseDrawPicture(std::istringstream& iss);
        std::unique_ptr<command::ICommand> ParseList(std::istringstream& iss);

    private:
        shapes::CPicture& m_picture;
        gfx::ICanvas& m_canvas;
    };

}