CFLAGS=-g -Wall
LDFLAGS=-lm
CC=gcc
main: maintemp.o lireNiveau.o tailleNiveau.o trouverNiveau.o afficherNiveau.o
	${CC} -o $@ ${CFLAGS} $^ ${LDFLAGS}
.c.o:
	${CC} ${CFLAGS} -c $<
clean:
	rm *.o
	rm main 
