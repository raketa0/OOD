#pragma once
#include "../SimUDuck/lib/Duck/Quack/IQuakBehavior.h"

class MockQuackBehavior : public IQuackBehavior
{
public:
	void Quack() override
	{
		if (canQuack)
		{
			m_Quack = true;
		}
	};

	bool GetCanQuack() const 
	{
		return m_Quack;
	}
	
	void SetCanQuack(bool isQuack)
	{
		
		canQuack = isQuack;
	}

	void ResetQuack()
	{
		m_Quack = false;
	}
private:
	bool canQuack;
	bool m_Quack = false; //Типа крякнул 

};

