#include "GameTable.h"
#include <iostream>
#include <algorithm>


GameTable::GameTable() {
	std::cout << "new GameTable\n";
}

GameTable::~GameTable() {
	std::cout << "delete GameTable\n";
}

void GameTable::PrepareTable()
{	
	auto line = GameLine{ vector<char>{'a', 'b', 'c'}, GameState::BaseGame };
	_lines.push_back(line);

	for (int i = 0; i < 100; i++) {
		char c1 = rand() % 26 + 97;
		char c2 = rand() % 26 + 97;
		char c3 = rand() % 26 + 97;
		auto line = GameLine{ vector<char>{c1, c2, c3}, GameState::BaseGame };
		_lines.push_back(line);
	}
}

void GameTable::Spin()
{
	GameLine pattern{ vector<char>{'a','b','c'}, GameState::BonusGame };

	Evaluate(pattern);

	Dump();
}

void GameTable::Evaluate(GameLine& input) {
	for (auto p : _lines) {

		int count = 0;
		for (int i = 0; i < p.symbols.size(); i++) 
		{
			if (p.symbols[i] == input.symbols[i]) 
			{
				++count;
			}
		}

		if (count == input.symbols.size()) 
		{
			cout << "found\n";
		}
		else {
			cout << "not found\n";
		};
	};
}

void GameTable::Dump() {
	for (auto p : _lines) {
		for (char symbol : p.symbols) {
			cout << symbol << " ";
		}
		cout << ":" << (int)p.gamestate << endl;
	}
}
