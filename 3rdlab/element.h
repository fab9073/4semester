#pragma once
#include <vector>
#include <gl/GL.h>
#include "palette.h"
#pragma comment(lib, "opengl32.lib")


enum isCases {
	SELECT, CHECKED
};

struct xy {
	int x, y;
};

class Element {
public:
	std::vector<bool> is = { false, false };
	virtual void DrawElement() = 0;
	virtual void DrawFrame() = 0;

	virtual color GetColor() = 0;
	virtual void reColor() = 0;
	virtual void reColor(color forChange) = 0;

	virtual void UseBonus(GameField* map, std::shared_ptr<Element>& cell, xy pos) = 0;
};
