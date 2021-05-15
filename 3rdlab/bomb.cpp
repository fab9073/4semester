#include "bomb.h"

void Bomb::DrawElement() {
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.5f, 0.5f, 0.5f);
	float x, y;
	float cnt = 20;
	float r = 0.4f;
	float alpha = 3.1415926f * 2.0f / cnt;
	for (int i = -1; i < cnt; i++) {
		x = sin(alpha * i) * r;
		y = cos(alpha * i) * r;
		glVertex2f(x + 0.5f, y + 0.5f);
	}
	glColor3f(0, 0, 0);
	glPointSize(2);
	for (int i = -1; i < cnt; i++) {
		x = sin(alpha * i) * r;
		y = cos(alpha * i) * r;
		glVertex2f(x + 0.5f, y + 0.5f);
	}
	glEnd();
}
void Bomb::DrawFrame() {
	float x, y;
	float dot = 100;
	float r = 0.4f;
	float alpha = 3.1415926f * 2.0f / dot;
	glPointSize(2);
	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.6f, 0.0f);
	for (int i = -1; i < dot; i++) {
		x = sin(alpha * i) * r;
		y = cos(alpha * i) * r;
		glVertex2f(x + 0.5f, y + 0.5f);
	}
	glEnd();
}

color Bomb::GetColor() { return { 0,0,0 }; };
void Bomb::reColor() {}
void Bomb::reColor(color forChange) {}

void Bomb::UseBonus(GameField* map, std::shared_ptr<Element>& cell, xy pos) {
	cell->is[SELECT] = false;
	cell.reset();
	cell.reset(new Gem());
	map->SmashOut(pos);
	int x1, y1;
	for (int i = 0; i < 4; i++) {
		x1 = rand() % mapW;
		y1 = rand() % mapH;
		map->SmashOut({ x1, y1 });
	}
}

