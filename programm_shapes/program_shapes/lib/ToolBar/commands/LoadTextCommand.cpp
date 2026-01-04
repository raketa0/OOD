#include "LoadTextCommand.h"
#include "../../load/Template Method/TextShapeLoader.h"
#include <iostream>

LoadTextCommand::LoadTextCommand(std::shared_ptr<CÑompositionShapes> composition)
    : m_composition(composition) {}

void LoadTextCommand::Execute()
{
	m_composition->CloseAllShapes();
    std::string filename;
    std::cout << "Enter TXT filename: ";
    std::cin >> filename;
    TextShapeLoader loader;
    loader.Load(filename, m_composition);
}