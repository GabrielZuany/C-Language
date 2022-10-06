#include <stdio.h>
#include "tGame.h"

int main(){
    tGame game;
    game = SetGameValues(game);
    printf("\nWelcome to Tic Tac Toe:\n\nPlayer 1 is X and Player 2 is O\n\nEnjoy it!\n\n");
    PrintGame(game);
    PlayGame(game);
    return 0;
}