#include <stdio.h>
#include <stdlib.h>

#include "board.h"
#include "userInteraction.h"

int * g_mines;
int * g_revealed;

int g_width;
int g_height;

int main(){
    
    initBoard(7, 7, 7);

    int * mainX = malloc(sizeof(int));
    int * mainY = malloc(sizeof(int));
    
    getMoveFromUser(mainX, mainY);

    printf("You entered %d, %d\n", *mainX, *mainY);

    return 0;
}
