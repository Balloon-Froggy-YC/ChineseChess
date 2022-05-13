#include "GameManager.h"

int GameManager::getCurrent_player() { return current_player; }

void GameManager::read()
{
    ifstream cmd;
    cmd.open("command.txt");

    while (!cmd.eof())
    {
        string sub; // sub command: a line of the file
        getline(cmd, sub);
        string player = sub.substr(0, sub.find(","));
        // find "n" in "Action"
        string actor = sub.substr(sub.find("n") + 4, 2);
        actor.erase(actor.find(" "));
        string action = sub.substr(sub.find("("));

        //========================================
        // fetch the data to the right type
        int plyr = stoi(player);
        current_player = plyr;
        if (getCurrent_player() == 1) // red
        {
            switch (actor[0])
            {
            case 'G': // General

                break;
            case 'A': // Advisor

                break;
            case 'E': // Elephant

                break;
            case 'C': // Chariot / Cannon
                if (actor[1] == 'h') // Chariot
                {
                }
                else // Cannon
                {
                }
                    break;
            case 'H': // Horse

                break;
            case 'S': // Soldier

                break;
            default:
                break;
            }
        }
        else //black
        {
        } /*=====repeat the switch on above=====*/

        stringstream ssPos;
        ssPos << action;
        int temp;
        // vector to store initial & destined position
        // Priority: x1->y1->x2->y2
        vector <int> pos;
        while (ssPos >> temp)
            pos.push_back(temp);
    }
    cmd.close();
}

void GameManager::play()
{
    wFile.open("now.txt");
    if (!wFile.is_open())
    {
        cout << "[ERROR] cannot open the file to be written.\n";
        return;
    }
    current_player = 1;
    //初始化盤面
    board.initializeBoard();

    //確認是否結束
    while (1/*check_end(board)*/)
    {
        //換對方走
        if (current_player == 0)
            current_player = 1;
        else
            current_player = 0;


        board.Print();
        chooseChess(current_player);

    }
}

void GameManager::chooseChess(int current_player)
{
    position fromPos;
    position toPos;
    cout << "choose a chess (in form x y):";
    cin >> fromPos.x >> fromPos.y;
    cout << "choose a destination (in form x y):";
    cin >> toPos.x >> toPos.y;

    player[current_player].Move(board, fromPos, toPos);

}