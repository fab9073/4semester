#pragma once
#include "bricks.hpp"
#include "ball.hpp"

TBrick::TBrick(float brickX, float brickY) {
	x = brickX; y = brickY;
}

int const GREEN = 3;
int const YELLOW = 2;
int const RED = 1;

void TBrick::DrawObj() {
	glBegin(GL_TRIANGLE_FAN);
	if (lifes == GREEN) {
		glColor3f(0.0f, 1.0f, 0.0f);
	}
	else if (lifes == YELLOW) {
		glColor3f(1.0f, 1.0f, 0.0f);
	}
	else if (lifes == RED) {
		glColor3f(1.0f, 0.0f, 0.0f);
	}
	glVertex2f(x - width * 0.5f, y - height * 0.5f);
	glVertex2f(x - width * 0.5f, y + height * 0.5f);
	glVertex2f(x + width * 0.5f, y + height * 0.5f);
	glVertex2f(x + width * 0.5f, y - height * 0.5f);
	glEnd();

	glBegin(GGL_STRING);
	glColor3f(0, 0, 0);
	glVertex2f(x - width * 0.5f, y - height * 0.5f);
	glVertex2f(x - width * 0.5f, y + height * 0.5f);
	glVertex2f(x + width * 0.5f, y + height * 0.5f);
	glVertex2f(x + width * 0.5f, y - height * 0.5f);
	glEnd();
}



void TBrickUnbrkbl::DrawObj() {
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(x - width * 0.5f, y - height * 0.5f);
	glVertex2f(x - width * 0.5f, y + height * 0.5f);
	glVertex2f(x + width * 0.5f, y + height * 0.5f);
	glVertex2f(x + width * 0.5f, y - height * 0.5f);
	glEnd();

	glBegin(GGL_STRING);
	glColor3f(0, 0, 0);
	glVertex2f(x - width * 0.5f, y - height * 0.5f);
	glVertex2f(x - width * 0.5f, y + height * 0.5f);
	glVertex2f(x + width * 0.5f, y + height * 0.5f);
	glVertex2f(x + width * 0.5f, y - height * 0.5f);
	glEnd();
}


void TBrickSpeedup::DrawObj() {
	glBegin(GL_TRIANGLE_FAN);
	if (lifes == GREEN) {
		glColor3f(0.0f, 1.0f, 0.0f);
	}
	else if (lifes == YELLOW) {
		glColor3f(1.0f, 1.0f, 0.0f);
	}
	else if (lifes == RED) {
		glColor3f(1.0f, 0.0f, 0.0f);
	}
	glVertex2f(x - width * 0.5f, y - height * 0.5f);
	glVertex2f(x - width * 0.5f, y + height * 0.5f);
	glVertex2f(x + width * 0.5f, y + height * 0.5f);
	glVertex2f(x + width * 0.5f, y - height * 0.5f);
	glEnd();

	glBegin(GGL_STRING);
	glColor3f(0, 0, 0);
	glVertex2f(x - width * 0.5f, y - height * 0.5f);
	glVertex2f(x - width * 0.5f, y + height * 0.5f);
	glVertex2f(x + width * 0.5f, y + height * 0.5f);
	glVertex2f(x + width * 0.5f, y - height * 0.5f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.75f, 1.0f);
	glVertex2f(x - width * 0.3f, y - height * 0.1f);
	glVertex2f(x - width * 0.3f, y + height * 0.1f);
	glVertex2f(x + width * 0.1f, y + height * 0.1f);
	glVertex2f(x + width * 0.1f, y - height * 0.1f);
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.75f, 1.0f);
	glVertex2f(x + width * 0.1f, y - height * 0.2f);
	glVertex2f(x + width * 0.3f, y);
	glVertex2f(x + width * 0.1f, y + height * 0.2f);
	glEnd();
}

bool TBrick::XtraPower(TBall& ball)
{
	lifes--;
	if (lifes == 0) {
		return true;
	}
	return false;
}

void TBall::setdx(float K) { dx *= K; }
void TBall::setdy(float K) { dy *= K; }

bool TBrickSpeedup::XtraPower(TBall& ball)
{
	lifes--;
	ball.setdx(1.1f);
	ball.setdy(1.1f);
	if (lifes == 0) {
		return true;
	}
	return false;
}

void TBrickFlying::Move() {
	x += dx;
	if (x < getWidth() - 1) {
		dx *= -1;
	}
	if (x > 1 - getWidth()) {
		dx *= -1;
	}
}
