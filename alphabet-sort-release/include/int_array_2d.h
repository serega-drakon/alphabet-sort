#ifndef INT_ARRAY_2D
#define INT_ARRAY_2D

/* RELEASE VERSION */

#include <stdio.h>
#include "fileio.h"

//Размеры массива   //UPDATE
#define MAX_X 300
#define MAX_Y 8000
#define READ 0
#define WRITE 1

         //UPDATE
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

int nextFreeY(int flag, int value){
    static int nextfreeY_2d = 0;
    switch(flag){
        case READ:
            return nextfreeY_2d;
        case WRITE:
            nextfreeY_2d = value;
            return value;
    }
}

//read        //UPDATE
int array_2d_r(int x, int y) {
    return arr2d_Main(READ, x, y, 0);
}

//write        //UPDATE
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

int nextfreeY_2d = 0;

// можно загрузиться сразу с нескольких файлов)
void loadFromFile2d(FILE* in) {
	int line[ MAX_X ];
	extern int nextfreeY_2d;
	int x;
	for (; _getline(line, MAX_X, in) > 0 && nextfreeY_2d < MAX_Y; nextfreeY_2d++)
		copyfromstr(nextfreeY_2d, line);
}

void saveToFile2d(FILE* out) {
	extern int nextfreeY_2d;
	int line[ MAX_X ];
	for (int y = 0; y < nextfreeY_2d; y++) {
		copytostr(y, line);
		fprint(line, out);
	}
}

void reset_Save2d(void) {
	extern int nextfreeY_2d;
	nextfreeY_2d = 0;
}

                     //UPDATE
//returns 0 if strings are the same
//1 if first is higher
//2 if second is higher
int alphabetRUY(int y1, int s[]) //works with ASCII
{
	int st1, st2;
	int i = 0, j = 0;
	do {
		//search for next letter
		for (; (st1 = isletter(array_2d_r(i, y1))) != 3 && st1 != 4 && st1 != -1; i++)
			;
		for (; (st2 = isletter(s[j])) != 3 && st2 != 4 && st2 != -1; j++)
			;
        //"alphabetization"
        st1 = alphabetPosRu(array_2d_r(i, y1));
        st2 = alphabetPosRu(s[j]);
		//comparison
		if (st1 < st2)
			return 1;
		else if (st2 < st1)
			return 2;
	} while (st1 != (255 - 224 + 11) && st2 != (255 - 224 + 11) && i++ < MAX_X && j++ < MAX_X);
	return 0;
}

#endif
