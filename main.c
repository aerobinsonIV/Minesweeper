#include <stdio.h>
#include <stdlib.h>

#include "board.h"
#include "userInteraction.h"

int * g_mines;
int * g_revealed;

int g_width;
int g_height;

int main(){
    
    initBoard(7, 7, 10);

    int * moveX = malloc(sizeof(int));
    int * moveY = malloc(sizeof(int));

    //Main loop
    while(1){
        renderBoard();
        
        getMoveFromUser(moveX, moveY);
        
        setSpace(*moveX, *moveY, g_revealed, 1);
    }

    return 0;
}
