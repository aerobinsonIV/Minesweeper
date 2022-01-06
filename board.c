#include <stdlib.h>

extern int * g_mines;
extern int * g_revealed;

extern int g_width;
extern int g_height;

//Given a coordinate pair, return a pointer to the int representing that location
int * getMinesAddr(int x, int y){
    //Board has row major ordering:
    // 1 2 3 4
    // 5 6 7 8
    // ...

    int row_offset = g_width * y; // For each row, add the number of spaces in a row
    int column_offset = x; // For each column, add one

    return g_mines + row_offset + column_offset;
}

int getSpace(int x, int y){
    return *getMinesAddr(x, y);
}

int setSpace(int x, int y, int value){
    // TODO: Make sure value is 0 or 1

    *getMinesAddr(x, y) = value;
    return 0;
}

int initBoard(int width, int height, int numMines){
    // TODO: Add param validation with different return codes for different problems

    g_width = width;
    g_height = height;

    //calloc(num items, size of each item in bytes)
    g_mines = (int *) calloc(width * height, sizeof(int));
    g_revealed = (int *) calloc(width * height, sizeof(int));
    
    return 0;
}