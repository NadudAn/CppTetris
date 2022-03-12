#include <iostream>
#include <vector>
using namespace std;

//테트리스 판 x, y축 길이  S
#define TABLE_X 20
#define TABLE_Y 30

class MainMenu {

public: 
	MainMenu() {
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
		cout << "\t\t"; cout << "                         게임을 시작하려면 아무키나 누르세요.\n\n\n\n\n\n\n\n\n\n";
		cout << "\t\t"; cout << "                                 TETRIS 1.0  By  Nayeong An\n";

		getchar();
		system("cls"); //콘솔창 clear

	}
};

class GameTable {

private :
	int x;
	int y;
	vector<vector<int>> table; //테이블 판 0 = "□", 1 = "▦", 2 = "■"

public:
	GameTable(int x, int y) { //테트리스 판 뼈대 생성
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

	void DrawGameTable() {
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				if (table[i][j] == 1) cout << "▦";
				else cout << "□";
			}
			cout << "\n";
		}
	}
};

int main(void) {
	system("mode con cols = 100 lines = 40 | title 테트리스");
	
	GameTable gt(TABLE_X, TABLE_Y);

	MainMenu();
	gt.DrawGameTable();
	
	getchar();

	return 0;
}