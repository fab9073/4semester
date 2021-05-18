#pragma once
#include "coeffs.hpp"

class QuadEq {
public:
	QuadEq();

	void FullSolvingQuadraticalEquation();

private:
	Coeffs* abc;
	double* solution;
	double discriminant;

	void calcDiscriminant();

	int checkDiscriminant();

	void calcSolQuadEq(int caseDis);
	void solveQuadEq();

	void printQuadEq();
	void getQuadEqSol();

};