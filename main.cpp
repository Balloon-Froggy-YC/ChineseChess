#include <iostream>
#include "GameManager.h"

int main()
{
	GameManager game();
	int status = 1; // 0:end 1:restart 2:read-file
	while (status != 0)
	{
		//game();

		cin >> status;//結束嗎?
		/*
		if(status == 1)
			game.restart();
		else if(status == 2)
			game.readFile();
		*/
	}

	return 0;

}