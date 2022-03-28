#include "Blocks.h"

int Block::getShape(int rotationCount, int y, int x) {
	return shape[rotationCount][y][x];
}

int Block::getX() {
	return x;
}

int Block::getY() {
	return y;
}

int Block::getRotationCount() {
	return rotationCount;
}

void Block::down() {
	y++;
}

void Block::left() {
	x--;
}

void Block::right() {
	x++;
}

void Block::rotate() {
	rotationCount = (rotationCount + 1) % 4;
}

void Block::setX(int x) {
	this->x = x;
}

void Block::setY(int y) {
	this->y = y;
}

void Block::setRotationCount(int r) {
	this->rotationCount = r;
}

void Block::setShape(int r, int y, int x, int value) {
	this->shape[r][y][x] = value;
}

Block1::Block1() {
	x = TABLE_X / 2 - 3; //�ʱ� ���� �� �� �߾� ������ ����
	y = 1;
	rotationCount = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int u = 0; u < 4; u++) {
				shape[i][j][u] = block1[i][j][u]; //�� ��ü ���� ����
			}
		}
	}
}

Block2::Block2() {
	x = TABLE_X / 2 - 3; //�ʱ� ���� �� �� �߾� ������ ����
	y = 1;
	rotationCount = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int u = 0; u < 4; u++) {
				shape[i][j][u] = block2[i][j][u]; //�� ��ü ���� ����
			}
		}
	}
}

Block3::Block3() {
	x = TABLE_X / 2 - 3; //�ʱ� ���� �� �� �߾� ������ ����
	y = 1;
	rotationCount = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int u = 0; u < 4; u++) {
				shape[i][j][u] = block3[i][j][u]; //�� ��ü ���� ����
			}
		}
	}
}

Block4::Block4() {
	x = TABLE_X / 2 - 3; //�ʱ� ���� �� �� �߾� ������ ����
	y = 1;
	rotationCount = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int u = 0; u < 4; u++) {
				shape[i][j][u] = block4[i][j][u]; //�� ��ü ���� ����
			}
		}
	}
}

Block5::Block5() {
	x = TABLE_X / 2 - 3; //�ʱ� ���� �� �� �߾� ������ ����
	y = 1;
	rotationCount = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int u = 0; u < 4; u++) {
				shape[i][j][u] = block5[i][j][u]; //�� ��ü ���� ����
			}
		}
	}
}