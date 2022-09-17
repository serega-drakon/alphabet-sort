#ifndef ALPHABET_SORT_NEW_FUNCS2D_H
#define ALPHABET_SORT_NEW_FUNCS2D_H

#include <stdio.h>

void copyY(int fromY, int toY);
void copyToStr(int lineNum, int outputStr[]);
void copyFromStr(int lineNum, int inputStr[]);
int loadFromFile2d(FILE* inputFile, int *nextfreeY);
void saveToFile2d(FILE* outputFile, int *nextfreeY);

#endif
