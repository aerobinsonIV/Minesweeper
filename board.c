#include <stdlib.h>

extern int * g_mines;
extern int * g_revealed;

extern int g_width;
extern int g_height;

//Given a coordinate pair and a pointer to the start of the board array, 
//return a pointer to the int representing that location
int * coordsToPointer(int x, int y, int * boardPointer){
    //Board has row major ordering:
    // 1 2 3 4
    // 5 6 7 8
    // ...

    int row_offset = g_width * y; // For each row, add the number of spaces in a row
    int column_offset = x; // For each column, add one

    return boardPointer + row_offset + column_offset;
}

int getSpace(int x, int y, int * boardPointer){
    return *coordsToPointer(x, y, boardPointer);
}

int setSpace(int x, int y, int * boardPointer, int value){
    // TODO: Make sure value is 0 or 1

    *coordsToPointer(x, y, boardPointer) = value;
    return 0;
}

void placeMines(int numMines){
    int minesRemaining = numMines;

    //Set random seed (constant for ease of debugging)
    // TODO: Change this to be based on current time
    srand(42069);

    int randX = 0;
    int randY = 0;

    while(minesRemaining > 0){

        do{
            //Generate coordinates for a random space on the board until
            randX = rand() % g_width;
            randY = rand() % g_height;

            //Try again if we generated a space that already has a mine
        }while(getSpace(randX, randY, g_mines));

        setSpace(randX, randY, g_mines, 1);

        minesRemaining --;
    }
}

int initBoard(int width, int height, int numMines){
    // TODO: Add param validation with different return codes for different problems

    g_width = width;
    g_height = height;

    //calloc(num items, size of each item in bytes)
    g_mines = (int *) calloc(width * height, sizeof(int));
    g_revealed = (int *) calloc(width * height, sizeof(int));

    placeMines(numMines);
    
    return 0;
}