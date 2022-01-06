all:
	gcc -c board.c -o board.o
	gcc -c main.c -o main.o
	gcc -o minesweeper main.o board.o
	rm *.o