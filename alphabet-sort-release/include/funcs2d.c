///////////////////// функции для работы с массивом /////////////////////////////

#include "funcs2d.h"
#include "fileio.h"
#include "intArray2d.h"

#define STACK_IS_FULL 2
#define FUNC_SUCCESS 0

//copy fromY line to toY
void copyY(int fromY, int toY) {
    for (int x = 0; x < MAX_X; x++)
        array_w(x, toY, array_r(x, fromY));
}

//outputStr has bigger or equal size than MAX_X
//if '\0' does not exist
void copyToStr(int lineNum, int outputStr[]) {
    int x;
    for (x = 0; x < MAX_X - 1 && (outputStr[x] = array_r(x, lineNum)) != '\0'; x++)
        ;
    outputStr[x] = '\0';
}

//inputStr has bigger or equal size than MAX_X
//if '\0' does not exist
int copyFromStr(int lineNum, int inputStr[]) {
    int x;
    for (x = 0; x < MAX_X - 1 && array_w(x, lineNum, inputStr[x]) != '\0'; x++)
        ;
    inputStr[x] = '\0';
    if(x == MAX_X){
        printf("copyFromStr(): stack is full\n");
        return STACK_IS_FULL;
    }
    else
        return FUNC_SUCCESS;
}

//можно загрузиться сразу с нескольких файлов)
int loadFromFile2d(FILE* inputFile, int *nextfreeY) {
    int line[ MAX_X ];
    int x;
    for (; getline2(line, MAX_X, inputFile) > 0 && arrayMemErr() == 0; (*nextfreeY)++)
        copyFromStr(*nextfreeY, line);

    if(arrayMemErr() == 1)
        return MEM_ERR;
    else
        return FUNC_SUCCESS;
}

void saveToFile2d(FILE* outputFile, int *nextfreeY) {
    int line[ MAX_X ];
    for (int y = 0; y < *nextfreeY; y++) {
        copyToStr(y, line);
        fprint(line, outputFile);
    }
}