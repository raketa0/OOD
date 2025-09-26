#include "CommandParser.h"
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <iostream>

namespace parser 
{

    gfx::Color CommandParser::ParseColor(const std::string& hex) 
    {
        if (hex.size() != 7 || hex[0] != '#') 
        {
            throw std::runtime_error("Invalid color format. Expected #RRGGBB");
        }

        unsigned int r, g, b;
        std::istringstream(hex.substr(1, 6)) >> std::hex >> std::setw(2) >> r >> std::setw(2) >> g >> std::setw(2) >> b;

        return gfx::Color
        {
            static_cast<unsigned char>(r),
            static_cast<unsigned char>(g),
            static_cast<unsigned char>(b)
        };
    }

    std::unique_ptr<shapes::IShapeStrategy> CommandParser::ParseStrategy(const std::string& type, std::istringstream& iss) 
    {
        if (type == "circle") 
        {
            double cx, cy, r;
            if (!(iss >> cx >> cy >> r)) 
            {
                throw std::runtime_error("Usage: circle <cx> <cy> <r>");
            }
            return std::make_unique<shapes::CircleStrategy>(cx, cy, r);
        }
        else if (type == "rectangle") 
        {
            double left, top, w, h;
            if (!(iss >> left >> top >> w >> h)) 
            {
                throw std::runtime_error("Usage: rectangle <left> <top> <w> <h>");
            }
            return std::make_unique<shapes::RectangleStrategy>(left, top, w, h);
        }
        else if (type == "triangle")
        {
            double x1, y1, x2, y2, x3, y3;
            if (!(iss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)) 
            {
                throw std::runtime_error("Usage: triangle <x1> <y1> <x2> <y2> <x3> <y3>");
            }
            return std::make_unique<shapes::TriangleStrategy>(x1, y1, x2, y2, x3, y3);
        }
        else if (type == "line") 
        {
            double x1, y1, x2, y2;
            if (!(iss >> x1 >> y1 >> x2 >> y2))
            {
                throw std::runtime_error("Usage: line <x1> <y1> <x2> <y2>");
            }
            return std::make_unique<shapes::LineStrategy>(x1, y1, x2, y2);
        }
        else if (type == "text")
        {
            double left, top, size;
            if (!(iss >> left >> top >> size))
            {
                throw std::runtime_error("Usage: text <left> <top> <size> <string>");

            }
            std::string text;
            std::getline(iss, text);
            if (!text.empty() && text[0] == ' ') text.erase(0, 1);
            return std::make_unique<shapes::TextStrategy>(left, top, size, text);
        }
        throw std::runtime_error("Unknown shape type: " + type);
    }

    std::unique_ptr<command::ICommand> CommandParser::ParseAddShape(std::istringstream& iss) 
    {
        std::string id, colorHex, type;
        if (!(iss >> id >> colorHex >> type))
        {
            throw std::runtime_error("Usage: AddShape <id> <#RRGGBB> <type> <params...>");

        }
        auto color = ParseColor(colorHex);
        auto strategy = ParseStrategy(type, iss);
        return std::make_unique<command::AddShapeCommand>(m_picture, id, color, std::move(strategy));
    }

    std::unique_ptr<command::ICommand> CommandParser::ParseMoveShape(std::istringstream& iss) 
    {
        std::string id; double dx, dy;
        if (!(iss >> id >> dx >> dy)) 
        {
            throw std::runtime_error("Usage: MoveShape <id> <dx> <dy>");
        }
        return std::make_unique<command::MoveShapeCommand>(m_picture, id, dx, dy);
    }

    std::unique_ptr<command::ICommand> CommandParser::ParseMovePicture(std::istringstream& iss)
    {
        double dx, dy;
        if (!(iss >> dx >> dy)) 
        {
            throw std::runtime_error("Usage: MovePicture <dx> <dy>");
        }
        return std::make_unique<command::MovePictureCommand>(m_picture, dx, dy);
    }

    std::unique_ptr<command::ICommand> CommandParser::ParseDeleteShape(std::istringstream& iss)
    {
        std::string id;
        if (!(iss >> id)) 
        {
            throw std::runtime_error("Usage: DeleteShape <id>");
        }
        return std::make_unique<command::DeleteShapeCommand>(m_picture, id);
    }

    std::unique_ptr<command::ICommand> CommandParser::ParseChangeColor(std::istringstream& iss)
    {
        std::string id, colorHex;
        if (!(iss >> id >> colorHex)) 
        {
            throw std::runtime_error("Usage: ChangeColor <id> <#RRGGBB>");
        }
        auto color = ParseColor(colorHex);
        return std::make_unique<command::ChangeColorCommand>(m_picture, id, color);
    }

    std::unique_ptr<command::ICommand> CommandParser::ParseChangeShape(std::istringstream& iss) 
    {
        std::string id, type;
        if (!(iss >> id >> type)) 
        {
            throw std::runtime_error("Usage: ChangeShape <id> <type> <params...>");
        }
        auto strategy = ParseStrategy(type, iss);
        return std::make_unique<command::ChangeShapeCommand>(m_picture, id, std::move(strategy));
    }

    std::unique_ptr<command::ICommand> CommandParser::ParseDrawShape(std::istringstream& iss) 
    {
        std::string id;
        if (!(iss >> id))
        {
            throw std::runtime_error("Usage: DrawShape <id>");
        }
        return std::make_unique<command::DrawShapeCommand>(m_picture, id, m_canvas);
    }

    std::unique_ptr<command::ICommand> CommandParser::ParseDrawPicture(std::istringstream& iss)
    {
        return std::make_unique<command::DrawPictureCommand>(m_picture, m_canvas);
    }

    std::unique_ptr<command::ICommand> CommandParser::ParseList(std::istringstream& iss)
    {
        return std::make_unique<command::ListCommand>(m_picture);//
    }

    std::unique_ptr<command::ICommand> CommandParser::Parse(const std::string& line)
    {
        std::istringstream iss(line);
        std::string cmd;
        if (!(iss >> cmd)) 
        {
            throw std::runtime_error("Empty command");
        }
        else if (cmd == "AddShape")  
        {
            return ParseAddShape(iss);
        }
        else if (cmd == "MoveShape")  
        {
            return ParseMoveShape(iss);
        }
        else if (cmd == "MovePicture")
        {
            return ParseMovePicture(iss);
        }
        else if (cmd == "DeleteShape")
        {
            return ParseDeleteShape(iss);
        }
        else if (cmd == "ChangeColor")
        {
            return ParseChangeColor(iss);
        }
        else if (cmd == "ChangeShape")
        {
            return ParseChangeShape(iss);
        }
        else if (cmd == "DrawShape")
        {
            return ParseDrawShape(iss);
        }
        else if (cmd == "DrawPicture")
        {
            return ParseDrawPicture(iss);
        }
        else if (cmd == "List")
        {
            return ParseList(iss);
        }
        throw std::runtime_error("Unknown command: " + cmd);
    }
}
