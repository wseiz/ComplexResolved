#include "pch.h"
#include <cmath>
#include <limits>
#include "Complex.h"

Complex::Complex() noexcept
{
	real = 0.0;
	imaginary = 0.0;
}
	
Complex::Complex(double real, double imaginary) noexcept
{
	this->real = real;
	this->imaginary = imaginary;
}

double Complex::getReal() const noexcept
{
	return real;
}

double Complex::getImaginary() const noexcept
{
	return imaginary;
}

void Complex::setReal(double const real) noexcept
{
	this->real = real;
}

void Complex::setImaginary(double const imaginary) noexcept
{
	this->imaginary = imaginary;
}

double Complex::magnitude() const noexcept
{
	return sqrt(real * real + imaginary * imaginary);
}

double Complex::direction() const noexcept
{
	return atan2(imaginary, real);
}

Complex Complex::operator+(Complex const& c) const noexcept
{
	return Complex(real + c.getReal(), imaginary + c.getImaginary());
}

Complex Complex::operator-(Complex const& c) const noexcept
{
	return Complex(real - c.getReal(), imaginary - c.getImaginary());
}

Complex Complex::operator+(double v) const noexcept
{
	return Complex(real + v, imaginary);
}

Complex Complex::operator-(double v) const noexcept
{
	return Complex(real - v, imaginary);
}

void Complex::operator+=(Complex const& c) noexcept
{
	real += c.real;
	imaginary += c.imaginary;
}

void Complex::operator+=(double v) noexcept
{
	real += v;
}

void Complex::operator-=(Complex const& c) noexcept
{
	real -= c.real;
	imaginary -= c.imaginary;
}

void Complex::operator-=(double v) noexcept
{
	real -= v;
}

bool Complex::operator==(Complex const& c) const noexcept
{
	return abs(real - c.real) < std::numeric_limits<double>::epsilon() && 
		   abs(imaginary - c.imaginary) < std::numeric_limits<double>::epsilon();
}

bool Complex::operator==(double v) const noexcept
{
	return abs(real - v) < std::numeric_limits<double>::epsilon() && 
		   abs(imaginary) < std::numeric_limits<double>::epsilon();
}

bool Complex::operator!=(Complex const& c) const noexcept
{
	return !(*this == c);
}

bool Complex::operator!=(double v) const noexcept
{
	return !(*this == v);
}

Complex operator+(double v, Complex const& c)
{
	return Complex(v + c.getReal(), c.getImaginary());
	// return c + v; // wersja alternatywna wykorzystująca operator + oraz przemienność dodawania
}

//TODO dodać definicję operatora odejmowania liczby rzeczywistej do liczby zespolonej
Complex operator-(double v, Complex const& c)
{
	return Complex( v - c.getReal(), -c.getImaginary() );
}

bool operator==(double v, Complex const& c)
{
	return c == v;
}

//TODO dodać definicję operatora != porównującego liczbę rzeczywistą z liczbą zespoloną
bool operator!=(double v, Complex const& c)
{
	return c != v;
}
