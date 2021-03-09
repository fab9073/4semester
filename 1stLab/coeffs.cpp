#include <../../coeffs.hpp>


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

void Coeffs::getCoeffs() {
	cout << "Entered coefficents:" << endl;
	for (int i = 0; i < countOfCoeffs; i++) {
		cout << coeff[i] << endl;
	}
}

void QuadEq::calcDiscriminant() { discriminant = coeff[1] * coeff[1] - 4 * coeff[0] * coeff[2]; }

int QuadEq::checkDiscriminant() { if (discriminant < 0) return ZERO_SOLS; else return discriminant > 0 ? TWO_SOLS : ONE_SOL; }

void QuadEq::calcSolQuadEq(int caseDis) {
	if (caseDis == ZERO_SOLS) { cout << "There is no real solutions of quadratic equality" << endl; }
	if (caseDis == ONE_SOL) {
		solution = new double(-coeff[1] / (2 * coeff[0]));
	}
	else if (caseDis == TWO_SOLS) {
		solution = new double[TWO_SOLS];
		solution[0] = (-coeff[1] + sqrt(discriminant)) / (2 * coeff[0]);
		solution[1] = (-coeff[1] - sqrt(discriminant)) / (2 * coeff[0]);
	}
}

void QuadEq::solveQuadEq() { calcSolQuadEq(checkDiscriminant()); }

void QuadEq::getQuadEq() {
	cout << "Entered Quadratic Equality:" << endl;
	if (coeff[0] != 0)	cout << coeff[0] << "x^2";

	if (coeff[1] < 0) 	cout << " - " << fabs(coeff[1]) << "x";
	else if (coeff[1] > 0) cout << " + " << coeff[1] << "x";

	if (coeff[2] < 0) cout << " - " << fabs(coeff[2]);
	else if (coeff[2] > 0) cout << " + " << coeff[2];

	cout << " = 0" << endl << endl;
}

void QuadEq::getQuadEqSol() {
	if (checkDiscriminant() == ZERO_SOLS) {
		return;
	}
	else if (checkDiscriminant() == ONE_SOL) {
		cout << "Solution of Quadratic Equaliation:" << endl << "x = " << solution[0] << endl << endl;
	}
	else if (checkDiscriminant() == TWO_SOLS) {
		cout << "Solutions of Quadratic Equaliation:" << endl << "x1 = " << solution[0] << endl << "x2 = " << solution[1] << endl << endl;
	}
}

QuadEq::QuadEq() : Coeffs(QUAD_EQ) { setCoeffs(); discriminant = 0; solution = nullptr; }

void QuadEq::FullSolvingQuadraticalEquation() { getQuadEq(); calcDiscriminant(); solveQuadEq(); getQuadEqSol(); }
