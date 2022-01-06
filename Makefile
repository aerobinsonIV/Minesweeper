all:
	gcc -g -c board.c -o board.o
	gcc -g -c main.c -o main.o
	gcc -g -c userInteraction.c -o userInteraction.o
	gcc -o minesweeper main.o board.o userInteraction.o
	rm *.o