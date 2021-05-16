#pragma once
#include <windows.h>
#include <gl/gl.h>
#include <math.h>
#include "carriage.hpp"
#include "bricks.hpp"
#include "bonus.hpp"
#include <vector>


#pragma comment(lib, "opengl32.lib")

class TBrick;

class TBall {
	const float radius = 0.05f;
	float x;
	float y;
	float dx = 0.01f;
	float dy = 0.01f;
public:
	TBall();
	TBall(float x1, float y1);
	void DrawObj();
	void setdx(float K);
	void setdy(float K);


	bool CarriageCollision(TCarriage carriage);
	bool BrickCollision(TBrick& brick);
	void DestroyBricks(std::vector <TBrick*>& bricks, std::vector<TBonus*>& bonuses);
	bool Move(TCarriage carriage);
	
};