#pragma once
#include "ball.hpp"

TBall::TBall() { x = 0; y = -0.9f; }
TBall::TBall(float x1, float y1) { x = x1; y = y1; }

void TBall::DrawObj() {
	float x0;
	float y0;
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 1, 1);
	float cnt = 40;
	float alpha = 3.1415926f * 2.0f / cnt;
	for (int i = -1; i < cnt; i++) {
		x0 = (float)sin((double)alpha * (double)i) * radius;
		y0 = (float)cos((double)alpha * (double)i) * radius;
		glVertex2f(x0 + x, y0 + y);
	}
	glColor3f(0.5f, 0.5f, 0.5f);
	glPointSize(2);
	for (int i = -1; i < cnt; i++) {
		x0 = (float)sin((double)alpha * (double)i) * radius;
		y0 = (float)cos((double)alpha * (double)i) * radius;
		glVertex2f(x0 + x, y0 + y);
	}
	glEnd();
}

bool TBall::CarriageCollision(TCarriage carriage) {
	if ((y - radius + 0.01f > carriage.getY() 
		&& y - radius - 0.01f < carriage.getY()) &&
		(x > carriage.getX() - carriage.getLength() &&
			x < carriage.getX() + carriage.getLength())) {
		dy *= -1;
		return true;
	}
	return false;
}


bool TBall::BrickCollision(TBrick& brick, int& score) {
	if ((brick.getY() - 0.5f * brick.getHeight() - 0.01f < y + radius
		&& brick.getY() - 0.5f * brick.getHeight() + 0.01f > y + radius)
		|| (brick.getY() + 0.5f * brick.getHeight() - 0.01f < y - radius
		    && brick.getY() + 0.5f * brick.getHeight() + 0.01f > y - radius))
	{
		if ((x - radius <= brick.getX() - 0.5f * brick.getWidth() 
			&& x + radius >= brick.getX() - 0.5f * brick.getWidth()) 
			|| ((x - radius <= brick.getX() + 0.5f * brick.getWidth())
			   && x + radius >= brick.getX() + 0.5f * brick.getWidth()))
		{
			dy *= -1;
			score++;
			return brick.XtraPower(*this);
		}
	}
	if ((brick.getX() - 0.5f * brick.getWidth() - 0.01f < x + radius
		&& brick.getX() - 0.5f * brick.getWidth() + 0.01f > x + radius)
		|| (brick.getX() + 0.5f * brick.getWidth() - 0.01f < x - radius
			&& brick.getX() + 0.5f * brick.getWidth() + 0.01f > x - radius)) 
	{
		if ((y - radius <= brick.getY() - 0.5f * brick.getHeight()
			&& y + radius >= brick.getY() - 0.5f * brick.getHeight())
			|| ((y - radius <= brick.getY() + 0.5f * brick.getHeight())
				&& y + radius >= brick.getY() + 0.5f * brick.getHeight()))
		{ 
			dx *= -1;
			score++;
			return brick.XtraPower(*this);
		}
	}
	if ((x + radius + 0.001f > brick.getX() - 0.5f * brick.getWidth() && x + radius - 0.01f < brick.getX() - 0.5f * brick.getWidth()
		&&
		y - radius + 0.001f > brick.getY() + 0.5f * brick.getHeight() && y - radius + 0.01f < brick.getY() + 0.5f * brick.getHeight())
		||
		(x - radius + 0.001f > brick.getX() + 0.5f * brick.getWidth() && x - radius - 0.01f < brick.getX() + 0.5f * brick.getWidth()
			&&
			y - radius + 0.001f > brick.getY() + 0.5f * brick.getHeight() && y - radius + 0.01f < brick.getY() + 0.5f * brick.getHeight())
		||
		(x - radius + 0.001f > brick.getX() + 0.5f * brick.getWidth() && x - radius - 0.01f < brick.getX() + 0.5f * brick.getWidth()
			&&
			y + radius + 0.001f > brick.getY() - 0.5f * brick.getHeight() && y + radius - 0.01f < brick.getY() - 0.5f * brick.getHeight())
		||
		((x + radius + 0.001f > brick.getX() - 0.5f * brick.getWidth() && x + radius - 0.01f < brick.getX() - 0.5f * brick.getWidth()
			&&
			y + radius + 0.001f > brick.getY() - 0.5f * brick.getHeight() && y + radius - 0.01f < brick.getY() - 0.5f * brick.getHeight()))) {
		dx *= -1;
		dy *= -1;
		score++;
		return brick.XtraPower(*this);
	}
	return false;
}

const int bonusChance = 4;

void TBall::DestroyBricks(std::vector <TBrick*>& bricks, std::vector<TBonus*>& bonuses, int& score) {
	std::vector<TBrick*>::iterator it = bricks.begin();
	for (; it != bricks.end(); it++) {
		if (BrickCollision(**it, score)) {
			if (rand() % bonusChance == 1) {
				bonuses.push_back(new TBonus((*it)->getX(), (*it)->getY()));
			}
			bricks.erase(it);
			return;
		}
	}

}

bool TBall::Move(TCarriage carriage) {
	x += dx;
	y += dy;

	if (CarriageCollision(carriage)) {
		return false;
	}

	if (y < radius - 1) {
		dy *= -1;
		return true;
	}
	if (y > 1 - radius) {
		dy *= -1;
		return false;
	}
	if (x + 0.05f < radius - 1) {
		dx *= -1;
		return false;
	}
	if (x - 0.05f > 1 - radius) {
		dx *= -1;
		return false;
	}
	return false;
}