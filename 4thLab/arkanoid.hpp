#pragma once
#include "carriage.hpp"
#include "ball.hpp"
#include "bricks.hpp"
#include "bonus.hpp"
#include <vector>

const int windowW = 768;
const int windowH = 512;

class Arkanoid {
public:
	TBall ball;
	TBall* bonusBall = nullptr;
	TCarriage carriage;
	std::vector<TBall*> lifes;
	std::vector <TBrick*> bricks;
	std::vector<TBonus*> bonuses;
	int score = 0;
	const int BonusBallChance = 2;

	Arkanoid();

	void DrawFrames();


	void DrawLifes();
	void InitLifes();
	void InitBricks();

	void DrawBricks();

	void MoveBricks();

	void DrawBonuses();

	void MoveBonuses();


	void ShowScore();
};