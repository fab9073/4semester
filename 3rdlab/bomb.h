#include "gamefield.h"
#include "element.h"
#include "gem.h"

class Bomb : public Element {
public:

	void DrawElement();
	void DrawFrame();

	color GetColor();
	void reColor();
	void reColor(color forChange);

	void UseBonus(GameField* map, std::shared_ptr<Element>& cell, xy pos);
};