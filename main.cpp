#include <iostream>
#include <math.h>
using namespace std;

class Coeffs {
public:
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

class Discriminant {
public:
	double value;

	Discriminant() {
		value = 0;
	}
	void calcDiscriminant(Coeffs abc) {
		value = abc.b * abc.b - 4 * abc.a * abc.c;
	}
	bool checkDiscriminant() { return value < 0; }
	bool checkDiscriminant0() { return value == 0; }
};

class QuadEq : public Coeffs, public Discriminant {
private:
	Coeffs abc;
	Discriminant dis;
	double* solution;

	void inline calcSolQuadEq(bool caseDis) {
		if (caseDis) {
			solution = new double(-abc.b / (2 * abc.a));
			return;
		}
		else {
			solution = new double[2];
			solution[0] = (-abc.b + sqrt(dis.value)) / (2 * abc.a);
			solution[1] = (-abc.b - sqrt(dis.value)) / (2 * abc.a);
		}
	}
	void setQuadEq() {
		abc.setCoeffs();
	}
	void getQuadEq() {
		abc.getCoeffs();
		cout << "Entered Quadratic Equality:" << endl;
		cout << abc.a << "x^2 + " << abc.b << "x + " << abc.c << " = 0" << endl << endl;
	}
	void solveQuadEq() {
		dis.calcDiscriminant(abc);
		if (dis.checkDiscriminant()) {
			cout << "There is no real solutions" << endl << endl;
			return;
		}
		else {
			calcSolQuadEq(checkDiscriminant0());
		}
	}
	void getQuadEqSol() {
		if (dis.checkDiscriminant()) {
			return;
		}
		else if (dis.checkDiscriminant0()) {
			cout << "Solution of Quadratic Equaliation:" << endl << "x = " << solution[0] << endl << endl;
		}
		else {
			cout << "Solutions of Quadratic Equaliation:" << endl << "x1 = " << solution[0] << endl << "x2 = " << solution[1] << endl << endl;
		}
	}
public:
	void FullSolvingQuadraticalEquation() {
		setQuadEq();
		getQuadEq();
		solveQuadEq();
		getQuadEqSol();
	}
};

int main(void) {
	QuadEq equality;
	equality.FullSolvingQuadraticalEquation();
}
