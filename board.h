#ifndef BOARD_H
#define BOARD_H

int getSpace(int x, int y, int * boardPointer);

int setSpace(int x, int y, int * boardPointer, int value);

int initBoard(int width, int height, int numMines);

#endif