#pragma once

class Complex
{
public:
	Complex(double real, double imag) : re(real), im(imag) {}
	double Real() const { return re; }
	double Imag() const { return im; }
	Complex& operator += (const Complex& c);
private:
	double re, im;
	friend Complex& _doapl(Complex* ths, const Complex& c);
};

inline Complex& _doapl(Complex* ths, const Complex& c)
{
	ths->re = ths->re + c.Real();
	ths->im = ths->im + c.Imag();
	return *ths;
}

inline Complex& Complex::operator+=(const Complex& c)
{
	return _doapl(this, c);
}

// global
// + 
inline Complex operator + (const Complex& c, double y)
{
	return Complex(c.Real() + y, c.Imag());
}
// -
inline Complex operator - (const Complex& c)
{
	return Complex(-c.Real(), c.Imag());
}
// == 
inline bool operator == (const Complex&a, const Complex&b)
{
	return a.Real() == b.Real() && a.Imag() == b.Imag();
}
// ostream
inline std::ostream& operator <<(std::ostream& os, const Complex& c)
{
	return os << "(" << c.Real() << "," << c.Imag() << ")" << std::endl;
}



