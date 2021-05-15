#pragma once
#include "gamefield.h"
#include "element.h"
#include "gem.h"

class ReColor : public Element {
	color prevColor;
public:
	ReColor(color forPrev);

	void DrawElement();
	void DrawFrame();

	color GetColor();
	void reColor();
	void reColor(color forChange);



	void UseBonus(GameField* map, std::shared_ptr<Element>& cell, xy pos);
};