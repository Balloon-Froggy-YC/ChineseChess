#include"GameManager.h"
using namespace std;
// ========== Chess class ========== //
void Chess::setType(string input)
{
	//type = input;
}

int Chess::getType()
{
	return type;
}

int Chess::getCurrentPlayer()
{
	return current_player;
}

void Chess::Move(Board& b, position& fromPos, position& toPos)
{
	if (b.board[toPos.y][toPos.x] == ' ' && b.board[fromPos.y][fromPos.x] != ' ') {
		b.board[toPos.y][toPos.x] = b.board[fromPos.y][fromPos.x];
		b.board[fromPos.y][fromPos.x] = ' ';
	}
}

// ========== General class ========== //
void General::Move(Board& b, position& fromPos, position& toPos)
{
	bool chessBeyond = false;		// 確認toPos為對方的棋或空白

	// player red
	if (getCurrentPlayer() == 1) {
		// 過田
		if (toPos.x < 3 || toPos.x > 5 || toPos.y < 7) {
			cout << "wrong move\n";
		}
		// 田內
		else {
			// 斜著走
			if (abs(fromPos.x - toPos.x) == 1 && abs(fromPos.y - toPos.y) == 1) {
				cout << "wrong move\n";
			}
			// 沒斜著走
			else if (fromPos.x == toPos.x || fromPos.y == toPos.y) {
				if (b.board[toPos.y][toPos.x] == ' ' /*|| b.board[toPos.y][toPos.x] == black*/) {
					chessBeyond = true;
				}
			}
		}
	}
	// player black
	else {
		// 過田
		if (toPos.x < 3 || toPos.x > 5 || toPos.y > 2) {
			cout << "wrong move\n";
		}
		// 田內
		else {
			// 斜著走
			if (abs(fromPos.x - toPos.x) == 1 && abs(fromPos.y - toPos.y) == 1) {
				cout << "wrong move\n";
			}
			// 沒斜著走
			else if (fromPos.x == toPos.x || fromPos.y == toPos.y) {
				if (b.board[toPos.y][toPos.x] == ' ' /*|| b.board[toPos.y][toPos.x] == red*/) {
					chessBeyond = true;
				}
			}
		}
	}

	if (chessBeyond == true) {
		b.board[toPos.y][toPos.x] = b.board[fromPos.y][fromPos.x];
		b.board[fromPos.y][fromPos.x] = ' ';
	}

}

// ========== Advisor class ========== //
void Advisor::Move(Board& b, position& fromPos, position& toPos)
{
	bool chessBeyond = false;		// 確認toPos為對方的棋或空白

	// player red
	if (getCurrentPlayer() == 1) {
		// 過田
		if (toPos.x < 3 || toPos.x > 5 || toPos.y < 7) {
			cout << "wrong move\n";
		}
		// 田內
		else {
			// 沒斜著走
			if (fromPos.x == toPos.x || fromPos.y == toPos.y) {
				cout << "wrong move\n";
			}
			// 斜著走
			else if (abs(fromPos.x - toPos.x) == 1 && abs(fromPos.y - toPos.y) == 1) {
				if (b.board[toPos.y][toPos.x] == ' ' /*|| b.board[toPos.y][toPos.x] == black*/) {
					chessBeyond = true;
				}
			}
		}
	}
	// player black
	else {
		// 過田
		if (toPos.x < 3 || toPos.x > 5 || toPos.y > 2) {
			cout << "wrong move\n";
		}
		// 田內
		else {
			// 沒斜著走
			if (fromPos.x == toPos.x || fromPos.y == toPos.y) {
				cout << "wrong move\n";
			}
			// 斜著走
			else if (abs(fromPos.x - toPos.x) == 1 && abs(fromPos.y - toPos.y) == 1) {
				if (b.board[toPos.y][toPos.x] == ' ' /*|| b.board[toPos.y][toPos.x] == red*/) {
					chessBeyond = true;
				}
			}
		}
	}

	if (chessBeyond == true) {
		b.board[toPos.y][toPos.x] = b.board[fromPos.y][fromPos.x];
		b.board[fromPos.y][fromPos.x] = ' ';
	}
}

