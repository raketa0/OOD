#include "SaveTextCommand.h"

SaveTextCommand::SaveTextCommand(std::shared_ptr<C—ompositionShapes> composition)
    : m_composition(composition) {}

void SaveTextCommand::Execute()
{
    std::string filename;
    std::cout << "Enter filename to save (text): ";
    std::cin >> filename;

    auto shapes = m_composition->Get—ompositionShapes();
    TextSaveStrategy strategy(shapes);
    strategy.Save(filename);
    std::cout << "Saved to " << filename << std::endl;
	filename.clear();
}
