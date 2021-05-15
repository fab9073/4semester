#pragma once
#include <windows.h>
#include <gl/gl.h>
#include <math.h>

class TBrick {
	float x;
	float y;
	const float height = 0.1f, width = 0.1f;

public:
	TBrick(float brickX, float brickY);
	void DrawObj();

	float getX() { return x; }
	float getY() { return y; }
	float getHeight() { return height; }
	float getWidth() { return width; }
};