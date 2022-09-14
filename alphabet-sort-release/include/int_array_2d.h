#ifndef INT_ARRAY_2D
#define INT_ARRAY_2D

/* RELEASE VERSION */

#include <stdio.h>
#include "fileio.h"

//Размеры массива   //UPDATE: added READ&WRITE
#define MAX_X 300
#define MAX_Y 8000
#define READ 0
#define WRITE 1

  //UPDATE: вместо глобальной переменной сделал основу и "обертки"
int arr2d_Main(int flag, int x, int y, int value){
    static int arr2d[MAX_X * MAX_Y];
    switch(flag){
        case READ:
            return arr2d[y * MAX_X + x];
        case WRITE:
            arr2d[y * MAX_X + x] = value;
            return arr2d[y * MAX_X + x];
    }
}

//read        //UPDATE: обертка к arr2d_Main
int array_2d_r(int x, int y) {
    return arr2d_Main(READ, x, y, 0);
}

//write        //UPDATE: обертка к arr2d_Main
int array_2d_w(int x, int y, int value) {
    return arr2d_Main(WRITE, x, y, value);
}

//copy y1 line to y2
void copyY(int y1, int y2) { 
	for (int x = 0; x < MAX_X; x++)
		array_2d_w(x, y2, array_2d_r(x, y1));
}

//str s has bigger or equal size than MAX_X
//if '\0' does not exist
void copytostr(int y, int s[]) {
    int x;
	for (x = 0; x < MAX_X && (s[x] = array_2d_r(x, y)) != '\0'; x++)
		;
    s[x] = '\0';
}

//str s has bigger or equal size than MAX_X
//if '\0' does not exist
void copyfromstr(int y, int s[]) {
    int x;
	for (x = 0; x < MAX_X && array_2d_w(x, y, s[x]) != '\0'; x++)
		;
    s[x] = '\0';
}

// можно загрузиться сразу с нескольких файлов)    //UPDATE: перешел к ссылке вместо глобальной переменной
void loadFromFile2d(FILE* in, int *nextfreeY_2d) {
	int line[ MAX_X ];
	int x;
	for (; getline_(line, MAX_X, in) > 0 && (*nextfreeY_2d) < MAX_Y; (*nextfreeY_2d)++)
		copyfromstr(*nextfreeY_2d, line);
    if((*nextfreeY_2d) == MAX_Y && getline_(line, MAX_X, in) > 0)
        printf("error: массив переполнен, но программа отсортирует все что может\n");
}

void saveToFile2d(FILE* out, int *nextfreeY_2d) {      //UPDATE: перешел к ссылке вместо глобальной переменной
	int line[ MAX_X ];
	for (int y = 0; y < *nextfreeY_2d; y++) {
		copytostr(y, line);
		fprint(line, out);
	}
}

#endif
