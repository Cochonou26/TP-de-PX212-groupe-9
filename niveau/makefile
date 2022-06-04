CFLAGS=-g -Wall
LDFLAGS=-lm
CC=gcc

main: main.o lectureTableau.o affichageTableau.o util.o
	${CC} -o $@ ${CFLAGS} $^ ${LDFLAGS}
.c.o:
	${CC} ${CFLAGS} -c $<
clean:
	rm main
	rm *.o
