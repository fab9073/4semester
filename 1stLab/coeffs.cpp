#include "coeffs.hpp"

Coeffs::Coeffs() {}
Coeffs::Coeffs(int count) { countOfCoeffs = count; coeff = new double[count]; }

void Coeffs::setCoeffs() {
	cout << "Please, enter " << countOfCoeffs << " coefficents." << endl;
	cout << "First coefficient refers to the highest degree of the polynomial." << endl;
	for (int i = 0; i < countOfCoeffs; i++) {
		cout << "Enter " << i + 1 << " coefficient: ";
		cin >> coeff[i];
	}
	cout << endl;
}

void Coeffs::printCoeffs() {
	cout << "Entered coefficents:" << endl;
	for (int i = 0; i < countOfCoeffs; i++) {
		cout << coeff[i] << endl;
	}
}

