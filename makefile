CFLAGS=-g -Wall
LDFLAGS=-lm
CC=gcc

main: maintemp.o lectureTableau.o affichageTableau.o util.o deplacement.o io.o positionObjectif.o
	${CC} -o $@ ${CFLAGS} $^ ${LDFLAGS}
.c.o:
	${CC} ${CFLAGS} -c $<
clean:
	rm -f main
	rm -f *.o
