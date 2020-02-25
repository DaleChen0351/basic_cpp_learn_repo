#include "knife.h"

Knife::Knife()
{
	FileManager fm;
	map<string, map<string, string>>m_weapon;
	fm.loadCSVData("resource/Weapon.csv", m_weapon);
}

int Knife::getBaseDamage()
{
	return this->baseDamage;
}

int Knife::getCrit()
{
	if (isTrigger(this->critRate))
	{
		return getBaseDamage() * this->critPlus;
	}
	return 0;
}

int Knife::getSuckBlood()
{
	if (isTrigger(this->suckRate))
	{
		return getBaseDamage() * this->suckPlus;
	}
	return 0;
}

bool Knife::getFrozen()
{
	return isTrigger(this->frozenRate);
}

bool Knife::isTrigger(int rate)
{
	//
	int randVal = rand() & 100 + 1;// 1~100
	if (randVal < rate)
	{
		return true;
	}
	return false;
}
