///////////////////// Двумерный массив /////////////////////////////

#include "intArray2d.h"

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
    return array2d_Main(READ, x, y, 0);
}

//write
int array2d_w(int x, int y, int value) {
    return array2d_Main(WRITE, x, y, value);
}
