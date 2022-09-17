#ifndef FILEIO
#define FILEIO

#include <stdio.h>

///////////////////// функции ввода-вывода //////////////////////////////////

//Читает посимвольно строку из потока ввода и записывает её в s[]
//lim - размер массива s[]
//символ новой строки в коне файла рекомендую поставить, чтобы строки потом не слиплись
int getline2(int outputStr[], int lim, FILE* inputFile) {
	int i; int c;
	for (i = 0; i < lim - 1 && (c = getc(inputFile)) != '\n' && c != EOF; i++)
        outputStr[i] = c;
	if(c == '\n')
        outputStr[i++] = '\n';
    outputStr[i] = '\0';
	return i;
}

//puts s[] to file out
void fprint(int s[], FILE* out) { 
	for (int i = 0; s[i] != '\0'; i++)
		putc(s[i], out);
}

#endif
