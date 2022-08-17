#ifndef FILEIO
#define FILEIO

#include <stdio.h>

//получает стоку из файла in, записывает ее в s[].
//lim - размер массива s[]
//рекомендую добавить '\n' в конец файла, чтобы строки после сортировки не склеились
int getline(int s[], int lim, FILE* in) {
	int i; int c;
	for (i = 0; i < lim - 1 && (c = getc(in)) != '\n' && c != EOF; i++) 
		s[i] = c;
	if(c == '\n')
		s[i++] = '\n';
	s[i] = '\0';
	return i;
}

//печатает строку s[] в файл out
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
	else if (a >= ('а' & 255) && a <= ('я' & 255))
		return 3;
	else if (a >= ('А' & 255) && a <= ('Я' & 255))
		return 4;
	else if (a == '\0')
		return -1;
	else
		return 0;
}

#endif
