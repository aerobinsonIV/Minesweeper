#include <stdlib.h>

extern int * g_mines;
extern int * g_revealed;

extern int g_width;
extern int g_height;

int initBoard(int width, int height, int numMines){
    // TODO: Add param validation with different return codes for different problems

    g_width = width;
    g_height = height;

    //calloc(num items, size of each item in bytes)
    g_mines = (int *) calloc(width * height, sizeof(int));
    g_revealed = (int *) calloc(width * height, sizeof(int));
    
    return 0;
}