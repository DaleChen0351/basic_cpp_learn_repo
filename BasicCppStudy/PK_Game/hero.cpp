#include "hero.h"

Hero::Hero(int heroId)
{
	FileManager fm;
	map<string, map<string, string>>m_hero;
	fm.loadCSVData("resource/Hero.csv", m_hero);

	string ID_str = std::to_string(heroId);
	string Id = m_hero[ID_str]["heroId"];
	this->heroName = m_hero[Id]["heroName"];
	this->heroAtk = atoi(m_hero[Id]["heroAtk"].c_str());
	this->heroDef = atoi(m_hero[Id]["heroAtk"].c_str());
	this->heroHp = atoi(m_hero[Id]["heroAtk"].c_str());
	this->heroInfo = m_hero[Id]["heroAtk"];

	this->pWeapon = NULL;
}

void Hero::Attack(Monster * monster)
{
	int harm_val = 0;
	int cri_val = 0;
	int suck_val = 0;
	bool isFronzen = false;
	// 未使用武器
	if (this->pWeapon == NULL)
	{
		harm_val = this->heroAtk;
	}
	else// 使用了武器
	{
		harm_val = this->heroAtk + pWeapon->getBaseDamage();
		cri_val = pWeapon->getCrit();
		suck_val = pWeapon->getSuckBlood();
		isFronzen = pWeapon->getFrozen();
	}
	
	if (isFronzen)
	{
		cout << "<" << heroName << "> 使用 <" << pWeapon->weaponName << "> 产生了“冰冻”特效！<" <<monster->monsterName<<"> 被冰冻"<< endl;
	}
	// 暴击
	if (cri_val)
	{
		cout << "<" << heroName << "> 使用 <" << pWeapon->weaponName << "> 产生了“暴击”特效！伤害值：" << cri_val << endl;
	}
	// 吸血
	if (suck_val)
	{
		cout << "<" << heroName << "> 使用 <" << pWeapon->weaponName << "> 产生了“吸血”特效！吸血值：" << suck_val << endl;
	}
	// output for monster
	//冰冻
	if (isFronzen)
	{
		monster->isFrozen = true;
	}
	//吸血
	if (suck_val)
	{
		this->heroHp += suck_val;
	}
	// true_harm_val计算
	int harm_sum = harm_val + cri_val + suck_val - monster->monsterDef;
	int temp_sum = harm_sum > 0 ? harm_sum : 1;
	monster->monsterHp -= temp_sum;
	cout << "<" << heroName <<"> 攻击了 <"<< monster->monsterName << "> 共造成：" << temp_sum<<"点伤害"<<endl;	
}

void Hero::EquipWeapon(Weapon * weapon)
{
	if (weapon == NULL)
	{
		return;
	}
	this->pWeapon = weapon;
	cout << "<" << this->heroName << "> 装备了" << " <" << this->pWeapon->weaponName <<"> "<<endl;
}
