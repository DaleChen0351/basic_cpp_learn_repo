#include "FileManager.h"


int main()
{
	FileManager fm;
	map<string, map<string, string>>m_hero, m_weapon, m_monster;
	fm.loadCSVData("resource/Hero.csv", m_hero);
	fm.loadCSVData("resource/Monster.csv", m_monster);
	fm.loadCSVData("resource/Weapon.csv", m_weapon);

	cout << "end of it " << endl;

	system("pause");
}