#include "LoadBinaryCommand.h"
#include <iostream>
#include "../../load/Template Method/BinaryShapeLoader.h"

LoadBinaryCommand::LoadBinaryCommand(std::shared_ptr<CÑompositionShapes> composition)
    : m_composition(composition)
{
}

void LoadBinaryCommand::Execute()
{
    m_composition->CloseAllShapes();

    std::string filename;
    std::cout << "Enter BIN filename: ";
    std::cin >> filename;

    BinaryShapeLoader loader;
    loader.Load(filename, m_composition);
}
