#include "gem.h"

const int FromRed = 2;
const int SixColors = 6;



Gem::Gem() {
	gemColor = palette[FromRed + rand() % (SixColors)];
}

Gem::Gem (color newcolor) {
	gemColor = newcolor;
}

void Gem::reColor(color forChange) {
	gemColor = forChange;
}

void Gem::DrawElement() {
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 1, 1);
	glVertex2f(0.1f, 0.6f);
	glVertex2f(0.25f, 0.8f);
	glVertex2f(0.3f, 0.8f);
	glVertex2f(0.4f, 0.6f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(gemColor.r, gemColor.g, gemColor.b);
	glVertex2f(0.3f, 0.8f);
	glVertex2f(0.4f, 0.6f);
	glVertex2f(0.6f, 0.6f);
	glVertex2f(0.7f, 0.8f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.75f * gemColor.r, 0.75f * gemColor.g, 0.75f * gemColor.b);
	glVertex2f(0.6f, 0.6f);
	glVertex2f(0.7f, 0.8f);
	glVertex2f(0.75f, 0.8f);
	glVertex2f(0.9f, 0.6f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(gemColor.r, gemColor.g, gemColor.b);
	glVertex2f(0.1f, 0.6f);
	glVertex2f(0.4f, 0.6f);
	glVertex2f(0.5f, 0.1f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.75f * gemColor.r, 0.75f * gemColor.g, 0.75f * gemColor.b);
	glVertex2f(0.4f, 0.6f);
	glVertex2f(0.6f, 0.6f);
	glVertex2f(0.5f, 0.1f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.5f * gemColor.r, 0.5f * gemColor.g, 0.5f * gemColor.b);
	glVertex2f(0.6f, 0.6f);
	glVertex2f(0.9f, 0.6f);
	glVertex2f(0.5f, 0.1f);
	glEnd();
}

void Gem::DrawFrame() {
	glLineWidth(2);
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0f, 0.6f, 0.0f);
	glVertex2f(0.5f, 0.1f);
	glVertex2f(0.1f, 0.6f);
	glVertex2f(0.25f, 0.8f);
	glVertex2f(0.75f, 0.8f);
	glVertex2f(0.9f, 0.6f);
	glVertex2f(0.5f, 0.1f);
	glEnd();
}

color Gem::GetColor() { return gemColor; }

void Gem::reColor() { gemColor = palette[FromRed + rand() % (SixColors)]; }

void Gem::UseBonus(GameField* map, std::shared_ptr<Element>& cell, xy pos) {}