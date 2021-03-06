#include "knife.h"

Knife::Knife()
{
	FileManager fm;
	map<string, map<string, string>>m_weapon;
	fm.loadCSVData("resource/Weapon.csv", m_weapon);

	string ID = m_weapon["1"]["weaponId"];
	this->weaponName = m_weapon[ID]["weaponName"];
	this->baseDamage = atoi(m_weapon[ID]["weaponAtk"].c_str());
	this->critPlus = atoi(m_weapon[ID]["weaponCritPlus"].c_str());
	this->critRate = atoi(m_weapon[ID]["weaponCriRate"].c_str());
	this->suckPlus = atoi(m_weapon[ID]["weaponSuckPlus"].c_str());
	this->suckRate = atoi(m_weapon[ID]["weaponSuckRate"].c_str());
	this->frozenRate = atoi(m_weapon[ID]["weaponFrozenRate"].c_str());
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
