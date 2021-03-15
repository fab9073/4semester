#pragma once
#include <iostream>
#include <cmath>
using namespace std;

int const quadEq = 3;

enum countSols {
	zeroSols,
	oneSol,
	twoSols
};

enum coef {
	A, B, C
};

class Coeffs {
public:
	double* coeff;
	int countOfCoeffs;

	Coeffs();
	Coeffs(int count);

	void setCoeffs();
	void printCoeffs();
};

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
