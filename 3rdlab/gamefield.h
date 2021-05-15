#pragma once
#include <vector>
#include <windows.h>
#include <gl/gl.h>
#include <memory>
#include "element.h"
#include "gem.h"
#include "recolor.h"
#include "bomb.h"
#include <algorithm>

#pragma comment(lib, "opengl32.lib")

const int mapW = 10;
const int mapH = 10;

class GameField {
public:
	std::vector<std::vector<std::shared_ptr<Element>>> cell;

	GameField(int mapH, int mapW);

	void DrawField();

	void SelectCell(int x, int y);

	void ReplaceElements();

	void CheckCombinations();
	void UpDownLeftRight(xy startpos, std::vector<xy>& positions, color rgb);
	void SmashOut(xy position);
	void SmashOutVector(std::vector<xy>& positions);

	void BonusesUsing();
};