CFLAGS=-g -Wall -Werror
LDFLAGS=-lm
CC=gcc

main: maintemp.o lectureTableau.o affichageTableau.o util.o deplacement.o
	${CC} -o $@ ${CFLAGS} $^ ${LDFLAGS}
.c.o:
	${CC} ${CFLAGS} -c $<
clean:
	rm main
	rm *.o
