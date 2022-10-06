#ifndef _TGAME_H_
#define _TGAME_H_

typedef struct{
    int player;
    int row;
    int column;
    char board[3][3];
}tGame;

tGame SetGameValues(tGame game);
void PlayGame(tGame game);
void PrintGame(tGame game);
int CheckWinner(tGame game);
int IsValidCell(tGame game, int row, int column);

#endif