#include "coeffs.hpp"

Coeffs::Coeffs() {}
Coeffs::Coeffs(int count) { countOfCoeffs = count; coeff = new double[count]; }

void Coeffs::setCoeffs() {
	std::cout << "Please, enter " << countOfCoeffs << " coefficents." << std::endl;
	std::cout << "First coefficient refers to the highest degree of the polynomial." << std::endl;
	for (int i = 0; i < countOfCoeffs; i++) {
		std::cout << "Enter " << i + 1 << " coefficient: ";
		std::cin >> coeff[i];
	}
	std::cout << std::endl;
}

void Coeffs::printCoeffs() {
	std::cout << "Entered coefficents:" << std::endl;
	for (int i = 0; i < countOfCoeffs; i++) {
		std::cout << coeff[i] << std::endl;
	}
}

