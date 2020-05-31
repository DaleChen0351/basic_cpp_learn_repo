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
	cout << "英雄名字：" << hero.heroName << endl;
	cout << "攻击力：" << hero.heroAtk << endl;
	hero.EquipWeapon(p);

	Monster mons(3);
	int loop= 0;
	while (true)
	{
	//回合开始
		loop++;
		cout << "第" << loop << "回合战斗开始！" << endl;
		hero.Attack(&mons);
		mons.Attack(&hero);
		//恢复
		mons.isFrozen = false;
		cout << endl;
		if (hero.heroHp<= 0 || mons.monsterHp <=0)
		{
			cout << "战斗结束" << endl;
			break;
		}
		
	}
	
	







	delete p;

	system("pause");
}