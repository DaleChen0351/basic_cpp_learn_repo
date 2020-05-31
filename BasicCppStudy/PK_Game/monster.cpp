#include "monster.h"

Monster::Monster(int monsterId)
{
	FileManager fm;
	map<string, map<string, string>>m_monster;
	fm.loadCSVData("resource/Monster.csv", m_monster);

	string tem_id = std::to_string(monsterId);
	string Id = m_monster[tem_id]["monsterId"];

	this->monsterName = m_monster[tem_id]["monsterName"];
	this->monsterAtk = atoi(m_monster[tem_id]["monsterAtk"].c_str());
	this->monsterDef = atoi(m_monster[tem_id]["monsterDef"].c_str());
	this->monsterHp = atoi(m_monster[tem_id]["monsterHp"].c_str());
	this->isFrozen = false;

}

void Monster::Attack(Hero * hero)
{
	if (this->isFrozen)
	{
		cout << "<" << this->monsterName << "> �����������غ��޷����� <" << hero->heroName << "> " << endl;
		return;
	}

	int harm_val = this->monsterAtk - hero->heroDef > 0 ? monsterAtk - hero->heroDef : 1;
	hero->heroHp -= harm_val;

	cout << "<" << monsterName << "> ������ <" << hero->heroName << ">����ɣ� "<< harm_val <<" ���˺�" << endl;
}
