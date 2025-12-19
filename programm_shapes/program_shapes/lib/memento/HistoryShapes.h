#pragma once

#include "IMementoShapes.h"
#include <stack>

class HistoryShapes
{
public:
	static HistoryShapes& GetInstance();
	void AddMemento(std::shared_ptr<IMementoShapes> memento);
	void Undo();
	void Redo();
private:
	std::stack<std::shared_ptr<IMementoShapes>> m_undoStack;
	std::stack<std::shared_ptr<IMementoShapes>> m_redoStack;
};
