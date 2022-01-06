#include <stdio.h>

#include "board.h"
#include "userInteraction.h"

int * g_mines;
int * g_revealed;

int g_width;
int g_height;

int main(){
    printf("Hello world\n");

    initBoard(5, 8, 12);

    printf("Width is %d\n", g_width);
    printf("Width is %d\n", g_height);

    renderBoard();

    return 0;
}
