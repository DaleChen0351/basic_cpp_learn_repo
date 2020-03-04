#pragma once
#include "weapon.h"
#include "FileManager.h"
#include "monster.h"
class Monster;
class Hero
{
public:
	Hero(int heroId);
	void Attack(Monster* monster);
	void EquipWeapon(Weapon* weapon);
public:
	string heroName;
	string heroInfo;
	int heroHp;
	int heroAtk;
	int heroDef;
	Weapon* pWeapon;

};