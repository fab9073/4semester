#pragma once
#pragma once
#include <iostream>
#include <cmath>

using std::endl;
using std::cout;
using std::cin;

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

