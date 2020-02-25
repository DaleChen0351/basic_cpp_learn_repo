#pragma once
#include "FileManager.h"

class Weapon
{
public:
	// 获取基础伤害值
	virtual int getBaseDamage() = 0;
	// 暴击， 返回值大于0 触发暴击
	virtual int getCrit() = 0;
	// 吸血，返回值大于0 触发吸血
	virtual int getSuckBlood() = 0;
	// 冰冻，返回true 触发冰冻
	virtual bool getFrozen() = 0;
	// 触发概率计算
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
