int litSauvegarde(char *r)
{

	int c;

	if ((c = r) == -1)
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
