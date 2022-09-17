#ifndef ALPHABET_SORT_NEW_FUNCS2D_H
#define ALPHABET_SORT_NEW_FUNCS2D_H

#include <stdio.h>

void copyY(int fromY, int toY);
void copyToStr(int y, int outputStr[]);
void copyFromStr(int y, int inputStr[]);
int loadFromFile2d(FILE* inputFile, int *nextfreeY);
void saveToFile2d(FILE* outputFile, int *nextfreeY);

#endif
