#pragma once

class BaseEquip
{
public:
	BaseEquip(): m_durValue(0),m_priceCur(0){}
	virtual void SetDuraValue(float duraValue)
	{
		m_durValue = duraValue;
	}
	//?
	virtual void SetPriceCur(float priceCur) {
		m_priceCur = priceCur;
	}
	virtual float DuraValue() const { return m_durValue; }
	virtual float PriceCur() const { return m_priceCur; }
	virtual float PowerValue() const { return m_powerValue; }
protected:
	float m_durValue;
	float m_priceCur;
	float m_powerValue;
};


