#include <stdio.h>
#include "int_array_2d_old.h"

void loadfromfile2d(FILE* in);
void savetofile2d(FILE* out);
void fprint(int s[], FILE* out);
int getline(int s[], int lim, FILE* in);

main() { /* TEST */
	FILE* in;
	FILE* out;
	in = fopen("in.txt", "r");
	out = fopen("out.txt", "w");



	fclose(in);
	fclose(out);
}

int nextfreeY_2d = 0;

void loadfromfile2d(FILE* in) {
	int line[MAX_X];
	extern int nextfreeY_2d;
	int x, y = 0;
	for (; getline(line, MAX_X, in) > 0 && nextfreeY_2d < MAX_Y; nextfreeY_2d++)
		for (x = 0; x < MAX_X && (array_2d_w(x, y++, line[x])) != '\0'; x++)
			;
}

void savetofile2d(FILE* out) {
	extern int nextfreeY_2d;
	int line[MAX_X];
	for (int y = 0; y < nextfreeY_2d; y++) {
		copytostr(y, line);
		fprint(line, out);
	}
}

void reset_save2d(void) {
	extern int nextfreeY_2d;
	nextfreeY_2d = 0;
}

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