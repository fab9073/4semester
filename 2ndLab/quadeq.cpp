#include "quadeq.hpp"


Coeffs::Coeffs(int count)
{
	countOfCoeffs = count;
	coeff = new double[count];
}

void processString(string& str)
{
	int charCounter = 0;
	while (str[charCounter] != '=')
	{
		if (str[charCounter] != '-' && str[charCounter] != '.' && !(str[charCounter] >= '0' && str[charCounter] <= '9'))
		{
			if (str[charCounter] == '^')
			{
				str[charCounter] = ' ';
				charCounter++;
			}
			str[charCounter] = ' ';
		}
		charCounter++;
	}
	str[charCounter] = ' ';
	str[charCounter + 1] = ' ';
}

void Coeffs::parseCoeffs(ifstream& filestream)
{
	string str;
	filestream >> str;
	processString(str);
	stringstream stream(str);

	stream >> coeff[A] >> coeff[B] >> coeff[C];
}

void Coeffs::parseCoeffs(string equality) 
{
	processString(equality);
	stringstream stream(equality);

	stream >> coeff[A] >> coeff[B] >> coeff[C];
}

QuadEq::QuadEq()
{
	abc = new Coeffs(quadEq);
	discriminant = abc->coeff[B] * abc->coeff[B] - 4 * abc->coeff[A] * abc->coeff[C];
}

void QuadEq::setQuadEq(ifstream& filestream)
{
	abc->parseCoeffs(filestream);
	discriminant = abc->coeff[B] * abc->coeff[B] - 4 * abc->coeff[A] * abc->coeff[C];
}

void QuadEq::setQuadEq(string equality)
{
	abc->parseCoeffs(equality);
	discriminant = abc->coeff[B] * abc->coeff[B] - 4 * abc->coeff[A] * abc->coeff[C];
}

string QuadEq::getQuadEq() 
{
	ostringstream streamIntoString;

	if (abc->coeff[A] != 0)	
		streamIntoString << abc->coeff[A] << "x^2";

	if (abc->coeff[B] < 0) 	
		streamIntoString << "-" << fabs(abc->coeff[B]) << "x";
	else if (abc->coeff[B] > 0) 
		streamIntoString << "+" << abc->coeff[B] << "x";

	if (abc->coeff[C] < 0) 
		streamIntoString << "-" << fabs(abc->coeff[C]);
	else if (abc->coeff[C] > 0)
		streamIntoString << "+" << abc->coeff[C];

	streamIntoString << "=0";

	return streamIntoString.str();
}

int QuadEq::checkDiscriminant()
{
	if (discriminant < 0)
		return zeroSols;
	else
		return discriminant > 0 ? twoSols : oneSol;
}

void QuadEq::solveQuadEq()
{
	int caseDis = checkDiscriminant();
	if (caseDis == oneSol)
	{
		solution = new double(-abc->coeff[B] / (2 * abc->coeff[A]));
	}
	else if (caseDis == twoSols)
	{
		solution = new double[twoSols];
		solution[0] = (-abc->coeff[B] + sqrt(discriminant)) / (2 * abc->coeff[A]);
		solution[1] = (-abc->coeff[B] - sqrt(discriminant)) / (2 * abc->coeff[A]);
	}
}

string QuadEq::getQuadEqSol() {
	ostringstream streamIntoString;
	if (checkDiscriminant() == zeroSols)
	{
		streamIntoString << "No Solutions";
	}
	else if (checkDiscriminant() == oneSol)
	{
		streamIntoString << "x = " << solution[0];
	}
	else if (checkDiscriminant() == twoSols)
	{
		streamIntoString << "x1 = " << solution[0] << endl << "x2 = " << solution[1];
	}
	return streamIntoString.str();
}