// ========== Elephant class ========== //
void Elephant::Move(Board& b, position& fromPos, position& toPos)
{
	bool chessInMiddle = false;		// 確認有沒有擠象眼
	bool chessBeyond = false;		// 確認toPos為對方的棋或空白

	// wrong move 
	if (fromPos.x == toPos.x || fromPos.y == toPos.y) {
		cout << "wrong move\n";
	}
	// wrong move (沒走田字)
	else if (abs(fromPos.x - toPos.x) != 2 || abs(fromPos.y - toPos.y) != 2) {
		cout << "wrong move\n";
	}
	// maybe right move (check chessInMiddle and chessBeyond)
	else {
		// player red
		if (getCurrentPlayer() == 1) {
			// 過河 -> wrong
			if (toPos.y < 5) {
				cout << "wrong move\n";
			}
			// 未過河
			else {
				// 向上移動 (左上 右上)
				if (fromPos.y - toPos.y == 2 && fromPos.x - toPos.x == 2) {
					if (b.board[fromPos.y - 1][fromPos.x - 1] != ' ') {
						chessInMiddle = true;
					}
				}
				else if (fromPos.y - toPos.y == 2 && toPos.y - fromPos.y == 2) {
					if (b.board[fromPos.y - 1][fromPos.x + 1] != ' ') {
						chessInMiddle = true;
					}
				}
				// 向下移動 (左下 右下)
				if (toPos.y - fromPos.y == 2 && fromPos.x - toPos.x == 2) {
					if (b.board[fromPos.y + 1][fromPos.x - 1] != ' ') {
						chessInMiddle = true;
					}
				}
				else if (toPos.y - fromPos.y == 2 && toPos.x - fromPos.x == 2) {
					if (b.board[fromPos.y + 1][fromPos.x + 1] != ' ') {
						chessInMiddle = true;
					}
				}

				if (b.board[toPos.y][toPos.x] == ' ' /*|| b.board[toPos.y][toPos.x] == black*/) {
					chessBeyond = true;
				}
			}
		}
		// player black
		else {
			// 過河 -> wrong
			if (toPos.y > 4) {
				cout << "wrong move\n";
			}
			// 未過河
			else {
				// 向上移動 (左上 右上)
				if (fromPos.y - toPos.y == 2 && fromPos.x - toPos.x == 2) {
					if (b.board[fromPos.y - 1][fromPos.x - 1] != ' ') {
						chessInMiddle = true;
					}
				}
				else if (fromPos.y - toPos.y == 2 && toPos.y - fromPos.y == 2) {
					if (b.board[fromPos.y - 1][fromPos.x + 1] != ' ') {
						chessInMiddle = true;
					}
				}
				// 向下移動 (左下 右下)
				if (toPos.y - fromPos.y == 2 && fromPos.x - toPos.x == 2) {
					if (b.board[fromPos.y + 1][fromPos.x - 1] != ' ') {
						chessInMiddle = true;
					}
				}
				else if (toPos.y - fromPos.y == 2 && toPos.x - fromPos.x == 2) {
					if (b.board[fromPos.y + 1][fromPos.x + 1] != ' ') {
						chessInMiddle = true;
					}
				}

				if (b.board[toPos.y][toPos.x] == ' ' /*|| b.board[toPos.y][toPos.x] == red*/) {
					chessBeyond = true;
				}
			}
		}

		if (chessInMiddle == false && chessBeyond == true) {
			b.board[toPos.y][toPos.x] = b.board[fromPos.y][fromPos.x];
			b.board[fromPos.y][fromPos.x] = ' ';
		}
		else {
			cout << "wrong move\n";
		}
	}

}

// ========== Chariot class ========== //
void Chariot::Move(Board& b, position& fromPos, position& toPos)
{
	bool chessInMiddle = false;		// 確認中間有沒有隔著棋
	bool chessBeyond = false;		// 確認toPos為對方的棋或空白

	// wrong move (走斜線)
	if (fromPos.x != toPos.x && fromPos.y != toPos.y) {
		cout << "wrong move\n";
	}
	// wrong move (不動)
	else if (fromPos.x == toPos.x && fromPos.y == toPos.y) {
		cout << "wrong move\n";
	}
	// maybe right move (check chessInMiddle and chessBeyond)
	else {
		// vertical move
		if (fromPos.x == toPos.x) {
			if (toPos.y > fromPos.y) {
				for (int i = fromPos.y; i < toPos.y; i++) {
					if (b.board[i][fromPos.x] != ' ') {
						chessInMiddle = true;
						break;
					}
				}
			}
			else {
				for (int i = toPos.y; i < fromPos.y; i++) {
					if (b.board[i][fromPos.x] != ' ') {
						chessInMiddle = true;
						break;
					}
				}
			}
		}
		// horizontal move
		else {
			if (toPos.x > fromPos.x) {
				for (int i = fromPos.x; i < toPos.x; i++) {
					if (b.board[fromPos.y][i] != ' ') {
						chessInMiddle = true;
						break;
					}
				}
			}
			else {
				for (int i = toPos.x; i < fromPos.x; i++) {
					if (b.board[fromPos.y][i] != ' ') {
						chessInMiddle = true;
						break;
					}
				}
			}
		}

		if (b.board[toPos.y][toPos.x] != ' ') {
			if (getCurrentPlayer() == 1 /*&& b.board[toPos.y][toPos.x] == black*/) {
				chessBeyond = true;
			}
			else if (getCurrentPlayer() == 2 /*&& b.board[toPos.y][toPos.x] == red*/) {
				chessBeyond = true;
			}
		}
		else if (b.board[toPos.y][toPos.x] == ' ') {
			chessBeyond = true;
		}

		if (chessInMiddle == true || chessBeyond == false) {
			cout << "wrong move\n";
		}
		else {
			b.board[toPos.y][toPos.x] = b.board[fromPos.y][fromPos.x];
			b.board[fromPos.y][fromPos.x] = ' ';
		}
	}
}

