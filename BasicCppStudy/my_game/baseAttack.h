#pragma once
#include "baseHuman.h"
// decorodator
// and bridge: ������̺;���ʵ�����Ÿ��Ե�ά�ȱ仯

// ���幥�����̿���bridgeģʽ
// ������������
	// �����;��½�
	// ����ֵ���½�
	// ������ֵ�ļ���
// ��չ�������̡�������
	// �����;��½�
	// ����ֵ�½���
	// ������ֵ��
// ��չ�������̡�������
	// ..
	// �����½���
	// ������ֵ��
	// KO�������

// Implementor :����������ֵ��������չ
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
//Abstraction  ��ս����������չ
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
	// ����������ֵ, ħ���������;ã� ������
public:
	virtual float AttackPowerOutput(const Human& human)
	{
		m_UserPower = human.AttackPower();
		m_EquipPower = human.GetEquipAttack()->PowerValue;
		return m_UserPower + m_EquipPower / 2;
	}
	virtual void EgoMagicValueConsume(Human& human)
	{
		human.MagicValueConcume(10);// ����Ӧ���о���ļ���������
	}
	virtual void EgoLifeValueConsume(Human& human)
	{
		human.LifeValueConsume(10);
	}
};

class MagicAttack : public BaseAttack
{
	// ����ħ������ֵ, ħ��ֵ�½�
	// �������ԣ�
public:
	virtual float AttackPowerOutput()
	{

	}
private:
	float m_UserMagic;

};
// ��ħ������������Խ�����չ decoratorģʽ
class HonerSpace : public BaseAttack
{
	// ����������ħ����������ļӳ�
};


// ? ȫ���������õ�ʱ������ȥ�½����󣿹��캯�� ������Init����