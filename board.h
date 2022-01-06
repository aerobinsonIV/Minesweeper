#ifndef BOARD_H
#define BOARD_H

int getSpace(int x, int y);

int setSpace(int x, int y, int value);

int initBoard(int width, int height, int numMines);

#endif