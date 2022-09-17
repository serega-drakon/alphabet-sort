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
int array2d_Main(int flag, int x, int y, int value){
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
int array2d_r(int x, int y) {
    return arr2d_Main(READ, x, y, 0);
}

//write        //UPDATE: обертка к arr2d_Main
int array2d_w(int x, int y, int value) {
    return arr2d_Main(WRITE, x, y, value);
}

#endif
