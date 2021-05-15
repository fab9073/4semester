#include "recolor.h"


void ReColor::DrawElement() {
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 1, 1);
	float x, y;
	float cnt = 20;
	float r = 0.5f;
	float alpha = 3.1415926f * 2.0f / cnt;
	for (int i = -1; i < cnt; i++) {
		x = sin(alpha * i) * r;
		y = cos(alpha * i) * r;
		glVertex2f(x + 0.5f, y + 0.5f);
	}
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 1, 1);
	glVertex2f(0.1f, 0.6f);
	glVertex2f(0.25f, 0.8f);
	glVertex2f(0.3f, 0.8f);
	glVertex2f(0.4f, 0.6f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(prevColor.r, prevColor.g, prevColor.b);
	glVertex2f(0.3f, 0.8f);
	glVertex2f(0.4f, 0.6f);
	glVertex2f(0.6f, 0.6f);
	glVertex2f(0.7f, 0.8f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.75f * prevColor.r, 0.75f * prevColor.g, 0.75f * prevColor.b);
	glVertex2f(0.6f, 0.6f);
	glVertex2f(0.7f, 0.8f);
	glVertex2f(0.75f, 0.8f);
	glVertex2f(0.9f, 0.6f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(prevColor.r, prevColor.g, prevColor.b);
	glVertex2f(0.1f, 0.6f);
	glVertex2f(0.4f, 0.6f);
	glVertex2f(0.5f, 0.1f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.75f * prevColor.r, 0.75f * prevColor.g, 0.75f * prevColor.b);
	glVertex2f(0.4f, 0.6f);
	glVertex2f(0.6f, 0.6f);
	glVertex2f(0.5f, 0.1f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.5f * prevColor.r, 0.5f * prevColor.g, 0.5f * prevColor.b);
	glVertex2f(0.6f, 0.6f);
	glVertex2f(0.9f, 0.6f);
	glVertex2f(0.5f, 0.1f);
	glEnd();
}

void ReColor::DrawFrame() {
	float x, y;
	float dot = 100;
	float r = 0.5f;
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

color ReColor::GetColor() {
	return prevColor;

}

void ReColor::reColor() {
}

void ReColor::reColor(color forChange) {}


ReColor::ReColor(color forPrev) { prevColor = forPrev; }

void ReColor::UseBonus(GameField* map, std::shared_ptr<Element>& cell, xy pos) {
	cell->is[SELECT] = false;
	color forChange = cell->GetColor();
	cell.reset();
	cell.reset(new Gem(forChange));
	for (int i = 0; i < 2; i++) {
		int rng1 = 50, rng2 = 50;
		while (pos.x + rng1 >= mapW || pos.x + rng1 < 0 || pos.y + rng2 >= mapH || pos.y + rng2 < 0) {
			rng1 = 1 + rand() % 3;
			rng2 = 1 + rand() % 3;
			if (rand() % 2) {
				rng1 = -rng1;
			}
			if (rand() % 2) {
				rng2 = -rng2;
			}
		}
		map->cell[pos.x + rng1][pos.y + rng2]->reColor(forChange);
}