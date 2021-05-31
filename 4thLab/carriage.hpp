#pragma once
#include <windows.h>
#include <gl/gl.h>
#include <math.h>

class TCarriage {
	const float dx = 0.05f;
	float x;
	float y;
	float length = 0.2f;
public:
	TCarriage() { x = 0; y = -0.95f; }

	void DrawObj();
	void Move(char left, char right, float borderL, float borderR);

	float getX() { return x; }
	float getY() { return y; }
	float getLength() { return length; }
};

