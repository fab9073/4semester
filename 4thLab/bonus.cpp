#include "bonus.hpp"


void TBonus::DrawObj() {
	float x0;
	float y0;
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 0.75, 0);
	float cnt = 100;
	float alpha = 3.1415926f * 2.0f / cnt;
	for (int i = -1; i < cnt; i++) {
		x0 = (float)sin((double)alpha * (double)i) * radius;
		y0 = (float)cos((double)alpha * (double)i) * radius;
		glVertex2f(x0 + x, y0 + y);
	}
	glEnd();
}