#include <iostream>
#include <vector>
using namespace std;

//��Ʈ���� �� x, y�� ����  S
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
		cout << "\t\t"; cout << "                         ������ �����Ϸ��� �ƹ�Ű�� ��������.\n\n\n\n\n\n\n\n\n\n";
		cout << "\t\t"; cout << "                                 TETRIS 1.0  By  Nayeong An\n";

		getchar();
		system("cls"); //�ܼ�â clear

	}
};

class GameTable {

private :
	int x;
	int y;
	vector<vector<int>> table; //���̺� �� 0 = "��", 1 = "��", 2 = "��"

public:
	GameTable(int x, int y) { //��Ʈ���� �� ���� ����
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
				if (table[i][j] == 1) cout << "��";
				else cout << "��";
			}
			cout << "\n";
		}
	}
};

int main(void) {
	system("mode con cols = 100 lines = 40 | title ��Ʈ����");
	
	GameTable gt(TABLE_X, TABLE_Y);

	MainMenu();
	gt.DrawGameTable();
	
	getchar();

	return 0;
}