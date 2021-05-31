#include "arkanoid.hpp"


void ArkanoidGame::InitBricks() {
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
};

void ArkanoidGame::InitLifes() {
	for (int k = 0; k < 3; k++) {
		lifes.push_back(new TBall(-1.1f - k * 0.1f, 0.9f));
	}
}

ArkanoidGame::ArkanoidGame() {
	ballz.push_back(new TBall(0.0f, -0.9f));
	InitBricks();
	InitLifes();
}


void ArkanoidGame::MoveBallz() {
	BallzCollision();
	for (size_t i = 0; i < ballz.size(); i++) {
		ballz[i]->DrawObj();
		if (ballz[i]->Move(carriage, bricks, bonuses, score)) {
			if (ballz.size() == 2) {
				delete ballz[i];
				ballz.erase(ballz.begin() + i);
			}
			else {
				if (!lifes.empty()) {
					score -= 10;
					lifes.pop_back();
					delete ballz[i];
					ballz.erase(ballz.begin() + i);
					ballz.push_back(new TBall(carriage.getX(), carriage.getY() + 0.1f));
				}
				else exit(1);
			}
		}
	}
}

void ArkanoidGame::MoveCarriage() {
	carriage.DrawObj();
	carriage.Move('A', 'D', -1.0f, 1.0f);
}

void ArkanoidGame::MoveBonuses() {
	for (size_t i = 0; i < bonuses.size(); i++) {
		bonuses[i]->DrawObj();
		if (bonuses[i]->Move(carriage, bricks, ballz, score)) {
			delete bonuses[i];
			bonuses.erase(bonuses.begin() + i);
		}
	}
}

void ArkanoidGame::DrawLifes() {
	std::vector<TBall*>::iterator it = lifes.begin();
	for (; it != lifes.end(); it++) {
		(*it)->DrawObj();
	}
}

void ArkanoidGame::DrawBricks() {
	std::vector<TBrick*>::iterator it = bricks.begin();
	for (; it != bricks.end(); it++) {
		(*it)->DrawObj();
		(*it)->Move();
	}
}

void ArkanoidGame::BallzCollision() {
	if (ballz.size() == 2) {
		if (ballz[0]->IsCrossPoint(ballz[1]->getX(), ballz[1]->getY(), 2 * ballz[1]->getRadius())) {
			ballz[0]->Mirror(ballz[1]->getX(), ballz[1]->getY());
			ballz[1]->Mirror(ballz[0]->getX(), ballz[0]->getY());
		}
	}
}

void ArkanoidGame::DrawFrames() {
	glBegin(GGL_STRING);
	glColor3f(1, 1, 1);
	glVertex2f(-1, -1);
	glVertex2f(-1, 1);
	glVertex2f(1, 1);
	glVertex2f(1, -1);
	glEnd();

}


static void Line1(float x1, float y1, float x2, float y2) {
	glVertex2f(x1 / 4 - 1.22f, y1 / 4 + 0.6f);
	glVertex2f(x2 / 4 - 1.22f, y2 / 4 + 0.6f);
}

static void Line2(float x1, float y1, float x2, float y2) {
	glVertex2f(x1 / 4 - 1.37f, y1 / 4 + 0.6f);
	glVertex2f(x2 / 4 - 1.37f, y2 / 4 + 0.6f);
}

static void Line3(float x1, float y1, float x2, float y2) {
	glVertex2f(x1 / 4 - 1.52f, y1 / 4 + 0.6f);
	glVertex2f(x2 / 4 - 1.52f, y2 / 4 + 0.6f);
}

void ArkanoidGame::ShowScore() {
	int score1 = score % 10;
	int score10 = (score / 10) % 10;
	int score100 = (score / 100) % 10;
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
	if (score > 9) {
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
	if (score > 99) {
		glBegin(GL_LINES);
		if ((score100 != 1) && (score100 != 4)) Line3(0.3f, 0.85f, 0.7f, 0.85f);
		if ((score100 != 0) && (score100 != 1) && (score100 != 7)) Line3(0.3f, 0.5f, 0.7f, 0.5f);
		if ((score100 != 1) && (score100 != 4) && (score100 != 7)) Line3(0.3f, 0.15f, 0.7f, 0.15f);

		if ((score100 != 5) && (score100 != 6)) Line3(0.7f, 0.5f, 0.7f, 0.85f);
		if ((score100 != 2)) Line3(0.7f, 0.5f, 0.7f, 0.15f);

		if ((score100 != 1) && (score100 != 2) && (score100 != 3) && (score100 != 7)) Line3(0.3f, 0.5f, 0.3f, 0.85f);
		if ((score100 == 0) || (score100 == 2) || (score100 == 6) || (score100 == 8)) Line3(0.3f, 0.5f, 0.3f, 0.15f);
		glEnd();
	}

}