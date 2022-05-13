#pragma once
#include"Board.h"
#include"Chess.h"
#include"GameManager.h"
#include"Viewer.h"

typedef struct position {
	int x;
	int y;
}position;


// ========== 基本棋子，abstract class ==========
class Chess
{
public:
	string type;	// 將general 士advisor 象elephant 車chariot 馬horse 炮cannon 兵soldier
	int current_player;		// 1 red (row > 5 on the board initially) ; 2 black (row < 4 on the board initially)
	static Board b;

	Chess(Board board, int player)
	{
		current_player = player;
		b = board;
	}

	void setType(string input);
	string getType();
	int getCurrentPlayer();

	// 可以選擇的棋子
	//void availableChess(Board& const board);

	// 選擇執哪一子 -> 寫在main -> Chess c = new 類別(看type是什麼); c.Move(); 即可實現子類別的Move()
	//void chooseChess(Chess current_player);

	// 從fromPos走到toPos (基本走法)
	virtual void Move(Board& b, position& fromPos, position& toPos);
};

// ========== General ==========
class General : public Chess	// 將 : 1.不過田 2.不能斜走 (3.被吃掉、王見王 皆輸掉遊戲)
{
public:
	General(Board b, int current_player) :Chess(b, current_player) {};
	virtual void Move(Board& b, position& fromPos, position& toPos) override;
};

// ========== Advisor ==========
class Advisor : public Chess	// 士 : 1.不過田 2.只能斜走
{
public:
	Advisor(Board b, int current_player) :Chess(b, current_player) {};
	virtual void Move(Board& b, position& fromPos, position& toPos) override;
};

// ========== Elephant ==========
class Elephant : public Chess	// 象 : 1.不過河 2.田字走 3.擠象眼(田字中間不可有棋)
{
public:
	Elephant(Board b, int current_player) :Chess(b, current_player) {};
	virtual void Move(Board& b, position& fromPos, position& toPos) override;
};

// ========== Chariot ==========
class Chariot : public Chess	// 車 : 1.直橫皆不受距離移動
{
public:
	Chariot(Board b, int current_player) :Chess(b, current_player) {};
	virtual void Move(Board& b, position& fromPos, position& toPos) override;
};

// ========== Horse ==========
class Horse : public Chess		// 馬 : 1.日字走 2.拐馬腳(前進方向 緊鄰馬的位子不可有棋)
{
public:
	Horse(Board b, int current_player) :Chess(b, current_player) {};
	virtual void Move(Board& b, position& fromPos, position& toPos) override;
};

// ========== Cannon ==========
class Cannon : public Chess		// 炮 : 1.不吃棋時走法與車相同 2.吃棋時跳吃
{
public:
	Cannon(Board b, int current_player) :Chess(b, current_player) {};
	virtual void Move(Board& b, position& fromPos, position& toPos) override;
};

// ========== Soldier ==========
class Soldier : public Chess	// 兵 : 1.過河前只能前行 2.過河後只能左右前行不可後退
{
public:
	Soldier(Board b, int current_player) :Chess(b, current_player) {};
	virtual void Move(Board& b, position& fromPos, position& toPos) override;
};