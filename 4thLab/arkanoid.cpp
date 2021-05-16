#include "arkanoid.hpp"



Arkanoid::Arkanoid() {
	InitBricks();
	InitLifes();
	ball = new TBall();
}

void Arkanoid::DrawFrames() {
	glBegin(GGL_STRING);
	glColor3f(1, 1, 1);
	glVertex2f(-1, -1);
	glVertex2f(-1, 1);
	glVertex2f(1, 1);
	glVertex2f(1, -1);
	glEnd();
}


void Arkanoid::DrawLifes() {
	std::vector<TBall*>::iterator it = lifes.begin();
	for (; it != lifes.end(); it++) {
		(*it)->DrawObj();
	}
}
void Arkanoid::InitLifes() {
	for (int k = 0; k < 3; k++) {
		lifes.push_back(new TBall(-1.1f - k * 0.1f, 0.9f));
	}
}
void Arkanoid::InitBricks() {
	float startX = -0.9f;
	float startY = 0.8f;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == 2 && j > 1 && j < 8) {
				bricks.push_back(new TBrickUnbrkbl(startX + j * 0.2f, startY - i * 0.1f));
			}
			else if (j == 0 || j == 9) {
				bricks.push_back(new TBrickSpeedup(startX + j * 0.2f, startY - i * 0.1f));
			}
			else {
				bricks.push_back(new TBrick(startX + j * 0.2f, startY - i * 0.1f));
			}
		}
	}
}

void Arkanoid::DrawBricks() {
	std::vector<TBrick*>::iterator it = bricks.begin();
	for (; it != bricks.end(); it++) {
		(*it)->DrawObj();
	}
}

void Arkanoid::MoveBricks() {
	std::vector<TBrick*>::iterator it = bricks.begin();
	for (; it != bricks.end(); it++) {
		(*it)->Move();
	}
}

void Arkanoid::DrawBonuses() {
	std::vector<TBonus*>::iterator it = bonuses.begin();
	for (; it != bonuses.end(); it++) {
		(*it)->DrawObj();
	}
}

void Arkanoid::MoveBonuses() {
	std::vector<TBonus*>::iterator it = bonuses.begin();
	for (; it != bonuses.end(); it++) {
		(*it)->Move();
	}
}

void Line1(float x1, float y1, float x2, float y2) {
	glVertex2f(x1 / 4 - 1.3f, y1 / 4 + 0.6f);
	glVertex2f(x2 / 4 - 1.3f, y2 / 4 + 0.6f);
}

void Line2(float x1, float y1, float x2, float y2) {
	glVertex2f(x1 / 4 - 1.45f, y1 / 4 + 0.6f);
	glVertex2f(x2 / 4 - 1.45f, y2 / 4 + 0.6f);
}

void Arkanoid::ShowScore() {
	int score1 = score % 10;
	int score10 = (score / 10) % 10;
	glLineWidth(3);
	glColor3f(1, 1, 0);
	glBegin(GL_LINES);
	if ((score1 != 1) && (score1 != 4)) Line1(0.3f, 0.85f, 0.7f, 0.85f);
	if ((score1 != 0) && (score1 != 1) && (score1 != 7)) Line1(0.3f, 0.5f, 0.7f, 0.5f);
	if ((score1 != 1) && (score1 != 4) && (score1 != 7)) Line1(0.3f, 0.15f, 0.7f, 0.15f);

	if ((score1 != 5) && (score1 != 6)) Line1(0.7f, 0.5f, 0.7f, 0.85f);
	if ((score1 != 2)) Line1(0.7f, 0.5f, 0.7f, 0.15f);

	if ((score1 != 1) && (score1 != 2) && (score1 != 3) && (score1 != 7)) Line1(0.3f, 0.5f, 0.3f, 0.85f);
	if ((score1 == 0) || (score1 == 2) || (score1 == 6) || (score1 == 8)) Line1(0.3f, 0.5f, 0.3f, 0.15f);
	glEnd();

	glBegin(GL_LINES);
	if ((score10 != 1) && (score10 != 4)) Line2(0.3f, 0.85f, 0.7f, 0.85f);
	if ((score10 != 0) && (score10 != 1) && (score10 != 7)) Line2(0.3f, 0.5f, 0.7f, 0.5f);
	if ((score10 != 1) && (score10 != 4) && (score10 != 7)) Line2(0.3f, 0.15f, 0.7f, 0.15f);

	if ((score10 != 5) && (score10 != 6)) Line2(0.7f, 0.5f, 0.7f, 0.85f);
	if ((score10 != 2)) Line2(0.7f, 0.5f, 0.7f, 0.15f);

	if ((score10 != 1) && (score10 != 2) && (score10 != 3) && (score10 != 7)) Line2(0.3f, 0.5f, 0.3f, 0.85f);
	if ((score10 == 0) || (score10 == 2) || (score10 == 6) || (score10 == 8)) Line2(0.3f, 0.5f, 0.3f, 0.15f);
	glEnd();
}
