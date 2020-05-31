#pragma once
#include "weapon.h"


class DragonSword : public Weapon
{
public:
	DragonSword();
	// 获取基础伤害值
	virtual int getBaseDamage();
	// 暴击， 返回值大于0 触发暴击
	virtual int getCrit();
	// 吸血，返回值大于0 触发吸血
	virtual int getSuckBlood();
	// 冰冻，返回true 触发冰冻
	virtual bool getFrozen();
	// 触发概率计算
	virtual bool isTrigger(int rate);
};

