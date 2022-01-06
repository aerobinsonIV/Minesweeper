all:
	gcc -c board.c -o board.o
	gcc -c main.c -o main.o
	gcc -c userInteraction.c -o userInteraction.o
	gcc -o minesweeper main.o board.o userInteraction.o
	rm *.o