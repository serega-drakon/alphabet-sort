#ifndef ALPHABET_SORT_NEW_INTARRAY2D_H
#define ALPHABET_SORT_NEW_INTARRAY2D_H

#define MEM_ERR 1
#define MAX_X 300

//определяю только "пользовательские" функции
struct dArray;
int array_r(int x, int y);
int array_w(int x, int y, int value);
void arraySwitch(struct dArray *ptrArray);
void* arrayInit();
void arrayFree(struct dArray *ptrArray);
_Bool arrayMemErr();

#endif
