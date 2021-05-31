#include "ball.hpp"
#include "carriage.hpp"
#include "bricks.hpp"



int sgn(float val)
{
	return (val > 0) ? (1) : ((val < 0) ? (-1) : (0));
}

bool TBall::ReflectCarriage(TCarriage& carriage) {
	if (((x + radius > carriage.getX() - carriage.getLength() &&
		x - radius < carriage.getX() + carriage.getLength())) &&
		IsCrossLine(carriage.getX() - carriage.getLength(), carriage.getY(),
			        carriage.getX() + carriage.getLength(), carriage.getY()))
	{
		dx = sgn(dx) * speedcomp;
		dy = sgn(dy) * speedcomp;
		dy *= -1;
		float speed = float(sqrt(dy * dy + dx * dx));
		if (x > carriage.getX()) {
			dy = float(cos(((x - carriage.getX()) / carriage.getLength()) * M_PI_4) * speed);
			dx = float(sin(((x - carriage.getX()) / carriage.getLength()) * M_PI_4) * speed);
		}
		else if (x < carriage.getX()) {
			dy = float(cos(((carriage.getX() - x) / carriage.getLength()) * M_PI_4) * speed);
			dx = float(-sin(((carriage.getX() - x) / carriage.getLength()) * M_PI_4) * speed);
		}
		return true;
	}
	return false;
}

bool TBall::IsCrossPoint(float x1, float y1, float r) 
{
	return (x - x1) * (x - x1) + (y - y1) * (y - y1) < r * r;
}

bool TBall::IsCrossLine(float x1, float y1, float x2, float y2) {
	float A = y2 - y1;
	float B = x1 - x2;
	float C = x2 * y1 - x1 * y2;
	return fabs(A * x + B * y + C) / sqrt(A * A + B * B) < radius;
}

void TBall::Mirror(float x1, float y1) 
 {
	float ballvec = float(atan2(dx, dy));
	float crossvec = float(atan2(x - x1, y - y1));

	float resvec = float(M_PI - ballvec + crossvec * 2.0f);
	float speed = float(sqrt(dx * dx + dy * dy));

	dx = float(sin(resvec) * speed);
	dy = float(cos(resvec) * speed);
}

const int BONUS_CHANCE = 10;


