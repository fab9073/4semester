#pragma once
#include "ball.hpp"
#include "carriage.hpp"
#include "bricks.hpp"
#include <vector>

const int windowW = 768;
const int windowH = 512;

class ArkanoidGame {
	std::vector<TBall*> ballz;
	std::vector<TBall*> lifes;

	TCarriage carriage;
	std::vector <TBrick*> bricks;
	std::vector <TBonus*> bonuses;
	int score = 0;
public:

	void InitBricks();
	void InitLifes();

	ArkanoidGame();

	void MoveBallz();
	void MoveCarriage();
	void MoveBonuses();

	void BallzCollision();

	void DrawFrames();
	void DrawBricks();
	void DrawLifes();
	//void MoveBricks();


	void ShowScore();
};