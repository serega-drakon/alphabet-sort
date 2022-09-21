///////////////////// Двумерный массив /////////////////////////////

#include "intArray2d.h"
#include <stdio.h>

#define READ 0
#define WRITE 1

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

//read
int array2d_r(int x, int y) {
    if((x >= 0)&&(x < MAX_X) && (y >= 0) && (y < MAX_Y))
        return array2d_Main(READ, x, y, 0);
    else{
        printf("array2d_r: element x = %d, y = %d is not belongs to array\n",x,y);
        return 0;
    }
}

//write
int array2d_w(int x, int y, int value) {
    if((x >= 0)&&(x < MAX_X) && (y >= 0) && (y < MAX_Y))
        return array2d_Main(WRITE, x, y, value);
    else{
        printf("array2d_r: element x = %d, y = %d is not belongs to array\n",x,y);
        return 0;
    }
}
