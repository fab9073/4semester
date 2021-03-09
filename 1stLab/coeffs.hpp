#pragma once
#include <iostream>
#include <cmath>
using namespace std;

#define QUAD_EQ 3
#define TWO_SOLS 2
#define ONE_SOL 1
#define ZERO_SOLS 0

class Coeffs {
protected:
	double* coeff;
	int countOfCoeffs;

	Coeffs(int count);

	void setCoeffs();
	void getCoeffs();
};

class QuadEq : public Coeffs {
private:
	double* solution;
	double discriminant;

	void calcDiscriminant();

	int checkDiscriminant();

	void calcSolQuadEq(int caseDis);
	void solveQuadEq();

	void getQuadEq();
	void getQuadEqSol();

public:
	QuadEq();

	void FullSolvingQuadraticalEquation();
};