#include <termios.h>
#include <unistd.h> 
#include <stdio.h>

#define MAXSIZE 10 

int configureTerminal()
{
	struct termios new;
	if (tcgetattr(0,&new) == -1)
		return 1;
	new.c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
	new.c_lflag &= ~(ECHO);   // les touches tapées ne s'inscriront plus dans le terminal
	new.c_cc[VMIN] = 1;
	new.c_cc[VTIME] = 0;
	if (tcsetattr(0,TCSANOW,&new) == -1)
		return 1;
	return 0;
}

int litClavier() 
{
	char r[MAXSIZE];
	int c;

	if ((c = read(0,r,3)) == -1)
		return 0; 

	switch (r[0]) {
		case 27 :
			if ((c == 3) && (r[1] == 91))
				return (r[2] - 64);
			else
				return 0;
		default:
			return r[0];
	}
}

