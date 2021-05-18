#include "quadeq.hpp"

QuadEq::QuadEq()
{
	abc = new Coeffs(3);
	abc->setCoeffs();
	discriminant = 0;
	solution = nullptr;
}

void QuadEq::calcDiscriminant() { discriminant = abc->coeff[B] * abc->coeff[B] - 4 * abc->coeff[A] * abc->coeff[C]; }

int QuadEq::checkDiscriminant()
{
	if (discriminant < 0)
		return zeroSols;
	else
		return discriminant > 0 ? twoSols : oneSol;
}

void QuadEq::calcSolQuadEq(int caseDis) {
	if (caseDis == zeroSols) { std::cout << "There is no real solutions of quadratic equality" << std::endl; }
	if (caseDis == oneSol) {
		solution = new double(-abc->coeff[B] / (2 * abc->coeff[A]));
	}
	else if (caseDis == twoSols) {
		solution = new double[twoSols];
		solution[0] = (-abc->coeff[B] + sqrt(discriminant)) / (2 * abc->coeff[A]);
		solution[1] = (-abc->coeff[B] - sqrt(discriminant)) / (2 * abc->coeff[A]);
	}
}

void QuadEq::solveQuadEq() { calcSolQuadEq(checkDiscriminant()); }

void QuadEq::printQuadEq() {
	cout << "Entered Quadratic Equality:" << endl;
	if (abc->coeff[A] != 0)	cout << abc->coeff[A] << "x^2";

	if (abc->coeff[B] < 0) 	cout << " - " << fabs(abc->coeff[B]) << "x";
	else if (abc->coeff[B] > 0) cout << " + " << abc->coeff[B] << "x";

	if (abc->coeff[C] < 0) cout << " - " << fabs(abc->coeff[C]);
	else if (abc->coeff[C] > 0) cout << " + " << abc->coeff[C];

	cout << " = 0" << endl << endl;
}

void QuadEq::getQuadEqSol() {
	if (checkDiscriminant() == zeroSols) {
		return;
	}
	else if (checkDiscriminant() == oneSol) {
		cout << "Solution of Quadratic Equaliation:" << endl << "x = " << solution[0] << endl << endl;
	}
	else if (checkDiscriminant() == twoSols) {
		cout << "Solutions of Quadratic Equaliation:" << endl << "x1 = " << solution[0] << endl << "x2 = " << solution[1] << endl << endl;
	}
}

void QuadEq::FullSolvingQuadraticalEquation() { printQuadEq(); calcDiscriminant(); solveQuadEq(); getQuadEqSol(); }
