#pragma once
#include <vector>
#include <string>
#include "Ship.h"

class Seas
{
public:
	Seas();
	virtual ~Seas();

	int col, row, lastHitRow, lastHitCol;
	bool lastDirectionHit, AIAttackTurn;

	void AITurn();
	const void GameState();
	bool DoAction(string action);
	const void SeaStatus(std::vector<std::vector<char>>& sea, string seaPrompt);

	std::vector<std::vector<char>> aiSea;
	std::vector<std::vector<char>> playerSea;
	std::vector<std::vector<char>> aiGuessSea;
	std::vector<std::vector<char>> playerGuessSea;

private:
	void ReloadGame();
	void LaunchMissile();
	bool LoadGame(int mode);
	void LoadAIShips(Ship* ship);
	void LoadPlayerShips(Ship* ship);
	void InitNewSeas(unsigned int size);
	bool WinConditionAchieved(std::vector<std::vector<char>>& sea, string prompt);
	bool LoadShip(std::vector<std::vector<char>>& sea, Ship* ship, int col, int row, bool direct);
	bool HitLocation(std::vector<std::vector<char>>& guessSea, std::vector<std::vector<char>>& enemySea, int col, int row);

};

