#include <fstream>
//遊戲流程
class GameManager
{
	vector<Chess>on_board;
	int current_player;
	Board board;
	Viewer viewer;	
	Chess A, B;
	
};
//GameManager Example
if(state == MOVE_PIECE)
{
	on_board[...]->OnMove(...);
	//do sth...
	if(cross_river) //兵卒過河後可以橫移
	{
		on_board[...]->SetCrossRiver(...);
		//do std...
	}
	/*
		1. Display
		2. Check gameover(將死 欠行 投降 個人時間用盡)
		3. Switch player
	*/
}

void read(... pos pos player);
//loop: 呼叫寫檔