// ========== Horse class ========== //
void Horse::Move(Board& b, position& fromPos, position& toPos)
{
	bool chessInMiddle = false;		// 確認有沒有拐馬腳
	bool chessBeyond = false;		// 確認toPos為對方的棋或空白

	// wrong move
	if (fromPos.x == toPos.x || fromPos.y == toPos.y) {
		cout << "wrong move\n";
	}
	// wrong move (沒走日字)
	else if (abs(fromPos.x - toPos.x) + abs(fromPos.y - toPos.y) != 3) {
		cout << "wrong move\n";
	}
	// maybe right move (check chessInMiddle and chessBeyond)
	else {
		// 向上移動
		if (fromPos.y - toPos.y == 2) {
			if (b.board[fromPos.y - 1][fromPos.x] != ' ') {
				chessInMiddle = true;
			}
		}
		// 向下移動
		else if (toPos.y - fromPos.y == 2) {
			if (b.board[fromPos.y + 1][fromPos.x] != ' ') {
				chessInMiddle = true;
			}
		}
		// 向左移動
		else if (fromPos.x - toPos.x == 2) {
			if (b.board[fromPos.y][fromPos.y - 1] != ' ') {
				chessInMiddle = true;
			}
		}
		// 向右移動
		else if (toPos.x - fromPos.x == 2) {
			if (b.board[fromPos.y][fromPos.x + 1] != ' ') {
				chessInMiddle = true;
			}
		}

		if (b.board[toPos.y][toPos.x] != ' ') {
			if (getCurrentPlayer() == 1 /*&& b.board[toPos.y][toPos.x] == black*/) {
				chessBeyond = true;
			}
			else if (getCurrentPlayer() == 2 /*&& b.board[toPos.y][toPos.x] == red*/) {
				chessBeyond = true;
			}
		}
		else if (b.board[toPos.y][toPos.x] == ' ') {
			chessBeyond = true;
		}

		if (chessInMiddle == true || chessBeyond == false) {
			cout << "wrong move\n";
		}
		else {
			b.board[toPos.y][toPos.x] = b.board[fromPos.y][fromPos.x];
			b.board[fromPos.y][fromPos.x] = ' ';
		}
	}

}

