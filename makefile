main: fonctions.o main.o
	gcc -g -Wall -fsanitize=address -o main fonctions.o main.o

fonctions.o: fonctions.c
	gcc -o fonctions.o -c fonctions.c -g -Wall -fsanitize=address

main.o: main.c fonctions.h
	gcc -o main.o -c main.c -g -Wall -fsanitize=address
