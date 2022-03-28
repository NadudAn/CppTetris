#include "Headers.h"
#include "Tetris.h"

int main(void) {
	CursorView(false);
	system("mode con cols = 100 lines = 40 | title TETRIS");
	GameTable gt(TABLE_X, TABLE_Y);
	MainMenu();
	GamePlay();
	getchar();
	
	return 0;
}