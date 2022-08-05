#pragma once
#include <vector>
#include "framework.h"

using namespace std;

enum class GameState {
	BaseGame,
	BonusGame,
	FreeSpins
};


struct GameLine {
	vector<char> symbols;
	GameState gamestate; 
};

class GameTable
{
private:
	vector<GameLine> _lines;
public:
	GameTable();
	virtual ~GameTable();
	void PrepareTable();
	void Spin();
	void Evaluate(GameLine& gl);
	void Dump();
};

