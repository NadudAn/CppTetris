#include "Tetris.h"

//Ŀ�� �����(0) or Ŀ�� ���̱�(1)
void CursorView(char show) {
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void gotoxy(int x, int y) {
	COORD pos = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

MainMenu::MainMenu() {
	cout << "\n\n\n\n";
	cout << "\t\t"; cout << "##############  #############  ##############  ###########     ##      ########\n";
	cout << "\t\t"; cout << "      ##        ##                   ##        ##         ##   ##    ##        ###\n";
	cout << "\t\t"; cout << "      ##        ##                   ##        ##         ##   ##   ##           ##\n";
	cout << "\t\t"; cout << "      ##        ##                   ##        ###########     ##    ### \n";
	cout << "\t\t"; cout << "      ##        #############        ##        ##        ##    ##      ##########\n";
	cout << "\t\t"; cout << "      ##        ##                   ##        ##         ##   ##               ###\n";
	cout << "\t\t"; cout << "      ##        ##                   ##        ##          ##  ##  ##             ##\n";
	cout << "\t\t"; cout << "      ##        ##                   ##        ##          ##  ##   ###         ##\n";
	cout << "\t\t"; cout << "      ##        #############        ##        ##          ##  ##     ##########\n";
	cout << "\t\t"; cout << "                         ������ �����Ϸ��� �ƹ�Ű�� ��������.\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t"; cout << "                                 TETRIS 1.0  By  Nayeong An\n";

	getchar();
	system("cls"); //�ܼ�â clear

}

void backup::updateBlock(Block* source, Block& backupBlock) {
	backupBlock.setX(source->getX());
	backupBlock.setY(source->getY());
	backupBlock.setRotationCount(source->getRotationCount());

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				backupBlock.setShape(i, j, k, source->getShape(i, j, k));
			}
		}
	}
}

void backup::updateTable(vector<vector<int>>& source, vector<vector<int>>& backupTable) {
	backupTable.resize(source.size(), vector<int>(source.size()));
	copy(source.begin(), source.end(), backupTable.begin());
}

//���̺� �� 0 = "��", 1 = "��", 2 = "��"
GameTable::GameTable(int x, int y) { //��Ʈ���� �� ���� ����
	blockObject = nullptr;
	this->x = x;
	this->y = y;

	for (int i = 0; i < y; i++) {
		vector<int> temp;
		for (int j = 0; j < x; j++) {
			temp.push_back(0);
		}
		table.push_back(temp);
	}
	
	for (int i = 0; i < x; i++) {
		table[0][i] = 1;
		table[y - 1][i] = 1;
	}
	for (int i = 1; i < y - 1; i++) {
		table[i][0] = 1;
		table[i][x - 1] = 1;
	}
}

void GameTable::drawGameTable() {
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (table[i][j] == 1) cout << "��";
			else if (table[i][j] == 2) cout << "��";
			else cout << "��";
		}
		cout << "\n";
	}
}

void GameTable::createBlock() {
	srand((unsigned int)time(NULL));
	int select = rand() % 5 + 1; //1~5 ��

	//�� ����
	if (select == 1) blockObject = new Block1();
	else if (select == 2) blockObject = new Block2();
	else if (select == 3) blockObject = new Block3();
	else if (select == 4) blockObject = new Block4();
	else if (select == 5) blockObject = new Block5();

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int Y = j + blockObject->getY();
			int X = i + blockObject->getX();
			table[Y][X] = blockObject->getShape(blockObject->getRotationCount(), i, j);
			//�� ��ü�� ���̺� ������Ʈ
		}
	}
}

//�� �̵�
void GameTable::moveBlock(int key) {
	Block backupBlock;
	vector<vector<int>> backupTable;
	backup::updateBlock(blockObject, backupBlock);
	backup::updateTable(table, backupTable);

	//���̺��� �� ��ü �����
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int Y = j + blockObject->getY();
			int X = i + blockObject->getX();
			if (table[Y][X] == 2) 
				table[Y][X] = 0;
			
		}
	}

	//����Ű�� ���� �Լ�����
	if (key == DOWN) blockObject->down();
	else if (key == LEFT) blockObject->left();
	else if (key == RIGHT) blockObject->right();

	//�̵��� �� ���¸� ���̺� ����
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int Y = j + blockObject->getY();
			int X = i + blockObject->getX();
			int blockValue = blockObject->getShape(blockObject->getRotationCount(), i, j);

			if (blockValue != 2) continue;

			if (table[Y][X] == 0)
				table[Y][X] = blockValue;
			else if (table[Y][X] == 1) {
				copy(backupTable.begin(), backupTable.end(), table.begin());
				blockObject->setX(backupBlock.getX());
				blockObject->setY(backupBlock.getY());
				return;
			}

		}
	}
}

void GameTable::rotateBlock() {
	Block backupBlock;
	vector<vector<int>> backupTable;
	backup::updateBlock(blockObject, backupBlock);
	backup::updateTable(table, backupTable);

	//���̺��� �� ��ü �����
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int Y = j + blockObject->getY();
			int X = i + blockObject->getX();
			if (table[Y][X] == 2)
				table[Y][X] = 0;

		}
	}

	blockObject->rotate();

	//ȸ���� �� ���¸� ���̺� ����
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int Y = j + blockObject->getY();
			int X = i + blockObject->getX();
			int blockValue = blockObject->getShape(blockObject->getRotationCount(), i, j);

			if (blockValue != 2) continue;

			if (table[Y][X] == 0)
				table[Y][X] = blockObject->getShape(blockObject->getRotationCount(), i, j);
			else if (table[Y][X] == 1) {
				copy(backupTable.begin(), backupTable.end(), table.begin());
				blockObject->setRotationCount(backupBlock.getRotationCount());
				return;
			}
		}
	}
}

GamePlay::GamePlay() {
	gt = new GameTable(TABLE_X, TABLE_Y); //������ �׸��� ��ü ����
	gt->createBlock();
	gt->drawGameTable();

	while (true) {
		int nSelct;

		if (_kbhit()) {
			nSelct = _getch();

			if (nSelct == 224) {
				nSelct = _getch();

				switch (nSelct) {
				case UP:
					gt->rotateBlock();
					gotoxy(0, 0);
					gt->drawGameTable();
					break;
				
				case DOWN:
					gt->moveBlock(DOWN);
					gotoxy(0, 0);
					gt->drawGameTable();
					break;
				case LEFT:
					gt->moveBlock(LEFT);
					gotoxy(0, 0);
					gt->drawGameTable();
					break;
				case RIGHT:
					gt->moveBlock(RIGHT);
					gotoxy(0, 0);
					gt->drawGameTable();
					break;
				default:
					break;
				}
			}
		}
	}
}

GamePlay::~GamePlay() {	//���� ���� �̺�Ʈ
	delete gt;
}