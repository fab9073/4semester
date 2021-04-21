#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>

enum Colors {
	BLACK, WHITE, RED,
	GREEN, BLUE, YELLOW,
	ORANGE, VIOLENT
};


class Elem {
public:
	Colors color;
};

class Elem_ptr 
{
public:
	Elem* elem;
};


class Quad : public Elem 
{

};

/*class Bonus : public Elem {

};

class reColour : public Bonus {
	reColour() { color = WHITE; }
};

class Bomb : public Bonus {
	Bomb() { color = BLACK; }
};*/

class GameTable
{
	int size;
	std::vector <Elem_ptr> block;
	int score;

	void BuildTable() 
	{

	}

	bool CheckRowsTable() 
	{

	}
	
	bool CheckColumnsTable() 
	{

	}

	bool CheckTable()
	{
		CheckRowsTable();
		CheckColumnsTable();
	}

	void RefillTable() 
	{

	}

	void ShuffleTable() 
	{

	}

	void SelectElem()
	{

	}

	bool MoveElem()
	{

	}

	void MakeMoveElem() 
	{

	}

	bool CheckMovesTable()
	{

	}

};