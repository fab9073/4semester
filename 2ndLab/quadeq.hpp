#pragma once
#include <fstream>
#include <string> 
#include <sstream>
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
	double* coeff = nullptr;
	int countOfCoeffs = 0;

	Coeffs(int count);

	void parseCoeffs(ifstream& filestream);
	void parseCoeffs(string coeffs);
};

class QuadEq {
public:

	QuadEq();

	void setQuadEq(ifstream& filestream);
	void setQuadEq(string equality);
	string getQuadEq() const;
	string getQuadEqSol();

	void solveQuadEq();

private:
	Coeffs* abc = nullptr;
	double* solution = nullptr;
	double discriminant;

	int checkDiscriminant() const;
};
