#pragma once
class Complex
{
private:
	double real;
	double imaginary;
public:
	Complex() noexcept;
	Complex(double real, double imaginary) noexcept;
	double getReal() const noexcept;
	double getImaginary() const noexcept;
	void setReal(double const real) noexcept;
	void setImaginary(double const imaginary) noexcept;
	double magnitude() const noexcept;
	double direction() const noexcept;
	
	Complex operator+(Complex const& c) const noexcept;
	Complex operator-(Complex const& c) const noexcept;
	Complex operator+(double v) const noexcept;
	Complex operator-(double v) const noexcept;

	void operator+=(Complex const& c) noexcept;
	void operator+=(double v) noexcept;
	void operator-=(Complex const& c) noexcept;
	void operator-=(double v) noexcept;

	bool operator==(Complex const& c) const noexcept;
	bool operator==(double v) const noexcept;
	bool operator!=(Complex const& c) const noexcept;
	bool operator!=(double v) const noexcept;
};

Complex operator+(double v, Complex const& c);

//TODO dodać deklarację operatora odejmowania liczby rzeczywistej do liczby zespolonej
Complex operator-(double v, Complex const& c);

bool operator==(double v, Complex const& c);

//TODO dodać deklarację operatora != porównującego liczbę rzeczywistą z liczbą zespoloną
bool operator!=(double v, Complex const& c);

