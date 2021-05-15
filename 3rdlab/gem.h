#pragma once
#include <vector>
#include <windows.h>
#include <gl/gl.h>
#include <memory>
#include "element.h"
#include "palette.h"
#include "gamefield.h"

#pragma comment(lib, "opengl32.lib")



class Gem : public Element {
	color gemColor;
public:
	Gem();
	Gem(color newcolor);

	void DrawElement();
    void DrawFrame();

    color GetColor();
	void reColor();
	void reColor(color forChange);

	void UseBonus(GameField* map, std::shared_ptr<Element>& cell, xy pos);
};
