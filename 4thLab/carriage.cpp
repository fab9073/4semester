#include "carriage.hpp"


TCarriage::TCarriage() { x = 0; y = -0.95f; }

void TCarriage::DrawObj() 
{
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex2f(x - length, y);
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
