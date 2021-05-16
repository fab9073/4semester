#pragma once
#include <windows.h>
#include <gl/gl.h>
#include <math.h>
//#include "ball.hpp"
#include <vector>


class TBall;

class TBrick {
protected:
	float x;
	float y;
	const float height = 0.1f, width = 0.1f;
	int lifes = 3;
public:
	TBrick(float brickX, float brickY);
	virtual void DrawObj();

	virtual void Move() {}

	float getX() { return x; }
	float getY() { return y; }
	float getHeight() { return height; }
	float getWidth() { return width; }
	virtual bool XtraPower(TBall& ball);

};


class TBrickUnbrkbl : public TBrick {
public:
	TBrickUnbrkbl(float brickX, float brickY) : TBrick(brickX, brickY) {}
	virtual void DrawObj();

	virtual bool XtraPower(TBall& ball) { return false; }
};

class TBrickSpeedup : public TBrick {
public:
	TBrickSpeedup(float brickX, float brickY) : TBrick(brickX, brickY) {}
	virtual void DrawObj();

	virtual bool XtraPower(TBall& ball);

};

class TBrickFlying : public TBrick {
	float dx, dy;
public:
	TBrickFlying() : TBrick(-0.6f, -0.6f) { dx = 0.001f, dy = 0.01f; }
	void Move();


};