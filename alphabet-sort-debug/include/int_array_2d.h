#ifndef INT_ARRAY_2D
#define INT_ARRAY_2D

/* DEBUG VERSION */

#include <stdio.h>
#include "fileio.h"

//Размеры массива
#define MAX_X 300
#define MAX_Y 8000

int arr2d[MAX_X * MAX_Y];

//read
int array_2d_r(int x, int y) {
	if (x < MAX_X && y < MAX_Y && x >= 0 && y >= 0)
		return arr2d[y * MAX_X + x];
	else
		printf("array_2d_r: error this element of array does not exist: x - %d, y - %d\n", x, y);
	return 0;
}

//write
int array_2d_w(int x, int y, int value) {
	if (x < MAX_X && y < MAX_Y && x >= 0 && y >= 0) {
		arr2d[y * MAX_X + x] = value;
		return value;
	}
	else
		printf("array_2d_w: error this element of array does not exist: x - %d, y - %d\n", x, y);
	return 0;
}

//copy y1 line to y2
void copyY(int y1, int y2) { 
	if (y1 < MAX_Y && y2 < MAX_Y && y1 >= 0 && y2 >= 0)
		for (int x = 0; x < MAX_X; x++)
			array_2d_w(x, y2, array_2d_r(x, y1));
	else
		printf("copyY: error these Y does not exist in array_2d: %d or %d\n", y1, y2);
}

//str s has bigger or equal size than MAX_X
//if '\0' does not exist
void copytostr(int y, int s[]) {
	if (y < MAX_Y && y >= 0)
		for (int x = 0; x < MAX_X && (s[x] = array_2d_r(x, y)) != '\0'; x++)
			;
	else
		printf("copytostr: error that Y does not exist in array_2d: %d\n", y);
}

//str s has bigger or equal size than MAX_X
//if '\0' does not exist
void copyfromstr(int y, int s[]) {
	if (y < MAX_Y && y >= 0)
		for (int x = 0; x < MAX_X && array_2d_w(x, y, s[x]) != '\0'; x++)
			;
	else
		printf("copyfromstr: error that Y does not exist in array_2d: %d\n", y);
}

int nextfreeY_2d = 0;

void loadfromfile2d(FILE* in) { 
	int line[MAX_X];
	extern int nextfreeY_2d;
	int x;
	for (; _getline(line, MAX_X, in) > 0 && nextfreeY_2d < MAX_Y - 1; nextfreeY_2d++)
		//оставляет одну строку в запасе для буфера в main.c
		copyfromstr(nextfreeY_2d, line);
}

void savetofile2d(FILE* out) {
	extern int nextfreeY_2d;
	int line[MAX_X];
	for (int y = 0; y < nextfreeY_2d; y++) {
		copytostr(y, line);
		fprint(line, out);
	}
}

void reset_save2d(void) {
	extern int nextfreeY_2d;
	nextfreeY_2d = 0;
}


//returns 0 if strings are the same
//1 if fisrt is higher
//2 if second is higher
int alphabetRUY(int y1, int y2) //works with ASCII
{
	//error check
	if (y1 >= MAX_Y || y2 >= MAX_Y || y1 < 0 || y2 < 0) {
		printf("alphabetY: error, these Y does not exist: %d or %d\n", y1, y2);
		return -1;
	}
	short st1, st2;
	int c1, c2;
	int i = 0, j = 0;
	do {
		//search for next letter
		for (; (st1 = isletter(array_2d_r(i, y1))) != 3 && st1 != 4 && st1 != -1; i++)
			;
		for (; (st2 = isletter(array_2d_r(j, y2))) != 3 && st2 != 4 && st2 != -1; j++)
			;
        //"alphabetization"
		if (st1 == 3)							//FIXME: Не учитывает букву Ё
			c1 = array_2d_r(i, y1) - 224; 
		else if (st1 == 4)
			c1 = array_2d_r(i, y1) - 192;
		else if (st1 == -1)
			c1 = 255 - 224 + 1;

		if (st2 == 3)
			c2 = array_2d_r(j, y2) - 224;
		else if (st2 == 4)
			c2 = array_2d_r(j, y2) - 192;
		else if (st2 == -1)
			c2 = 255 - 224 + 1;

		//comparison
		if (c1 < c2)
			return 1;
		else if (c2 < c1)
			return 2;
	} while (st1 != -1 && st2 != -1 && c1 == c2 && i++ < MAX_X && j++ < MAX_X);
	return 0;
}


/* Дальше можешь не смотреть, это скорее так для меня аналоги предыдущих функций */

//swap y1 line and y2
void swapY(int y1, int y2) {
	if (y1 < MAX_Y && y2 < MAX_Y && y1 >= 0 && y2 >= 0) {
		int temp;
		for (int x = 0; x < MAX_X; x++) {
			temp = array_2d_r(x, y1);
			array_2d_w(x, y1, array_2d_r(x, y2));
			array_2d_w(x, y2, temp);
		}
	}
	else
		printf("swapY: error these Y does not exist in array_2d: %d or %d\n", y1, y2);
}

int alphabetENGY(int y1, int y2) //works with ASCII
{
	//analog of RU version, see it for comments
	if (y1 >= MAX_Y || y2 >= MAX_Y || y1 < 0 || y2 < 0) {
		printf("alphabetY: error, these Y does not exist: %d or %d\n", y1, y2);
		return -1;
	}
	short st1, st2;
	int c1, c2;
	int i = 0, j = 0;
	do {
		for (; (st1 = isletter(array_2d_r(i, y1))) != 1 && st1 != 2 && st1 != -1; i++)
			;
		for (; (st2 = isletter(array_2d_r(j, y2))) != 1 && st2 != 2 && st2 != -1; j++)
			;
		if (st1 == 1)
			c1 = array_2d_r(i, y1) - 'a';
		else if (st1 == 2)
			c1 = array_2d_r(i, y1) - 'A';
		else if (st1 == -1)
			c1 = 'Z' > 'z' ? 'Z' + 1 : 'z' + 1;

		if (st2 == 1)
			c2 = array_2d_r(j, y2) - 'a';
		else if (st2 == 2)
			c2 = array_2d_r(j, y2) - 'A';
		else if (st2 == -1)
			c2 = 'Z' > 'z' ? 'Z' + 1 : 'z' + 1;

		if (c1 < c2)
			return 1;
		else if (c2 < c1)
			return 2;
	} while (st1 != -1 && st2 != -1 && c1 == c2 && i++ < MAX_X && j++ < MAX_X);
	return 0;
}


#endif