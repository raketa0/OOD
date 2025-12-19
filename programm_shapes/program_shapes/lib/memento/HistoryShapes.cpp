#include "HistoryShapes.h"

HistoryShapes& HistoryShapes::GetInstance()
{
	static HistoryShapes instance;
	return instance;
}

void HistoryShapes::AddMemento(std::shared_ptr<IMementoShapes> memento)
{
	m_undoStack.push(memento);
	while (!m_redoStack.empty())
	{
		m_redoStack.pop();
	}
}

void HistoryShapes::Undo()
{
	if (m_undoStack.empty())
	{
		return;
	}
	auto memento = m_undoStack.top();
	m_undoStack.pop();
	memento->Restore();
	m_redoStack.push(memento);
}

void HistoryShapes::Redo()
{
	if (m_redoStack.empty())
	{
		return;
	}
	auto memento = m_redoStack.top();
	m_redoStack.pop();
	memento->Restore();
	m_undoStack.push(memento);
}
