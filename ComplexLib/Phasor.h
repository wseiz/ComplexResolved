#pragma once
#include "../ComplexLib/Complex.h"

class Phasor
{
private:
	double magnitude;
	double direction;
public:
	Phasor(double magnitude, double direction) noexcept;
	Phasor(Complex const& c) noexcept;

	double getMagnitude() const noexcept;
	double getDirection() const noexcept;
	double getReal() const noexcept;
	double getImaginary() const noexcept;
	void setMagnitude(double magnitude) noexcept;
	void setDirection(double direction) noexcept;

	explicit operator Complex() const noexcept;

	Phasor operator+(Complex const& c) const noexcept;

	//TODO dodać deklarację operatora - umożliwiającego odjęcie do obiektu typu Phasor obiektu typu Complex
	Phasor operator-(Complex const& c) const noexcept;

	void operator+=(Complex const& c) noexcept;

	//TODO dodać deklarację operatora -= umożliwiającego odjęcie do obiektu typu Phasor obiektu typu Complex
	void operator-=(Complex const& c) noexcept;



	bool operator==(Complex const& c) const noexcept;
	bool operator!=(Complex const& c) const noexcept;
};
