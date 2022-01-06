#include <stdio.h>

extern int * g_mines;
extern int * g_revealed;

extern int g_width;
extern int g_height;

void renderBoard(){
    //Render top border
    for(int x = 0; x < g_width + 2; x ++){
        printf("+");    
    }
    printf("\n");

    //Loop through rows
    for(int y = 0; y < g_height; y ++){
        
        //Left border
        printf("+");

        //Loop through spaces in a row (moving left to right)
        for(int x = 0; x < g_width; x++){
            printf("#");
        }
        
        //Right border
        printf("+");
        printf("\n");
    }

    //Render bottom border
    for(int x = 0; x < g_width + 2; x ++){
        printf("+");    
    }
    printf("\n");
}