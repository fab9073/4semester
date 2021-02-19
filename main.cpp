#include <iostream>
#include <math.h>
using namespace std;

class Coeffs {
protected:
	double a;
	double b;
	double c;

	Coeffs() {
		a = 0;
		b = 0;
		c = 0;
	}
	void setCoeffs() {
		cout << "Please, enter coefficents a, b, c:" << endl;
		cin >> a >> b >> c;
		cout << endl;
	}
	void getCoeffs() {
		cout << "Entered coefficents:" << endl;
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		cout << "c = " << c << endl << endl;
	}
};

class Discriminant : public Coeffs {
protected:
	double value;

	Discriminant() {
		value = 0;
	}
	void calcDiscriminant() {
		value = b * b - 4 * a * c;
	}
	bool checkDiscriminant() { return value < 0; }
	bool checkDiscriminant0() { return value == 0; }
};

class QuadEq : private Discriminant {
private:
	double* solution;

	void inline calcSolQuadEq(bool caseDis) {
		if (caseDis) {
			solution = new double(-b / (2 * a));
			return;
		}
		else {
			solution = new double[2];
			solution[0] = (-b + sqrt(value)) / (2 * a);
			solution[1] = (-b - sqrt(value)) / (2 * a);
		}
	}
	void setQuadEq() {
		setCoeffs();
	}
	void getQuadEq() {
		getCoeffs();
		cout << "Entered Quadratic Equality:" << endl;
		cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl << endl;
	}
	void solveQuadEq() {
		calcDiscriminant();
		if (checkDiscriminant()) {
			cout << "There is no real solutions" << endl << endl;
			return;
		}
		else {
			calcSolQuadEq(checkDiscriminant0());
		}
	}
	void getQuadEqSol() {
		if (checkDiscriminant()) {
			return;
		}
		else if (checkDiscriminant0()) {
			cout << "Solution of Quadratic Equaliation:" << endl << "x = " << solution[0] << endl << endl;
		}
		else {
			cout << "Solutions of Quadratic Equaliation:" << endl << "x1 = " << solution[0] << endl << "x2 = " << solution[1] << endl << endl;
		}
	}
public:
	QuadEq()
	{};
	void FullSolvingQuadraticalEquation() {
		setQuadEq();
		getQuadEq();
		solveQuadEq();
		getQuadEqSol();
	}
};

int main(void) {
	QuadEq(equality);
	equality.FullSolvingQuadraticalEquation();
}
