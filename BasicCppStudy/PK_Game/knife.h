#pragma once
#include "weapon.h"


class Knife : public Weapon
{
public:
	Knife();

	// ��ȡ�����˺�ֵ
	virtual int getBaseDamage();
	// ������ ����ֵ����0 ��������
	virtual int getCrit();
	// ��Ѫ������ֵ����0 ������Ѫ
	virtual int getSuckBlood();
	// ����������true ��������
	virtual bool getFrozen();
	// �������ʼ���
	virtual bool isTrigger(int rate);

};
