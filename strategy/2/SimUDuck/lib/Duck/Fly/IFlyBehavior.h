#ifndef LAB01_SIMUDUCK_IFLYBEHAVIOR_H
#define LAB01_SIMUDUCK_IFLYBEHAVIOR_H

//пересмотреть const методы
struct IFlyBehavior
{
	virtual ~IFlyBehavior(){};
	virtual void Fly() = 0;
	virtual bool CanFly()  = 0; // объ€вит const  в реализ которых не должны измен€ть состо€ние стратегии
	virtual int GetCountFly()  = 0;
};

#endif
