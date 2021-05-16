#pragma once
#include "carriage.hpp"


TCarriage::TCarriage() { x = 0; y = -0.95f; }

void TCarriage::DrawObj() 
{
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 1, 1);
	glVertex2f(x - length, y);
	glVertex2f(x - length, y + 0.01f);
	glVertex2f(x + length, y + 0.01f);
	glVertex2f(x + length, y);
	glEnd();
}

bool TCarriage::TakeBonus(std::vector<TBonus*>& bonuses) {
	std::vector<TBonus*>::iterator it = bonuses.begin();
	for (; it != bonuses.end(); it++) {
		if (((*it)->getY() - (*it)->getRadius() + 0.01f > getY()
			&& (*it)->getY() - (*it)->getRadius() - 0.01f < getY()) &&
			((*it)->getX() > getX() - getLength() &&
				(*it)->getX() < getX() + getLength())) {
			delete (*it);
			bonuses.erase(it);
			return true;
		}
	}
	return false;
}

void TCarriage::Move(char left, char right, float borderL, float borderR)
{
	if (GetKeyState(left) < 0) x -= dx;
	else if (GetKeyState(right) < 0) x += dx;
	
	if (x - length < borderL) x = borderL + length;
	if (x + length > borderR) x = borderR - length;
}
