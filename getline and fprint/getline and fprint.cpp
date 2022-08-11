#include <stdio.h>
#include <Windows.h>

#define MAXLINE 100

int getline(int s[], int lim, FILE* in);
void fprint(char s[], FILE* out);

main() {
	SetConsoleCP(1251); //localization
	SetConsoleOutputCP(1251); // encoding of txt must be ANCI !!!!

	FILE* infile;
	FILE* outfile;
	infile = fopen("C:\\Users\\slepy\\source\\repos\\alphabet-sort-new\\getline and fprint\\in.txt", "r");
	outfile = fopen("C:\\Users\\slepy\\source\\repos\\alphabet-sort-new\\getline and fprint\\out.txt", "w");

	int line[MAXLINE];
	printf("%d\n", getline(line, MAXLINE, infile));

	for (int i = 0; line[i] != '\0'; i++)
		printf("%c", line[i]);

	fprint(line, outfile);

	fclose(outfile);
	fclose(infile);
}

int getline(int s[], int lim, FILE* in) { //WORKS!
	int i; int c;
	for (i = 0; i < lim - 1 && (c = getc(in)) != '\n' && c != EOF; i++)
		s[i] = c;
	if (c == '\n')
		s[i++] = '\n';
	s[i] = '\0';
	return i;
}

void fprint(int s[], FILE* out) { //WORKS! 
	for (int i = 0; s[i] != '\0'; i++)
		putc(s[i], out);
}