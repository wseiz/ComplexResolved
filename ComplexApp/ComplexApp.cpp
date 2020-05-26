// ComplexApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "../ComplexLib/Complex.h"

void display(Complex const& complex)
{
    std::cout << std::endl;
    std::cout << "Liczba zespolona to: (";
    std::cout << complex.getReal();
    std::cout << ",";
    std::cout << complex.getImaginary();
    std::cout << ")";
    std::cout << std::endl;
    std::cout << "moduł: ";
    std::cout << complex.magnitude();
    std::cout << std::endl;
    std::cout << "kąt: ";
    std::cout << complex.direction();
    std::cout << std::endl;
}

int main()
{
    setlocale(LC_ALL, "pl-pl");

    double real, imaginary;
    std::cout << "Podaj wartość części rzeczywistej:";
    std::cin >> real;
    std::cout << "Podaj wartość części urojonej:";
    std::cin >> imaginary;
    Complex complex1(real, imaginary);
    display(complex1);

    std::cout << std::endl;
    std::cout << "Podaj wartość części rzeczywistej:";
    std::cin >> real;
    std::cout << "Podaj wartość części urojonej:";
    std::cin >> imaginary;
    Complex complex2;
    complex2.setReal(real);
    complex2.setImaginary(imaginary);
    display(complex2);


    Complex sum;
    sum = complex1 + complex2;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Suma liczb: ";
    std::cout << std::endl;
    display(sum);

    double value;
    std::cout << std::endl;
    std::cout << "Podaj liczbę rzeczywistą: ";
    std::cin >> value;

    Complex sum2;
    sum2 = complex1 + value;
    std::cout << std::endl;
    std::cout << "Suma2: ";
    std::cout << std::endl;
    display(sum2);

    Complex substract;
    substract = complex1 - complex2;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Różnica liczb: ";
    std::cout << std::endl;
    display(substract);

    Complex substract2;
    substract2 = complex1 - value;
    std::cout << std::endl;
    std::cout << "Różnica2: ";
    std::cout << std::endl;
    display(substract2);
}