// ========== Cannon class ========== //
void Cannon::Move(Board& b, position& fromPos, position& toPos)
{
	bool chessInMiddle = false;		// 確認中間有沒有隔著一棋
	bool chessBeyond = false;		// 確認toPos為對方的棋或空白

	// wrong move (走斜線)
	if (fromPos.x != toPos.x && fromPos.y != toPos.y) {
		cout << "wrong move\n";
	}
	// wrong move (不動)
	else if (fromPos.x == toPos.x && fromPos.y == toPos.y) {
		cout << "wrong move\n";
	}
	// maybe right move (check chessInMiddle and chessBeyond)
	else {
		// vertical move
		if (fromPos.x == toPos.x) {
			if (toPos.y > fromPos.y) {
				for (int i = fromPos.y; i < toPos.y; i++) {
					if (b.board[i][fromPos.x] != ' ') {
						if (chessInMiddle == true) {		// 確保中間隔著不超過一棋
							chessInMiddle = false;
							break;
						}
						else {
							chessInMiddle = true;
						}
					}
				}
			}
			else {
				for (int i = toPos.y; i < fromPos.y; i++) {
					if (b.board[i][fromPos.x] != ' ') {
						if (chessInMiddle == true) {		// 確保中間隔著不超過一棋
							chessInMiddle = false;
							break;
						}
						else {
							chessInMiddle = true;
						}
					}
				}
			}
		}
		// horizontal move
		else {
			if (toPos.x > fromPos.x) {
				for (int i = fromPos.x; i < toPos.x; i++) {
					if (b.board[fromPos.y][i] != ' ') {
						if (chessInMiddle == true) {		// 確保中間隔著不超過一棋
							chessInMiddle = false;
							break;
						}
						else {
							chessInMiddle = true;
						}
					}
				}
			}
			else {
				for (int i = toPos.x; i < fromPos.x; i++) {
					if (b.board[fromPos.y][i] != ' ') {
						if (chessInMiddle == true) {		// 確保中間隔著不超過一棋
							chessInMiddle = false;
							break;
						}
						else {
							chessInMiddle = true;
						}
					}
				}
			}
		}

		if (b.board[toPos.y][toPos.x] != ' ') {
			if (getCurrentPlayer() == 1 /*&& b.board[toPos.y][toPos.x] == black*/) {
				chessBeyond = true;
			}
			else if (getCurrentPlayer() == 2 /*&& b.board[toPos.y][toPos.x] == red*/) {
				chessBeyond = true;
			}
		}
		else if (b.board[toPos.y][toPos.x] == ' ') {
			chessBeyond = true;
		}

		// 跳吃並移動
		if (chessInMiddle == true && chessBeyond == true) {
			b.board[toPos.y][toPos.x] = b.board[fromPos.y][fromPos.x];
			b.board[fromPos.y][fromPos.x] = ' ';
		}
		// 純移動
		else if (chessInMiddle == false && chessBeyond == true) {
			b.board[toPos.y][toPos.x] = b.board[fromPos.y][fromPos.x];
			b.board[fromPos.y][fromPos.x] = ' ';
		}
		else {
			cout << "wrong move\n";
		}
	}
}

// ========== Soldier class ========== //
void Soldier::Move(Board& b, position& fromPos, position& toPos)
{
	bool chessBeyond = false;		//確認toPos為對方的棋或空白

	// player red
	if (getCurrentPlayer() == 1) {
		// 過河
		if (fromPos.y < 5) {
			// wrong move (後退 斜著走 非走一格)
			if (toPos.y >= fromPos.y || (toPos.x != fromPos.x && toPos.y != fromPos.y) || abs(fromPos.x - toPos.x) > 1 || abs(fromPos.y - toPos.y) > 1) {
				cout << "wrong move\n";
			}
			// right move (吃棋 or 移動)
			else {
				if (b.board[toPos.y][toPos.x] == ' ' /*|| b.board[toPos.y][toPos.x] == black*/) {
					chessBeyond = true;
				}
			}
		}
		// 未過河
		else {
			// wrong move (後退 左右走 非走一格)
			if (toPos.y >= fromPos.y || toPos.x != fromPos.x || abs(fromPos.y - toPos.y) > 1) {
				cout << "wrong move\n";
			}
			// right move (吃棋 or 移動)
			else {
				if (b.board[toPos.y][toPos.x] == ' ' /*|| b.board[toPos.y][toPos.x] == black*/) {
					chessBeyond = true;
				}
			}
		}
	}
	// player black
	else {
		// 過河
		if (fromPos.y > 4) {
			// wrong move (後退 斜著走 非走一格)
			if (toPos.y <= fromPos.y || (toPos.x != fromPos.x && toPos.y != fromPos.y) || abs(fromPos.x - toPos.x) > 1 || abs(fromPos.y - toPos.y) > 1) {
				cout << "wrong move\n";
			}
			// right move (吃棋 or 移動)
			else {
				if (b.board[toPos.y][toPos.x] == ' ' /*|| b.board[toPos.y][toPos.x] == red*/) {
					chessBeyond = true;
				}
			}
		}
		// 未過河
		else {
			// wrong move (後退 左右走 非走一格)
			if (toPos.y <= fromPos.y || toPos.x != fromPos.x || abs(fromPos.y - toPos.y) > 1) {
				cout << "wrong move\n";
			}
			// right move (吃棋 or 移動)
			else {
				if (b.board[toPos.y][toPos.x] == ' ' /*|| b.board[toPos.y][toPos.x] == red*/) {
					chessBeyond = true;
				}
			}
		}
	}

	if (chessBeyond == true) {
		b.board[toPos.y][toPos.x] = b.board[fromPos.y][fromPos.x];
		b.board[fromPos.y][fromPos.x] = ' ';
	}
}