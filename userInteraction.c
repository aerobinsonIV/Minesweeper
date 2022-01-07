#define HORIZONTAL_SPACING 2

#include <stdio.h>

#include "board.h"

extern int * g_mines;
extern int * g_revealed;

extern int g_width;
extern int g_height;

void printHorizontalSpace(){
    for(int i = 0; i < HORIZONTAL_SPACING; i ++){
        printf(" ");
    }
}

void printHorizontalBorder(){
    for(int x = 0; x < g_width + 2; x ++){
        printf("+");
        printHorizontalSpace();
    }
    printf("\n");
}

//THIS VERSION OF THE PROGRAM DOES NOT CONSIDER DIAGONALS ADJACENT

//Returns number of adjacent spaces to the given coords with value 1 on specified board array
int getAdjacentSum(int x, int y, int * boardArray){
    
    //XY coordinate pairs of all adjacent spaces
    const int numAdjacents = 4;
    int adjX[numAdjacents];
    int adjY[numAdjacents];

    adjX[0] = x + 1;
    adjY[0] = y;

    adjX[1] = x - 1;
    adjY[1] = y;

    adjX[2] = x;
    adjY[2] = y + 1;

    adjX[3] = x;
    adjY[3] = y - 1;

    int curX = 0;
    int curY = 0;

    int adjacentSum = 0;

    // Loop through all adjacent spaces
    for(int i = 0; i < numAdjacents; i ++){
        curX = adjX[i];
        curY = adjY[i];

        // If one of the adjacent spaces is off the board, skip it
        if(curX < 0 || curX >= g_width){
            continue;
        }

        if(curY < 0 || curY >= g_height){
            continue;
        }

        adjacentSum += getSpace(curX, curY, boardArray);
    }

    return adjacentSum;
}

void renderRevealedSpace(int x, int y){
    int spaceValue = getSpace(x, y, g_mines);
    
    if(spaceValue == 0){
        // no mine
        int numAdjacentMines = getAdjacentSum(x, y, g_mines);
        if(numAdjacentMines == 0){
            printf(" ");
        }else{
            printf("%d", numAdjacentMines);
        }
        
    }else if(spaceValue == 1){
        //Mine
        printf("X");
    }
}

void renderBoard(){
    // TODO: Add coordinate labels

    //Top border
    printHorizontalBorder();

    //Loop through rows
    for(int y = 0; y < g_height; y ++){
        
        //Left border
        printf("+");
        printHorizontalSpace();

        //Loop through spaces in a row (moving left to right)
        for(int x = 0; x < g_width; x++){
            if(getSpace(x, y, g_revealed)){
                renderRevealedSpace(x, y);   
            }else{
                printf("#");   
            }
            
            printHorizontalSpace();
        }
        
        //Right border
        printf("+");
        printf("\n");
    }

    //Bottom border
    printHorizontalBorder();

}

void clearInputBuffer(){
    int ch;
    while (((ch = fgetc(stdin)) != '\n') && (ch != EOF));
}

// TODO: Change these to reference, more stylistically correct than pointers. Maybe?
void getMoveFromUser(int * x, int * y){
    // TODO: Display one-time instruction message at beginning of program

    int _x = 0;
    int _y = 0;

    int scanfReturn = 0;

    // TODO: Display error message on invalid entry

    // Loop until user enters a valid move
    while(1){
        printf("Please enter your move: ");
        scanfReturn = scanf("%d %d", &_x, &_y);
        clearInputBuffer();

        // TODO: properly handle user entering nothing

        if(scanfReturn != 2){
            continue;
        }

        if(_x < 0 || _x >= g_width){
            continue;
        }

        if(_y < 0 || _y >= g_height){
            continue;
        }

        break;
    }

    *x = _x;
    *y = _y;
}