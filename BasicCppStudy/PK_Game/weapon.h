#pragma once
#include "FileManager.h"

class Weapon
{
public:
	// ��ȡ�����˺�ֵ
	virtual int getBaseDamage() = 0;
	// ������ ����ֵ����0 ��������
	virtual int getCrit() = 0;
	// ��Ѫ������ֵ����0 ������Ѫ
	virtual int getSuckBlood() = 0;
	// ����������true ��������
	virtual bool getFrozen() = 0;
	// �������ʼ���
	virtual bool isTrigger(int rate) = 0;
public:
	int baseDamage;
	string weaponName;
	int critPlus;
	int critRate;
	int suckPlus;
	int suckRate;
	int frozenRate;


};
