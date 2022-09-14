#ifndef FILEIO
#define FILEIO

#include <stdio.h>

///////////////////// функции ввода-вывода //////////////////////////////////

//Читает посимвольно строку из потока ввода и записывает её в s[]
//lim - размер массива s[]
//символ новой строки в коне файла рекомендую поставить, чтобы строки потом не слиплись
int getline_(int s[], int lim, FILE* in) {
	int i; int c;
	for (i = 0; i < lim - 1 && (c = getc(in)) != '\n' && c != EOF; i++) 
		s[i] = c;
	if(c == '\n')
		s[i++] = '\n';
	s[i] = '\0';
	return i;
}

//puts s[] to file out
void fprint(int s[], FILE* out) { 
	for (int i = 0; s[i] != '\0'; i++)
		putc(s[i], out);
}

#endif
