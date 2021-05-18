#pragma once
#pragma once
#include <iostream>
#include <cmath>

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

