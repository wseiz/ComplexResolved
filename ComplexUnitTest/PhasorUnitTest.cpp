#include "pch.h"
#include "CppUnitTest.h"
#include "../ComplexLib/Complex.h"
#include "../ComplexLib/Phasor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ComplexUnitTest
{
	TEST_CLASS(PhasorUnitTest)
	{
	public:
		TEST_METHOD(ConstructorWithParameterMagnitudeDirection)
		{
			Phasor p(512.37, 1.89);
			Assert::AreEqual(512.37, p.getMagnitude(), 0.01);
			Assert::AreEqual(1.89, p.getDirection(), 0.01);
		}
		TEST_METHOD(ConstructorWithParameterComplex)
		{
			Complex c(132.73, 423.59);
			Phasor p(c);
			Assert::AreEqual(443.90, p.getMagnitude(), 0.01);
			Assert::AreEqual(1.27, p.getDirection(), 0.01);
		}
		TEST_METHOD(getMagnitude)
		{
			Phasor p(253.74, 1.89);
			Assert::AreEqual(253.74, p.getMagnitude(), 0.01);
		}
		TEST_METHOD(getDirection)
		{
			Phasor p(253.74, 1.89);
			Assert::AreEqual(1.89, p.getDirection(), 0.01);
		}
		TEST_METHOD(getReal)
		{
			Phasor p(23.74, 0.89);
			Assert::AreEqual(14.94, p.getReal(), 0.01);
		}
		TEST_METHOD(getImaginary)
		{
			Phasor p(23.74, 0.89);
			Assert::AreEqual(18.45, p.getImaginary(), 0.01);
		}
		TEST_METHOD(setMagnitude)
		{
			Phasor p(223.74, -0.23);
			p.setMagnitude(920.23);
			Assert::AreEqual(920.23, p.getMagnitude(), 0.01);
		}
		TEST_METHOD(setDirection)
		{
			Phasor p(523.74, 1.02);
			p.setDirection(0.23);
			Assert::AreEqual(0.23, p.getDirection(), 0.01);
		}
		TEST_METHOD(operatorConversionComplex)
		{
			Phasor p(1.45, 0.05);
			Complex c(0.0, 0.0);

			c = (Complex)p;
			Assert::AreEqual(1.45, c.magnitude(), 0.01);
			Assert::AreEqual(0.05, c.direction(), 0.01);
		}
		TEST_METHOD(operatorPlusPhasorComplex)
		{
			Phasor a(0.0, 0.0);
			Phasor b(132.87, -1.39);
			Complex c(-2.41, 34.35);
			a = b + c;
			Assert::AreEqual(98.72, a.getMagnitude(), 0.01);
			Assert::AreEqual(-1.35, a.getDirection(), 0.01);
		}
		TEST_METHOD(operatorMinusPhasorComplex)
		{
			Phasor a(0.0, 0.0);
			Phasor b(42.53, -0.19);
			Complex c(25.31, 47.74);
			a = b - c;
			Assert::AreEqual(58.15, a.getMagnitude(), 0.01);
			Assert::AreEqual(-1.28, a.getDirection(), 0.01);
		}
		TEST_METHOD(operatorPlusEqualComplex)
		{
			Phasor a(12.87, -1.39);
			Complex b(-2.41, 34.35);
			a += b;
			Assert::AreEqual(21.69, a.getMagnitude(), 0.01);
			Assert::AreEqual(1.57, a.getDirection(), 0.01);
		}
		TEST_METHOD(operatorMinusEqualComplex)
		{
			Phasor a(42.53, 1.42);
			Complex b(25.31, 47.74);
			a -= b;
			Assert::AreEqual(19.76, a.getMagnitude(), 0.01);
			Assert::AreEqual(-2.85, a.getDirection(), 0.01);
		}
		TEST_METHOD(operatorEqualPhasorComplexEqual)
		{
			Phasor a(59.121578125080525, 1.1284060131957678);
			Complex b(25.31, 53.43);
			Assert::IsTrue(a == b);
		}
		TEST_METHOD(operatorEqualPhasorComplexNotEqual)
		{
			Phasor a(95.73, 0.43);
			Complex b(-31.21, 53.43);
			Assert::IsFalse(a == b);
		}
	};
}
