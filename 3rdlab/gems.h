#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <queue>
#include <windows.h>
#include <gl/gl.h>
#include <memory>
#include <math.h>

#pragma comment(lib, "opengl32.lib")

const int mapW = 9;
const int mapH = 9;

struct color {
	float r, g, b;
};

enum isCases {
	SELECT, CHECKED
};

class Element {
public:
	std::vector<bool> is = { false, false };
	virtual void DrawElement() = 0;
	virtual void DrawFrame() = 0;
	virtual color getColor() = 0;
	virtual void reColor() = 0;
	virtual void reColor(color newColor) = 0;

	virtual bool isExplosion() = 0;
	virtual bool isReColor() = 0;
};


class Gem : public Element {
	color gemColor;
public:
	Gem();
	Gem(color newColor);

	color getColor();
	void DrawFrame();
	void reColor();
	void reColor(color newColor);
	void DrawElement();

	bool isExplosion();
	bool isReColor();
};

class Bomb : public Element {
public:
	void DrawElement();
	void DrawFrame();
	color getColor();
	void reColor();
	void reColor(color newColor);

	bool isExplosion();
	bool isReColor();
};

class ReColor : public Element {
	color prevColor;
public:
	ReColor(color prev);

	void DrawElement();

	void DrawFrame();
	color getColor();
	void reColor();
	void reColor(color newColor);

	bool isExplosion();
	bool isReColor();
};

struct xy {
	int x, y;
};

class GameField {
public:
	std::shared_ptr<Element>** cell;

	GameField(int mapH, int mapW);

	void drawField();

	void swapGems();

	void BonusReColor();
	void BlowUP();

	void SmashOut(xy position);
	void UpDownLeftRight(xy startpos, std::vector<xy>& positions, color rgb);
	void CheckCombinations();
};
