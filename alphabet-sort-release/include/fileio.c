///////////////////// функции ввода-вывода //////////////////////////////////
#include <stdio.h>
#include "fileio.h"

//Читает посимвольно строку из потока ввода и записывает её в outputStr[]
//lim - размер массива outputStr[]
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

//puts inputStr[] to file outputFile
void fprint(int inputStr[], FILE* outputFile) {
    for (int i = 0; inputStr[i] != '\0'; i++)
        putc(inputStr[i], outputFile);
}