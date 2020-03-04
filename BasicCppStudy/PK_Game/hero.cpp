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
	// δʹ������
	if (this->pWeapon == NULL)
	{
		harm_val = this->heroAtk;
	}
	else// ʹ��������
	{
		harm_val = this->heroAtk + pWeapon->getBaseDamage();
		cri_val = pWeapon->getCrit();
		suck_val = pWeapon->getSuckBlood();
		isFronzen = pWeapon->getFrozen();
	}
	
	if (isFronzen)
	{
		cout << "<" << heroName << "> ʹ�� <" << pWeapon->weaponName << "> �����ˡ���������Ч��<" <<monster->monsterName<<"> ������"<< endl;
	}
	// ����
	if (cri_val)
	{
		cout << "<" << heroName << "> ʹ�� <" << pWeapon->weaponName << "> �����ˡ���������Ч���˺�ֵ��" << cri_val << endl;
	}
	// ��Ѫ
	if (suck_val)
	{
		cout << "<" << heroName << "> ʹ�� <" << pWeapon->weaponName << "> �����ˡ���Ѫ����Ч����Ѫֵ��" << suck_val << endl;
	}
	// output for monster
	//����
	if (isFronzen)
	{
		monster->isFrozen = true;
	}
	//��Ѫ
	if (suck_val)
	{
		this->heroHp += suck_val;
	}
	// true_harm_val����
	int harm_sum = harm_val + cri_val + suck_val - monster->monsterDef;
	int temp_sum = harm_sum > 0 ? harm_sum : 1;
	monster->monsterHp -= temp_sum;
	cout << "<" << heroName <<"> ������ <"<< monster->monsterName << "> ����ɣ�" << temp_sum<<"���˺�"<<endl;	
}

void Hero::EquipWeapon(Weapon * weapon)
{
	if (weapon == NULL)
	{
		return;
	}
	this->pWeapon = weapon;
	cout << "<" << this->heroName << "> װ����" << " <" << this->pWeapon->weaponName <<"> "<<endl;
}
