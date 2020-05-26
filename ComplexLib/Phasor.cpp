#include "pch.h"
#include <cmath>
#include <limits>
#include "Phasor.h"

Phasor::Phasor(double magnitude, double direction) noexcept : magnitude(magnitude), direction(direction) 
{
}

Phasor::Phasor(Complex const& c) noexcept
{
	magnitude = c.magnitude();
	direction = c.direction();
}

double Phasor::getMagnitude() const noexcept
{
	return magnitude;
}

double Phasor::getDirection() const noexcept
{
	return direction;
}

double Phasor::getReal() const noexcept
{
	return magnitude * cos(direction);
}

double Phasor::getImaginary() const noexcept
{
	return magnitude * sin(direction);
}

void Phasor::setMagnitude(double magnitude) noexcept
{
	this->magnitude = magnitude;
}

void Phasor::setDirection(double direction) noexcept
{
	this->direction = direction;
}

Phasor::operator Complex() const noexcept
{
	return Complex(getReal(), getImaginary());
}

Phasor Phasor::operator+(Complex const& c) const noexcept
{
	return Phasor(Complex(*this) + c);
}

Phasor Phasor::operator-(Complex const& c) const noexcept
{
	return Phasor(Complex(*this) - c);
}

void Phasor::operator+=(Complex const& c) noexcept
{
	Complex result = (Complex)(*this) + c;
	magnitude = result.magnitude();
	direction = result.direction();
}

void Phasor::operator-=(Complex const& c) noexcept
{
	Complex result = (Complex)(*this) - c;
	magnitude = result.magnitude();
	direction = result.direction();
}

bool Phasor::operator==(Complex const& c) const noexcept
{
	return abs(magnitude - c.magnitude()) < std::numeric_limits<double>::epsilon() &&
		   abs(direction - c.direction()) < std::numeric_limits<double>::epsilon();
}

bool Phasor::operator!=(Complex const& c) const noexcept
{
	return !(*this == c);
}
