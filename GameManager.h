#pragma once

#include <fstream>
#include <sstream>
#include <vector>
#include<iostream>
#include "Board.h"
#include "Chess.h"
#include "Viewer.h"
using namespace std;
//遊戲流程

struct position {
	int x;
	int y;
};
//enum chessType {GENERAL, ADVISOR, ELEPHANT, CHARIOT, HORSE, CANNON, SOLDIER};

// 基本棋子，abstract class
class Chess
{
private:
	int type;	// 將general 士advisor 象elephant 車chariot 馬horse 炮cannon 兵soldier
	int current_player;		// 1 red (row > 5 on the board initially) ; 2 black (row < 4 on the board initially)
	//Board b;
public:
	Chess(Board b);
	Chess() { type = -1; current_player = -1; };
	Chess(int _player) { type = -1; current_player = _player; };

	void setType(std::string input);
	int getType();
	int getCurrentPlayer();
	void setCurrentPlayer(int curr) { current_player = curr; }

	// 可以選擇的棋子
	//void availableChess(Board& const board);

	// 選擇執哪一子 -> 寫在main -> Chess c = new 類別(看type是什麼); c.Move(); 即可實現子類別的Move()
	//void chooseChess(Chess current_player);

	// 從fromPos走到toPos (基本走法)
	virtual void Move(Board& b, position& fromPos, position& toPos);
};


class General : public Chess	// 將 : 1.不過田 2.不能斜走 (3.被吃掉、王見王 皆輸掉遊戲)
{
public:
	General(Board b) :Chess(b) {};
	virtual void Move(Board& b, position& fromPos, position& toPos) override;
};

class Advisor : public Chess	// 士 : 1.不過田 2.只能斜走
{
public:
	Advisor(Board b) :Chess(b) {};
	virtual void Move(Board& b, position& fromPos, position& toPos) override;
};

class Elephant : public Chess	// 象 : 1.不過河 2.田字走 3.擠象眼(田字中間不可有棋)
{
public:
	Elephant(Board b) :Chess(b) {};
	virtual void Move(Board& b, position& fromPos, position& toPos) override;
};

class Chariot : public Chess	// 車 : 1.直橫皆不受距離移動
{
public:
	Chariot(Board b) :Chess(b) {};
	virtual void Move(Board& b, position& fromPos, position& toPos) override;
};

class Horse : public Chess		// 馬 : 1.日字走 2.拐馬腳(前進方向 緊鄰馬的位子不可有棋)
{
public:
	Horse(Board b) :Chess(b) {};
	virtual void Move(Board& b, position& fromPos, position& toPos) override;
};

class Cannon : public Chess		// 炮 : 1.不吃棋時走法與車相同 2.吃棋時跳吃
{
public:
	Cannon(Board b) :Chess(b) {};
	virtual void Move(Board& b, position& fromPos, position& toPos) override;
};

class Soldier : public Chess	// 兵 : 1.過河前只能前行 2.過河後只能左右前行不可後退
{
public:
	Soldier(Board b) :Chess(b) {};
	virtual void Move(Board& b, position& fromPos, position& toPos) override;
};


class GameManager
{
private:
	vector<Chess*> on_board;
	int current_player; // 1:red, 2:black
	Board board;
	Viewer viewer;
	Chess player[2];
	ofstream wFile;

public:
	GameManager() { current_player = 0; }
	int getCurrent_player();
	void play();

	// 選擇執哪一子 -> 寫在main -> Chess c = new 類別(看type是什麼); c.Move(); 即可實現子類別的Move()
	void chooseChess(int);
	void read();//loop: 呼叫寫檔
};



/*
//GameManager Example
if (state == MOVE_PIECE)
{
	on_board[...]->OnMove(...);
	//do sth...
	if (cross_river) //兵卒過河後可以橫移
	{
		on_board[...]->SetCrossRiver(...);
		//do std...
	}
	
		1. Display
		2. Check gameover(將死 欠行 投降 個人時間用盡)
		3. Switch player
	
}
*/