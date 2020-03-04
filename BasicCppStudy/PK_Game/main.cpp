#include "FileManager.h"
#include "knife.h"
#include "broadsword.h"
#include "dragonsword.h"
#include "hero.h"


int main()
{
	FileManager fm;
	map<string, map<string, string>>m_hero, m_weapon, m_monster;
	fm.loadCSVData("resource/Hero.csv", m_hero);
	fm.loadCSVData("resource/Monster.csv", m_monster);
	fm.loadCSVData("resource/Weapon.csv", m_weapon);


	Weapon* p = new Knife;
	p = new DragonSword;
	cout << p->weaponName << endl;
	cout << p->baseDamage << endl;
	cout << p->critPlus << endl;
	cout << endl;


	Hero hero(2);
	cout << "Ӣ�����֣�" << hero.heroName << endl;
	cout << "��������" << hero.heroAtk << endl;
	hero.EquipWeapon(p);

	Monster mons(3);
	int loop= 0;
	while (true)
	{
	//�غϿ�ʼ
		loop++;
		cout << "��" << loop << "�غ�ս����ʼ��" << endl;
		hero.Attack(&mons);
		mons.Attack(&hero);
		//�ָ�
		mons.isFrozen = false;
		cout << endl;
		if (hero.heroHp<= 0 || mons.monsterHp <=0)
		{
			cout << "ս������" << endl;
			break;
		}
		
	}
	
	







	delete p;

	system("pause");
}