#pragma once
#include <windows.h>
#include <gl/gl.h>
#include <math.h>
#include <vector>
#define _USE_MATH_DEFINES

#pragma comment(lib, "opengl32.lib")

class TCarriage;
class TBrick;
class TBonus;

class TBall {
protected:
	const float radius = 0.05f;
	float x;
	float y;
	float speedcomp = 0.01f;
	float dx = speedcomp;
	float dy = speedcomp;

	bool IsCrossLine(float x1, float y1, float x2, float y2);
	bool ReflectCarriage(TCarriage& carriage);
	bool ReflectBricks(std::vector<TBrick*>& bricks, std::vector<TBonus*>& bonuses, int& score);

public:
	TBall(float x1, float y1) { x = x1; y = y1; }

	bool IsCrossPoint(float x1, float y1, float r);
	void Mirror(float x1, float y1);

	virtual void DrawObj();

	bool Move(TCarriage& carriage, std::vector<TBrick*>& bricks, std::vector<TBonus*>& bonuses, int& score);

	void multSpeed(float mult) { speedcomp *= mult; }

	float getX() { return x; }
	float getY() { return y; }
	float getRadius() { return radius; }
};

class TBonus : public TBall {
	float ddy = -0.0001f;
	float dy = -0.001f;
public:
	TBonus(float x1, float y1) : TBall(x1, y1) {}

	virtual void DrawObj();

	bool Move(TCarriage& carriage, std::vector<TBrick*>& bricks, std::vector<TBall*>& ballz, int& score);

};