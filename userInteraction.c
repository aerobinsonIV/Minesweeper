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
            printf("%d", getSpace(x, y));
            printHorizontalSpace();
        }
        
        //Right border
        printf("+");
        printf("\n");
    }

    //Bottom border
    printHorizontalBorder();

}