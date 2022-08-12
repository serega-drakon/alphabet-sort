#ifndef FILEIO
#define FILEIO

#include <stdio.h>

int getline(int s[], int lim, FILE* in) {
	int i; int c;
	for (i = 0; i < lim - 2 && (c = getc(in)) != '\n' && c != EOF; i++) 
		s[i] = c;
	if(c == '\n')
		s[i++] = '\n';
	s[i] = '\0';
	return i;
}

void fprint(int s[], FILE* out) { 
	for (int i = 0; s[i] != '\0'; i++)
		putc(s[i], out);
}

//ASCII
//returns -1 if it is \0
//returns 0 if it is not letter
//returns 1 if it is ENG letter in lowercase
//returns 2 if it is ENG letter in uppercase
//returns 3 if it is RU letter in lowercase
//returns 4 if it is RU letter in uppercase
int isletter(int a) { //FIXME
	if (a >= 'a' && a <= 'z')
		return 1;
	else if (a >= 'A' && a <= 'Z')
		return 2;
	else if (a >= ('à' & 255) && a <= ('ÿ' & 255))
		return 3;
	else if (a >= ('À' & 255) && a <= ('ß' & 255))
		return 4;
	else if (a == '\0')
		return -1;
	else
		return 0;
}

#endif
