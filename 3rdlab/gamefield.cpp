#include "gamefield.h"

GameField::GameField(int mapH, int mapW) {
	cell.assign(mapH, std::vector<std::shared_ptr<Element>>(mapW));
	for (int x = 0; x < mapW; x++) {
		for (int y = 0; y < mapH; y++) {
			cell[x][y] = std::make_shared<Gem>(Gem());
		}
	}
}


void GameField::DrawField() {
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
			if (cell[x][y]->is[SELECT])
				cell[x][y]->DrawFrame();
			glPopMatrix();
		}
	}
}

void GameField::SelectCell(int x, int y) {
	if (cell[x][y]->is[SELECT]) {
		cell[x][y]->is[SELECT] = false;
	}
	else {
		cell[x][y]->is[SELECT] = true;
	}
}

void GameField::ReplaceElements() {
	int dx = 1, dy = 1;
	for (int x = 0; x < mapW; x++) {
		for (int y = 0; y < mapH; y++) {
			if (cell[x][y]->is[SELECT]) {
				if (x != mapW - 1 && cell[x + dx][y]->is[SELECT])
				{
					cell[x][y]->is[SELECT] = false;
					cell[x + dx][y]->is[SELECT] = false;
					std::swap(cell[x][y], cell[x + dx][y]);
				}
				else if (y != mapH - 1 && cell[x][y + dy]->is[SELECT])
				{
					cell[x][y]->is[SELECT] = false;
					cell[x][y + dy]->is[SELECT] = false;
					std::swap(cell[x][y], cell[x][y + dy]);
				}
			}
		}
	}
}


const int BonusChance = 20;

const int BombOrRecolor = 2;

void GameField::SmashOut(xy position) {
	int x = position.x, y = position.y;
	cell[x][y]->is[SELECT] = true;
	cell[x][y]->UseBonus(this, cell[x][y], position);

	if (rand() % BonusChance == 1) {
		if (rand() % BombOrRecolor) {
			color resetColor = cell[x][y]->GetColor();
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
				size_t abc = sizeof(cell[x][y]);
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

bool operator==(const color& rgb1, const color& rgb2) {
	return (rgb1.r == rgb2.r && rgb1.g == rgb2.g && rgb1.b == rgb2.b);
}

void GameField::UpDownLeftRight(xy point, std::vector<xy>& positions, color rgb) {
	if (point.x >= mapW || point.x < 0 || point.y >= mapH || point.y < 0)
		return;
	if (cell[point.x][point.y]->GetColor() == rgb) {
		cell[point.x][point.y]->is[CHECKED] = true;
		positions.push_back(point);
		UpDownLeftRight({ point.x + 1, point.y }, positions, rgb);
		UpDownLeftRight({ point.x - 1, point.y }, positions, rgb);
		UpDownLeftRight({ point.x, point.y + 1 }, positions, rgb);
		UpDownLeftRight({ point.x, point.y - 1 }, positions, rgb);
	}
}

bool comparator(xy point1, xy point2) {
	return point1.y < point2.y;
}

void GameField::SmashOutVector(std::vector<xy>& positions) {
	if (positions.size() > 2)
	{
		std::sort(positions.begin(), positions.end(), comparator);
		while (!positions.empty())
		{
			SmashOut(positions.back());
			positions.pop_back();
		}
	}
	else if (!positions.empty())
	{
		while (!positions.empty()) positions.pop_back();
	}
}

void GameField::CheckCombinations() {
	std::vector<xy> positions;
	for (int y = mapH - 1; y > -1; y--) {
		for (int x = 0; x < mapW; x++) {
			UpDownLeftRight({ x,y }, positions, cell[x][y]->GetColor());
			SmashOutVector(positions);
		}
	}
	for (int y = 0; y < mapH; y++) {
		for (int x = 0; x < mapW; x++) {
			cell[x][y]->is[CHECKED] = false;
		}
	}
}


void GameField::BonusesUsing() {
	for (int y = 0; y < mapH; y++) {
		for (int x = 0; x < mapW; x++) {
			if (cell[x][y]->is[SELECT]) {
				cell[x][y]->UseBonus(this, cell[x][y], { x,y });
			}
		}
	}
}
