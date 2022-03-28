#pragma once

#include "Headers.h"
#include "Blocks.h"

void CursorView(char show);
void gotoxy(int x, int y);

class MainMenu {

public:
	MainMenu();
};

class GameTable {

private:
	int x;
	int y;
	Block* blockObject;
	vector<vector<int>> table;//테이블 판 0 = "□", 1 = "▦", 2 = "■"
public:
	GameTable(int x, int y);
	void drawGameTable();
	void createBlock();
	void moveBlock(int);
	void rotateBlock();

};

class GamePlay {
private:
	GameTable* gt;
public:
	GamePlay();
	~GamePlay();
};

class backup {
public:
	static void updateBlock(Block* source, Block& backupBlock);
	static void updateTable(vector<vector<int>>& source, vector<vector<int>>& backupTable);
};