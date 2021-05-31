#include "carriage.hpp"

void TCarriage::DrawObj()
{
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 1, 1);
	glVertex2f(x - length, y);
	glVertex2f(x - length, y + 0.01f);
	glVertex2f(x, y + 0.025f);
	glVertex2f(x + length, y + 0.01f);
	glVertex2f(x + length, y);
	glEnd();
}

void TCarriage::Move(char left, char right, float borderL, float borderR)
{
	if (GetKeyState(left) < 0) x -= dx;
	else if (GetKeyState(right) < 0) x += dx;

	if (x - length < borderL) x = borderL + length;
	if (x + length > borderR) x = borderR - length;
}