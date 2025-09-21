#pragma once
#include "../SimUDuck/lib/Duck/Dance/IDanceBehavior.h"
#include <memory>

class MockDuck 
{
public:
	MockDuck(std::unique_ptr<IDanceBehavior>&& danceBehavior)
	: m_danceBehavior(std::move(danceBehavior)){};

	void Dance() const
	{
		m_danceBehavior->Dance();
	}

	std::unique_ptr<IDanceBehavior> m_danceBehavior;
};
