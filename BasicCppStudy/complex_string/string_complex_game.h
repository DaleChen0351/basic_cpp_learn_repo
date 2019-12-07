#pragma once

class Human
{
public:
	Human(float lifeValue = 0, float magicValue = 0, std::string name= "name") 
	: m_lifeValue(lifeValue), m_magicValue(magicValue), m_name(name){}
	float GetLifeValue() const { return m_lifeValue; }
	float GetMagicValue() const { return m_magicValue; }
	void SetLifeValue(float lifeValue) { m_lifeValue = lifeValue; }
	std::string GetName() const { return m_name; }
// > operator overloading
	bool operator < (const Human& h);
	virtual ~Human(){}

private:
	float m_lifeValue;// Ѫֵ
	float m_magicValue; // ħ��ֵ
	std::string m_name;
};
inline bool Human::operator<(const Human& h)
{
	return this->m_lifeValue < h.m_lifeValue;
}
// global
inline std::ostream& operator << (std::ostream& os,  Human& h)
{
	os << h.GetName().c_str() << ":" << std::endl;
	os<< h.GetLifeValue() << std::endl;
	return os;
}
// add blood
inline Human& operator +(Human& h, float lifeValue)
{
	float t_value = h.GetLifeValue() + lifeValue;
	h.SetLifeValue(t_value);
	return h;
}

