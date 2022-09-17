#ifndef ALPHABET_SORT_NEW_FUNCS2D_H
#define ALPHABET_SORT_NEW_FUNCS2D_H

#include "fileio.h"
#include "int_array_2d.h"

///////////////////// функции для работы с массивом /////////////////////////////

//copy y1 line to y2
void copyY(int y1, int y2) {
    for (int x = 0; x < MAX_X; x++)
        array_2d_w(x, y2, array_2d_r(x, y1));
}

//str s has bigger or equal size than MAX_X
//if '\0' does not exist
void copyToStr(int y, int s[]) {
    int x;
    for (x = 0; x < MAX_X && (str[x] = array_2d_r(x, y)) != '\0'; x++)
        ;
    str[x] = '\0';
}

//str s has bigger or equal size than MAX_X
//if '\0' does not exist
void copyFromStr(int y, int s[]) {
    int x;
    for (x = 0; x < MAX_X && array_2d_w(x, y, str[x]) != '\0'; x++)
        ;
    str[x] = '\0';
}

// можно загрузиться сразу с нескольких файлов)    //UPDATE: перешел к ссылке вместо глобальной переменной
int loadFromFile2d(FILE* inputFile, int *nextfreeY) {
    int line[ MAX_X ];
    int x;
    for (; getline_(line, MAX_X, inputFile) > 0 && (*nextfreeY) < MAX_Y; (*nextfreeY)++)
        copyfromstr(*nextfreeY, line);
    if((*nextfreeY) == MAX_Y && getline_(line, MAX_X, inputFile) > 0)
        printf("error: массив переполнен, но программа отсортирует все что может\n");
}

void saveToFile2d(FILE* out, int *nextfreeY_2d) {      //UPDATE: перешел к ссылке вместо глобальной переменной
    int line[ MAX_X ];
    for (int y = 0; y < *nextfreeY_2d; y++) {
        copytostr(y, line);
        fprint(line, out);
    }
}

#endif //ALPHABET_SORT_NEW_FUNCS2D_H
