#pragma once
#include "quadeq.hpp"
#include <stack>
#include <vector>
#include <map>
#include <iterator>
#include <fstream>
#include <string> 
#include <iostream>


struct Letter
{
private:
	string quadEq;
	string solution;
	string name;
public:
	string getQuadEq() const;
	string getSolution() const;
	string getName() const;

	void setLetter(string equality, string sol, string studname);
	void printLetter() const;
};

enum studClassificator 
{
	studGood = 1,
	studBad,
	studUgly
};

class Student
{
protected:
	Student() {}
private:
	string name;
public:
	Student(string studname);

	virtual Letter solveEq(QuadEq equality) = 0;
	string getName() const;
};

class TheGood : virtual public Student
{
protected:
	TheGood() {}
public:
	TheGood(string studname) : Student(studname) {}
	Letter solveEq(QuadEq equality);
};

class TheBad : virtual public Student 
{
protected:
	TheBad() {}
public:
	TheBad(string studname) : Student(studname) {}
	Letter solveEq(QuadEq equality);
};

class TheUgly : public TheGood, public TheBad 
{
public:
	TheUgly(string studname) : Student(studname) {}
	Letter solveEq(QuadEq equality);
};

class Teacher 
{
public:

	void StartExam(string tasks, vector <Student*>& studGroup, stack <Letter>& LetterStack) const;
	void checkLetter(Letter studLetter, map <string, int>& ReportMap) const;

	void createReport(stack <Letter>& LetterStack, map <string, int>& ReportMap) const;

	void printReport(map <string, int>& ReportMap) const;
	void printReport(string filenameReport, map <string, int>& ReportMap) const;

};
