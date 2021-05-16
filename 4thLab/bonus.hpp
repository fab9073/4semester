#pragma once
#include <windows.h>
#include <gl/gl.h>
#include <math.h>
//#include "ball.hpp"

#pragma comment(lib, "opengl32.lib")

class TBonus {
	float x, y;
	float dy = 0.005f;
	float radius = 0.05f;
public:
	TBonus(float x0, float y0) { x = x0; y = y0; }
	float getY() { return y; }
	float getX() { return x; }
	float getRadius() { return radius; }
	void DrawObj();
	void Move() { y -= dy; }
};