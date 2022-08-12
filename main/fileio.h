#ifndef FILEIO
#define FILEIO

#include <stdio.h>

int getline(int s[], int lim, FILE* in) { //TESTED
	int i; int c;
	for (i = 0; i < lim - 1 && (c = getc(in)) != '\n' && c != EOF; i++)
		s[i] = c;
	if (c == '\n')
		s[i++] = '\n';
	s[i] = '\0';
	return i;
}

void fprint(int s[], FILE* out) { //TESTED
	for (int i = 0; s[i] != '\0'; i++)
		putc(s[i], out);
}

#endif
