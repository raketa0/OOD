#include "SaveBinaryCommand.h"
#include "../../save/BinarySaveStrategy.h"

SaveBinaryCommand::SaveBinaryCommand(std::shared_ptr<C—ompositionShapes> composition)
	:m_composition(composition){}

void SaveBinaryCommand::Execute()
{
    std::string filename;
    std::cout << "Enter filename to save (binary): ";
	std::cin >> filename;
    auto shapes = m_composition->Get—ompositionShapes();
    BinarySaveStrategy strategy(shapes);
    strategy.Save(filename);
    std::cout << "Saved to " << filename << std::endl;
	filename.clear();
}
