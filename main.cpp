#include <iostream>
using namespace std;
//init
const int SIZE  = 3;
char board[SIZE][SIZE] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
//to display board
void display_board()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << endl;
    }
}

//player
char currentPlayer = 'X';
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O':'X';
}

//move

bool move(int pos) //pos only from 1 to 9
{
    int row = (pos-1)/SIZE;
    int col = (pos-1)%SIZE;
    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = currentPlayer;
        return true;
    }
    else
    {
        return false;
    }
}

//check for win
bool checkWin()
{
    //check for straight win
    for (int i = 0; i < SIZE; i++)
    {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            return true;
    }
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return true;
    return false;
}

//check draw
bool checkDraw()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

int main()
{
    int position;
    bool gameWin = false;
    bool gameDraw = false;

    while (!gameWin && !gameDraw)
    {
        display_board();
        std::cout << "Player " << currentPlayer << " enter your move (1-9): ";
        std::cin >> position;

        if (move(position))
        {
            gameWin = checkWin();
            gameDraw = checkDraw();
            if (!gameWin && !gameDraw)
                switchPlayer();
        }
        else
        {
            std::cout << "Invalid move, try again" << endl;
        }
    }

    display_board();
    if (gameWin)    std::cout << "its a win for player " << currentPlayer << endl;
    else    std::cout << "its a draw" << endl;
    return 0;
}