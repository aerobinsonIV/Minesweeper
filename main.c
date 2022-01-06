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
    printf("Height is %d\n", g_height);

    setSpace(3, 3, g_mines, 1);

    renderBoard();

    return 0;
}
