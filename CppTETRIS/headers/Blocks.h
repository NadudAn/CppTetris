#pragma once

#include "Headers.h"

//1번 블럭
const int block1[4][4][4] = {
	{
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{2, 2, 2, 2},
		{0, 0, 0, 0},
	},
	{
		{0, 0, 2, 0},
		{0, 0, 2, 0},
		{0, 0, 2, 0},
		{0, 0, 2, 0},
	},
	{
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{2, 2, 2, 2},
		{0, 0, 0, 0},
	},
	{
		{0, 0, 2, 0},
		{0, 0, 2, 0},
		{0, 0, 2, 0},
		{0, 0, 2, 0},
	}
};

//2번 블럭
const int block2[4][4][4] = {
	{
		{0, 0, 0, 0},
		{0, 2, 2, 0},
		{0, 2, 2, 0},
		{0, 0, 0, 0},
	},
	{
		{0, 0, 0, 0},
		{0, 2, 2, 0},
		{0, 2, 2, 0},
		{0, 0, 0, 0},
	},
	{
		{0, 0, 0, 0},
		{0, 2, 2, 0},
		{0, 2, 2, 0},
		{0, 0, 0, 0},
	},
	{
		{0, 0, 0, 0},
		{0, 2, 2, 0},
		{0, 2, 2, 0},
		{0, 0, 0, 0},
	}
};

//3번 블럭
const int block3[4][4][4] = {
	{
		{0, 2, 0, 0},
		{0, 2, 0, 0},
		{0, 2, 2, 0},
		{0, 0, 0, 0},
	},
	{
		{0, 0, 0, 0},
		{0, 2, 2, 2},
		{0, 2, 0, 0},
		{0, 0, 0, 0},
	},
	{
		{0, 2, 2, 0},
		{0, 0, 2, 0},
		{0, 0, 2, 0},
		{0, 0, 0, 0},
	},
	{
		{0, 0, 0, 0},
		{0, 0, 2, 0},
		{2, 2, 2, 0},
		{0, 0, 0, 0},
	}
};

//4번 블럭
const int block4[4][4][4] = {
	{
		{0, 0, 0, 0},
		{0, 2, 0, 0},
		{0, 2, 2, 0},
		{0, 0, 2, 0},
	},
	{
		{0, 0, 0, 0},
		{0, 2, 2, 0},
		{2, 2, 0, 0},
		{0, 0, 0, 0},
	},
	{
		{0, 0, 0, 0},
		{0, 2, 0, 0},
		{0, 2, 2, 0},
		{0, 0, 2, 0},
	},
	{
		{0, 0, 0, 0},
		{0, 2, 2, 0},
		{2, 2, 0, 0},
		{0, 0, 0, 0},
	}
};

//5번 블럭
const int block5[4][4][4] = {
	{
		{0, 0, 0, 0},
		{0, 2, 2, 2},
		{0, 0, 2, 0},
		{0, 0, 0, 0},
	},
	{
		{0, 0, 2, 0},
		{0, 2, 2, 0},
		{0, 0, 2, 0},
		{0, 0, 0, 0},
	},
	{
		{0, 0, 2, 0},
		{0, 2, 2, 2},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	},
	{
		{0, 0, 2, 0},
		{0, 0, 2, 2},
		{0, 0, 2, 0},
		{0, 0, 0, 0},
	}
};

class Block {
protected:
	int shape[4][4][4];
	int x;
	int y;
	int rotationCount;

public:
	int getShape(int rotationCount, int y, int x);
	int getX();
	int getY();
	int getRotationCount();
	void down();
	void left();
	void right();
	void rotate();
	void setX(int);
	void setY(int);
	void setRotationCount(int);
	void setShape(int, int, int, int);
};

class Block1 : public Block {
public:
	Block1();
};

class Block2 : public Block {
public:
	Block2();
};

class Block3 : public Block {
public:
	Block3();
};

class Block4 : public Block {
public:
	Block4();
};

class Block5 : public Block {
public:
	Block5();
};