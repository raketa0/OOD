#include "CPicture.h"
#include "../tools/Constants.h"



void CPicture::AddShape(std::unique_ptr<IShape> shape)
{
	m_shapes.push_back(std::move(shape));
}

void CPicture::DrawPicture(ICanvas& canvas)
{
	for (auto& shape : m_shapes)
	{
		shape->DrawShape(canvas);
	}
}

void CPicture::LoadFromFile(const std::string& filename)
{
    std::ifstream fin(filename);
    if (!fin.is_open()) 
    {
        std::cout << ERROR_OPENING_FILE << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(fin, line)) 
    {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string type;
        ss >> type;

        Shape enumType = StrTypeInEnum(type);

        switch (enumType)
        {
        case CIRCLE:
        {
            auto circle = ParserCircle(line);
            AddShape(std::make_unique<CircleAdapter>(circle));
            break;
        }
        case RECTANGLE:
        {
            auto rectange = ParserRectangle(line);
            AddShape(std::make_unique<RectangleAdapter>(rectange));
            break;
        }
        case TRIANGLE:
        {
            auto triangle = ParserTriangle(line);
            AddShape(std::make_unique<TriangleAdapter>(triangle));
            break;
        }
        default:
            break;
        }
    }

    fin.close();
}

void CPicture::OutCharacteristics()
{
    std::ofstream fout(OUTPUT_FILE);
    if (!fout.is_open())
    {
        std::cerr << OUTPUT_FILE_ERROR << std::endl;
        return;
    }

    for (auto& shape : m_shapes)
    {
        fout << shape->GetType() << PERIMETER_LABEL << shape->Perimeter() << AREA_LABEL << shape->Area() << NEWLINE;
    }

    std::cout << RESULTS_WRITTEN;
}