bool TBall::ReflectBricks(std::vector<TBrick*>& bricks, std::vector <TBonus*>& bonuses, int& score)
{
	if (!bricks.empty()) {
		float height_2 = bricks[0]->getHeight() / 2.0f;
		float width_2 = bricks[-0]->getWidth() / 2.0f;

		for (size_t i = 0; i < bricks.size(); i++)
		{
			if (IsCrossPoint(bricks[i]->getX() - width_2, bricks[i]->getY() - height_2, radius)) {
				Mirror(bricks[i]->getX() - width_2, bricks[i]->getY() - height_2);
				if (bricks[i]->lifesAway(*this, score)) {
					if (rand() % BONUS_CHANCE == 1) {
						bonuses.push_back(new TBonus(bricks[i]->getX(), bricks[i]->getY()));
					}
					delete bricks[i];
					bricks.erase(bricks.begin() + i);
				}
				return true;
			}
			if (IsCrossPoint(bricks[i]->getX() - width_2, bricks[i]->getY() + height_2, radius)) {
				Mirror(bricks[i]->getX() - width_2, bricks[i]->getY() + height_2);
				if (bricks[i]->lifesAway(*this, score)) {
					if (rand() % BONUS_CHANCE == 1) {
						bonuses.push_back(new TBonus(bricks[i]->getX(), bricks[i]->getY()));
					}
					delete bricks[i];
					bricks.erase(bricks.begin() + i);
				}
				return true;
			}
			if (IsCrossPoint(bricks[i]->getX() + width_2, bricks[i]->getY() + height_2, radius)) {
				Mirror(bricks[i]->getX() + width_2, bricks[i]->getY() + height_2);
				if (bricks[i]->lifesAway(*this, score)) {
					if (rand() % BONUS_CHANCE == 1) {
						bonuses.push_back(new TBonus(bricks[i]->getX(), bricks[i]->getY()));
					}
					delete bricks[i];
					bricks.erase(bricks.begin() + i);
				}
				return true;
			}
			if (IsCrossPoint(bricks[i]->getX() + width_2, bricks[i]->getY() - height_2, radius)) {
				Mirror(bricks[i]->getX() + width_2, bricks[i]->getY() - height_2);
				if (bricks[i]->lifesAway(*this, score)) {
					if (rand() % BONUS_CHANCE == 1) {
						bonuses.push_back(new TBonus(bricks[i]->getX(), bricks[i]->getY()));
					}
					delete bricks[i];
					bricks.erase(bricks.begin() + i);
				}
				return true;
			}
			if (x > bricks[i]->getX() - width_2 && x < bricks[i]->getX() + width_2 && 
				IsCrossLine(bricks[i]->getX() - width_2, bricks[i]->getY() - height_2,
				bricks[i]->getX() + width_2, bricks[i]->getY() - height_2)) {
				dy *= -1;
				if (bricks[i]->lifesAway(*this, score)) {
					if (rand() % BONUS_CHANCE == 1) {
						bonuses.push_back(new TBonus(bricks[i]->getX(), bricks[i]->getY()));
					}
					delete bricks[i];
					bricks.erase(bricks.begin() + i);
				}
				return true;
			}
			if (y > bricks[i]->getY() - height_2 && y < bricks[i]->getY() + height_2 &&
				IsCrossLine(bricks[i]->getX() - width_2, bricks[i]->getY() - height_2,
				bricks[i]->getX() - width_2, bricks[i]->getY() + height_2)) {
				dx *= -1;
				if (bricks[i]->lifesAway(*this, score)) {
					if (rand() % BONUS_CHANCE == 1) {
						bonuses.push_back(new TBonus(bricks[i]->getX(), bricks[i]->getY()));
					}
					delete bricks[i];
					bricks.erase(bricks.begin() + i);
				}
				return true;
			}
			if (x > bricks[i]->getX() - width_2 && x < bricks[i]->getX() + width_2 &&
				IsCrossLine(bricks[i]->getX() - width_2, bricks[i]->getY() + height_2,
				bricks[i]->getX() + width_2, bricks[i]->getY() + height_2)) {
				dy *= -1;
				if (bricks[i]->lifesAway(*this, score)) {
					if (rand() % BONUS_CHANCE == 1) {
						bonuses.push_back(new TBonus(bricks[i]->getX(), bricks[i]->getY()));
					}
					delete bricks[i];
					bricks.erase(bricks.begin() + i);
				}
				return true;
			}
			if (y > bricks[i]->getY() - height_2 && y < bricks[i]->getY() + height_2 &&
				IsCrossLine(bricks[i]->getX() + width_2, bricks[i]->getY() + height_2,
				bricks[i]->getX() + width_2, bricks[i]->getY() - height_2)) {
				dx *= -1;
				if (bricks[i]->lifesAway(*this, score)) {
					if (rand() % BONUS_CHANCE == 1) {
						bonuses.push_back(new TBonus(bricks[i]->getX(), bricks[i]->getY()));
					}
					delete bricks[i];
					bricks.erase(bricks.begin() + i);
				}
				return true;
			}
		}
	}
	return false;
}

bool TBall::Move(TCarriage& carriage, std::vector<TBrick*>& bricks, std::vector<TBonus*>& bonuses, int& score) {
	x += dx;
	y += dy;

	if (ReflectCarriage(carriage)) {
		return false;
	}

	if (ReflectBricks(bricks, bonuses, score)) {
		return false;
	}

	if (IsCrossLine(-1, 1, 1, 1)) {
		dy *= -1;
		return false;
	}
	if (IsCrossLine(-1, -1, 1, -1)) {
		dy *= -1;
		return true;
	}
	if (IsCrossLine(-1, -1, -1, 1)) {
		dx *= -1;
		return false;
	}
	if (IsCrossLine(1, -1, 1, 1)) {
		dx *= -1;
		return false;
	}
	return false;
}

const int BALL_OR_BRICK = 2;

bool TBonus::Move(TCarriage& carriage, std::vector<TBrick*>& bricks, std::vector<TBall*>& ballz, int& score) {
	dy += ddy;
	y += dy;

	if (ReflectCarriage(carriage)) {
		score += 5;
		if (rand() % BALL_OR_BRICK == 1 && ballz.size() < 2) {
			ballz.push_back(new TBall(0.0f, -0.9f));
		}
		else {
			bricks.push_back(new TBrickFlying());
		}
		return true;
	}

	if (IsCrossLine(-1, -1, 1, -1)) {
		return true;
	}
	return false;
}


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

void TBonus::DrawObj() {
	float x0;
	float y0;
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 0.75, 0);
	float cnt = 100;
	float alpha = 3.1415926f * 2.0f / cnt;
	for (int i = -1; i < cnt; i++) {
		x0 = (float)sin((double)alpha * (double)i) * radius;
		y0 = (float)cos((double)alpha * (double)i) * radius;
		glVertex2f(x0 + x, y0 + y);
	}
	glEnd();
}