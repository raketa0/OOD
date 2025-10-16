#ifndef LAB01_SIMUDUCK_IFLYBEHAVIOR_H
#define LAB01_SIMUDUCK_IFLYBEHAVIOR_H

//������������ const ������
struct IFlyBehavior
{
	virtual ~IFlyBehavior(){};
	virtual void Fly() = 0;
	virtual bool CanFly()  = 0; // ������� const  � ������ ������� �� ������ �������� ��������� ���������
	virtual int GetCountFly()  = 0;
};

#endif
