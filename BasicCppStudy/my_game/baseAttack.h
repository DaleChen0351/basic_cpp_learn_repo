#pragma once
#include "baseHuman.h"
// decorodator
// and bridge: 抽象过程和具体实现沿着各自的维度变化

// 整体攻击流程可用bridge模式
// 基本攻击流程
	// 武器耐久下降
	// 体力值的下降
	// 攻击总值的计算
// 扩展攻击流程——反击
	// 武器耐久下降
	// 体力值下降少
	// 攻击总值少
// 扩展攻击流程——闪击
	// ..
	// 体力下降多
	// 攻击总值多
	// KO情况出现

// Implementor :从自身属性值消耗上扩展
class BaseAttack
{
public:
	virtual float AttackPowerOutput(const Human& human) = 0;
	virtual void EgoMagicValueConsume(Human& human) = 0;
	virtual void EgoLifeValueConsume(Human& human) = 0;
	virtual ~BaseAttack(){}
protected:
	float m_UserPower;
	float m_EquipPower;
};
//Abstraction  从战斗流程上扩展
class BaseAttackProc
{
public:
	BaseAttack* m_attack;
	
	BaseAttackProc() : m_name("BaseAttackProc"), m_attack(nullptr){}
	virtual void EgoBodyConsume(Human& human) = 0;
	virtual float CalcAttackPower(const Human& human) = 0;
	virtual ~BaseAttackProc(){}
protected:
	std::string m_name;
};
// Refined Abstraction
class NormalAttackProc : public BaseAttackProc
{
public:
	NormalAttackProc() { m_name = "NormalAttackProc"; }
	virtual float CalcAttackPower(const Human& human)
	{
		return  m_attack->AttackPowerOutput(human);
	}
	virtual void EgoBodyConsume(Human& human)
	{
		m_attack->EgoLifeValueConsume(human);
		m_attack->EgoMagicValueConsume(human);
	}
};

// Concrete Implementor
class PhyAttack : public BaseAttack
{
	// 调用物理攻击值, 魔法类武器耐久， 体力等
public:
	virtual float AttackPowerOutput(const Human& human)
	{
		m_UserPower = human.AttackPower();
		m_EquipPower = human.GetEquipAttack()->PowerValue;
		return m_UserPower + m_EquipPower / 2;
	}
	virtual void EgoMagicValueConsume(Human& human)
	{
		human.MagicValueConcume(10);// 参数应该有具体的技能所决定
	}
	virtual void EgoLifeValueConsume(Human& human)
	{
		human.LifeValueConsume(10);
	}
};

class MagicAttack : public BaseAttack
{
	// 调用魔法攻击值, 魔法值下降
	// 法术策略？
public:
	virtual float AttackPowerOutput()
	{

	}
private:
	float m_UserMagic;

};
// 对魔法和物理均可以进行扩展 decorator模式
class HonerSpace : public BaseAttack
{
	// 无论物理还是魔法攻击输出的加成
};


// ? 全部都是引用的时候，哪里去新建对象？构造函数 或者是Init函数