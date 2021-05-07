#include "gems.h"

namespace rgb {
	color palette[8] = {
		{0.0f, 0.0f, 0.0f},
		{1.0f, 1.0f, 1.0f},
		{1.0f, 0.0f, 0.0f},
		{0.0f, 1.0f, 0.0f},
		{0.0f, 0.0f, 1.0f},
		{1.0f, 1.0f, 0.0f},
		{1.0f, 0.0f, 1.0f},
		{0.0f, 1.0f, 1.0f},
	};
};

	Gem::Gem() { gemColor = rgb::palette[2 + rand() % (6)]; }
	Gem::Gem(color newColor) { gemColor = newColor; }
	Gem::~Gem() {};
	color Gem::getColor() { return gemColor; }
	void Gem::reColor() { gemColor = rgb::palette[2 + rand() % (6)]; }
	void Gem::reColor(color newColor) { gemColor = newColor; }

	void Gem::DrawElement() {
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1, 1, 1);
		glVertex2f(0.1f, 0.6f);
		glVertex2f(0.25f, 0.8f);
		glVertex2f(0.3f, 0.8f);
		glVertex2f(0.4f, 0.6f);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(gemColor.r, gemColor.g, gemColor.b);
		glVertex2f(0.3f, 0.8f);
		glVertex2f(0.4f, 0.6f);
		glVertex2f(0.6f, 0.6f);
		glVertex2f(0.7f, 0.8f);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.75f * gemColor.r, 0.75f * gemColor.g, 0.75f * gemColor.b);
		glVertex2f(0.6f, 0.6f);
		glVertex2f(0.7f, 0.8f);
		glVertex2f(0.75f, 0.8f);
		glVertex2f(0.9f, 0.6f);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(gemColor.r, gemColor.g, gemColor.b);
		glVertex2f(0.1f, 0.6f);
		glVertex2f(0.4f, 0.6f);
		glVertex2f(0.5f, 0.1f);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.75f * gemColor.r, 0.75f * gemColor.g, 0.75f * gemColor.b);
		glVertex2f(0.4f, 0.6f);
		glVertex2f(0.6f, 0.6f);
		glVertex2f(0.5f, 0.1f);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.5f * gemColor.r, 0.5f * gemColor.g, 0.5f * gemColor.b);
		glVertex2f(0.6f, 0.6f);
		glVertex2f(0.9f, 0.6f);
		glVertex2f(0.5f, 0.1f);
		glEnd();
	}

	void Gem::DrawFrame() {
		glLineWidth(2);
		glBegin(GL_LINE_STRIP);
		glColor3f(1.0f, 0.6f, 0.0f);
		glVertex2f(0.5f, 0.1f);
		glVertex2f(0.1f, 0.6f);
		glVertex2f(0.25f, 0.8f);
		glVertex2f(0.75f, 0.8f);
		glVertex2f(0.9f, 0.6f);
		glVertex2f(0.5f, 0.1f);
		glEnd();
	}

	Bomb::Bomb() { isExplosion = true; }

	void Bomb::DrawElement() {
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.5f, 0.5f, 0.5f);
		float x, y;
		float cnt = 20;
		float r = 0.4f;
		float alpha = 3.1415926f * 2.0f / cnt;
		for (int i = -1; i < cnt; i++) {
			x = sin(alpha * i) * r;
			y = cos(alpha * i) * r;
			glVertex2f(x + 0.5f, y + 0.5f);
		}
		glColor3f(0, 0, 0);
		glPointSize(2);
		for (int i = -1; i < cnt; i++) {
			x = sin(alpha * i) * r;
			y = cos(alpha * i) * r;
			glVertex2f(x + 0.5f, y + 0.5f);
		}
		glEnd();
	}
	void Bomb::DrawFrame() {
		float x, y;
		float dot = 100;
		float r = 0.4f;
		float alpha = 3.1415926f * 2.0f / dot;
		glPointSize(2);
		glBegin(GL_POINTS);
		glColor3f(1.0f, 0.6f, 0.0f);
		for (int i = -1; i < dot; i++) {
			x = sin(alpha * i) * r;
			y = cos(alpha * i) * r;
			glVertex2f(x + 0.5f, y + 0.5f);
		}
		glEnd();
	}

	color Bomb::getColor() { return { 0,0,0 }; };
	void Bomb::reColor() {}
	void Bomb::reColor(color newColor) {}


	ReColor::ReColor(color prev) { prevColor = prev; isReColor = true; }

	void ReColor::DrawElement() {
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1, 1, 1);
		float x, y;
		float cnt = 20;
		float r = 0.5f;
		float alpha = 3.1415926f * 2.0f / cnt;
		for (int i = -1; i < cnt; i++) {
			x = sin(alpha * i) * r;
			y = cos(alpha * i) * r;
			glVertex2f(x + 0.5f, y + 0.5f);
		}
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1, 1, 1);
		glVertex2f(0.1f, 0.6f);
		glVertex2f(0.25f, 0.8f);
		glVertex2f(0.3f, 0.8f);
		glVertex2f(0.4f, 0.6f);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(prevColor.r, prevColor.g, prevColor.b);
		glVertex2f(0.3f, 0.8f);
		glVertex2f(0.4f, 0.6f);
		glVertex2f(0.6f, 0.6f);
		glVertex2f(0.7f, 0.8f);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.75f * prevColor.r, 0.75f * prevColor.g, 0.75f * prevColor.b);
		glVertex2f(0.6f, 0.6f);
		glVertex2f(0.7f, 0.8f);
		glVertex2f(0.75f, 0.8f);
		glVertex2f(0.9f, 0.6f);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(prevColor.r, prevColor.g, prevColor.b);
		glVertex2f(0.1f, 0.6f);
		glVertex2f(0.4f, 0.6f);
		glVertex2f(0.5f, 0.1f);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.75f * prevColor.r, 0.75f * prevColor.g, 0.75f * prevColor.b);
		glVertex2f(0.4f, 0.6f);
		glVertex2f(0.6f, 0.6f);
		glVertex2f(0.5f, 0.1f);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.5f * prevColor.r, 0.5f * prevColor.g, 0.5f * prevColor.b);
		glVertex2f(0.6f, 0.6f);
		glVertex2f(0.9f, 0.6f);
		glVertex2f(0.5f, 0.1f);
		glEnd();
	}

	void ReColor::DrawFrame() {
		float x, y;
		float dot = 100;
		float r = 0.5f;
		float alpha = 3.1415926f * 2.0f / dot;
		glPointSize(2);
		glBegin(GL_POINTS);
		glColor3f(1.0f, 0.6f, 0.0f);
		for (int i = -1; i < dot; i++) {
			x = sin(alpha * i) * r;
			y = cos(alpha * i) * r;
			glVertex2f(x + 0.5f, y + 0.5f);
		}
		glEnd();
	}

	color ReColor::getColor() { return prevColor; }
	void ReColor::reColor() {}
	void ReColor::reColor(color newColor) {}

