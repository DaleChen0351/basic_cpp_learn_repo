#pragma once
#include "FileManager.h"
#include "hero.h"
class Hero;
class Monster
{
public:
	Monster(int monsterId);
	void Attack(Hero* hero);
public:
	string monsterName;
	int monsterAtk;
	int monsterDef;
	int monsterHp;
	bool isFrozen;

};
