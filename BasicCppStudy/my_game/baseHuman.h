#pragma once


class Human
{
public:
	Human(float lifeValue = 0, float magicValue = 0, std::string name = "name")
		: m_lifeValue(lifeValue), m_magicValue(magicValue), m_name(name), m_equipAttack(nullptr) {}
	float GetLifeValue() const { return m_lifeValue; }
	float GetMagicValue() const { return m_magicValue; }
	float AttackPower() const { return m_attaackPower; }
	BaseEquip* GetEquipAttack() const { return m_equipAttack; }
	void SetLifeValue(float lifeValue) { m_lifeValue = lifeValue; }
	bool MagicValueConcume(float magicV) {
		m_magicValue -= magicV;
		if (m_magicValue <= 0)
			return false;
	}
	bool LifeValueConsume(float lifeV) {
		m_lifeValue -= m_lifeValue;
		if (m_lifeValue <= 0)
			return false;
	}
	std::string GetName() const { return m_name; }
	// > operator overloading
	bool operator < (const Human& h);
	virtual ~Human() {}
protected:
	float m_lifeValue;// Ѫֵ
	float m_magicValue; // ħ��ֵ
	float m_attaackPower;
	std::string m_name;
	// Dale new
	BaseEquip* m_equipAttack;
};
inline bool Human::operator<(const Human& h)
{
	return this->m_lifeValue < h.m_lifeValue;
}
// global
inline std::ostream& operator << (std::ostream& os, Human& h)
{
	os << h.GetName().c_str() << ":" << std::endl;
	os << h.GetLifeValue() << std::endl;
	return os;
}
// add blood
inline Human& operator +(Human& h, float lifeValue)
{
	float t_value = h.GetLifeValue() + lifeValue;
	h.SetLifeValue(t_value);
	return h;
}