bool operator==(const color& rgb1, const color& rgb2) {
	return (rgb1.r == rgb2.r && rgb1.g == rgb2.g && rgb1.b == rgb2.b);
}

GameField::GameField(int mapH, int mapW) {
		cell = new std::shared_ptr<Element>*[mapH];
		for (int i = 0; i < mapH; i++) {
			cell[i] = new std::shared_ptr<Element>[mapW];
		}

		for (int x = 0; x < mapW; x++) {
			for (int y = 0; y < mapH; y++) {
				cell[x][y] = std::shared_ptr<Element>(new Gem());
			}
		}
	}

	void GameField::drawField() {
		glLoadIdentity();
		glScalef(2.0f / mapW, 2.0f / mapH, 1);
		glTranslatef(-mapW / 2.0f, -mapH / 2.0f, 0);

		for (int x = 0; x < mapW; x++)
		{
			for (int y = 0; y < mapH; y++)
			{
				glPushMatrix();
				glTranslatef(float(x), float(y), 0);
				cell[x][y]->DrawElement();
				if (cell[x][y]->isSelect)
					cell[x][y]->DrawFrame();
				glPopMatrix();
			}
		}
	}

	void GameField::swapGems() {
		int dx = 1, dy = 1;
		for (int x = 0; x < mapW; x++) {
			for (int y = 0; y < mapH; y++) {
				if (cell[x][y]->isSelect) {
					if (x != mapW - 1 && cell[x + dx][y]->isSelect)
					{
						cell[x][y]->isSelect = false;
						cell[x + dx][y]->isSelect = false;
						swap(cell[x][y], cell[x + dx][y]);
					}
					else if (y != mapH - 1 && cell[x][y + dy]->isSelect)
					{
						cell[x][y]->isSelect = false;
						cell[x][y + dy]->isSelect = false;
						swap(cell[x][y], cell[x][y + dy]);
					}
				}
			}
		}
	}

	void GameField::BonusReColor() {
		for (int x = 0; x < mapW; x++) {
			for (int y = 0; y < mapH; y++) {
				if (cell[x][y]->isSelect && cell[x][y]->isReColor) {
					cell[x][y]->isSelect = false;
					cell[x][y]->isReColor = false;
					color forChange = cell[x][y]->getColor();
					cell[x][y].reset();
					cell[x][y].reset(new Gem(forChange));
					for (int i = 0; i < 2; i++) {
						int rng1 = 50, rng2 = 50;
						while (x + rng1 >= mapW || x + rng1 < 0 || y + rng2 >= mapH || y + rng2 < 0) {
							rng1 = 1 + rand() % 3;
							rng2 = 1 + rand() % 3;
							if (rand() % 2) {
								rng1 = -rng1;
							}
							if (rand() % 2) {
								rng2 = -rng2;
							}
						}
						cell[x + rng1][y + rng2]->reColor(forChange);
					}
				}
			}
		}
	}

	void GameField::BlowUP() {
		int x1, y1;
		for (int x = 0; x < mapW; x++) {
			for (int y = 0; y < mapH; y++) {
				if (cell[x][y]->isSelect && cell[x][y]->isExplosion) {
					cell[x][y]->isSelect = false;
					cell[x][y]->isExplosion = false;
					cell[x][y].reset();
					cell[x][y].reset(new Gem());
					for (int y2 = y; y2 < mapH - 1; y2++)
					{
						swap(cell[x][y2], cell[x][y2 + 1]);
					}
					for (int i = 0; i < 4; i++) {
						x1 = rand() % mapW;
						y1 = rand() % mapH;
						SmashOut({ x1, y1 });
					}
				}

			}
		}
	}

	void GameField::SmashOut(xy position) {
		int x = position.x, y = position.y;
		if (cell[x][y]->isExplosion) {
			cell[x][y]->isSelect = true;
			BlowUP();
		}
		if (rand() % 20 == 1) {
			if (rand() % 2) {
				color resetColor = cell[x][y]->getColor();
				if (y == mapH - 1) {
					cell[x][y].reset();
					cell[x][y].reset(new ReColor(resetColor));
					return;
				}
				else {
					cell[x][y + 1].reset(new ReColor(resetColor));
				}
			}
			else {
				if (y == mapH - 1) {
					cell[x][y].reset();
					cell[x][y].reset(new Bomb());
					return;
				}
				else {
					cell[x][y + 1].reset(new Bomb());
				}
			}
		}
		for (; y < mapH - 1; y++)
		{
			swap(cell[x][y], cell[x][y + 1]);
		}
		cell[x][y]->reColor();
	}

	void GameField::UpDownLeftRight(xy point, std::queue<xy>& positions, color rgb) {
		if (point.x >= mapW || point.x < 0 || point.y >= mapH || point.y < 0) 
			return;
		if (cell[point.x][point.y]->isExplosion || cell[point.x][point.y]->isReColor || cell[point.x][point.y]->isChecked) {
			cell[point.x][point.y]->isChecked = true;
			return;
		}
		if (cell[point.x][point.y]->getColor() == rgb) {
			cell[point.x][point.y]->isChecked = true;
			positions.push(point);
			UpDownLeftRight({ point.x + 1, point.y }, positions, rgb);
			UpDownLeftRight({ point.x - 1, point.y }, positions, rgb);
			UpDownLeftRight({ point.x, point.y + 1 }, positions, rgb);
			UpDownLeftRight({ point.x, point.y - 1 }, positions, rgb);
		}
	}

        void GameField::CheckCombinations() {
		std::queue<xy> positions;
		for (int y = mapH-1; y > -1; y--) {
			for (int x = 0; x < mapW; x++) {
				UpDownLeftRight({ x,y }, positions, cell[x][y]->getColor());
				if (positions.size() > 2)
				{
					while (!positions.empty())
					{
						SmashOut(positions.front());
						positions.pop();
					}
				}
				else if (!positions.empty())
				{
					while (!positions.empty()) positions.pop();
				}
			}
		}
		for (int y = 0; y < mapH; y++) {
			for (int x = 0; x < mapW; x++) {
				cell[x][y]->isChecked = false;
			}
		}
	}

	void GameField::HorizontalCheck() {
		int x = 0, y = 0;
		std::stack<xy> positions;

		for (y = 0; y < mapH; y++)
		{
			if (positions.size() > 2)
			{
				while (!positions.empty())
				{
					SmashOut(positions.top());
					positions.pop();
				}
			}
			else if (!positions.empty())
			{
				while (!positions.empty()) positions.pop();
			}
			color curColor = cell[0][y]->getColor();
			positions.push({ 0,y });
			for (x = 1; x < mapW; x++)
			{
				if (!cell[x][y]->isReColor && !cell[x][y]->isExplosion && curColor == cell[x][y]->getColor())
				{
					positions.push({ x,y });
				}
				else if (positions.size() > 2)
				{
					while (!positions.empty())
					{
						SmashOut(positions.top());
						positions.pop();
					}
					curColor = cell[x][y]->getColor();
					positions.push({ x,y });
				}
				else
				{
					while (!positions.empty())
					{
						positions.pop();
					}
					curColor = cell[x][y]->getColor();
					positions.push({ x,y });
				}
			}
		}
		if (positions.size() > 2) {
			while (!positions.empty()) {
				SmashOut(positions.top());
				positions.pop();
			}
		}
	}

	void GameField::VerticalCheck() {
		int x = 0, y = 0;
		std::stack<xy> positions;
		for (x = 0; x < mapW; x++)
		{
			if (positions.size() > 2)
			{
				while (!positions.empty())
				{
					SmashOut(positions.top());
					positions.pop();
				}
			}
			else if (!positions.empty())
			{
				while (!positions.empty()) positions.pop();
			}
			color curColor = cell[x][0]->getColor();
			positions.push({ x,0 });
			for (y = 1; y < mapH; y++)
			{
				if (!cell[x][y]->isReColor && !cell[x][y]->isExplosion && curColor == cell[x][y]->getColor())
				{
					positions.push({ x,y });
				}
				else if (positions.size() > 2)
				{
					while (!positions.empty())
					{
						SmashOut(positions.top());
						positions.pop();
					}
					curColor = cell[x][y]->getColor();
					positions.push({ x,y });
				}
				else
				{
					while (!positions.empty())
					{
						positions.pop();
					}
					curColor = cell[x][y]->getColor();
					positions.push({ x,y });
				}
			}
		}
		if (positions.size() > 2) {
			while (!positions.empty()) {
				SmashOut(positions.top());
				positions.pop();
			}
		}
	}
