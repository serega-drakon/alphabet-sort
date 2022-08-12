#ifndef INT_ARRAY_2D
#define INT_ARRAY_2D

#include <stdio.h>

#define MAX_X 3
#define MAX_Y 3

int arr2d[MAX_X * MAX_Y];

int array_2d_r(int x, int y) {
	if (x < MAX_X && y < MAX_Y && x >= 0 && y >= 0)
		return arr2d[y * MAX_X + x];
	else
		printf("array_2d_r: error this element of array does not exist: x - %d, y - %d\n", x, y);
	return 0;
}

int array_2d_w(int x, int y, int value) {
	if (x < MAX_X && y < MAX_Y && x >= 0 && y >= 0) {
		arr2d[y * MAX_X + x] = value;
		return value;
	}
	else
		printf("array_2d_w: error this element of array does not exist: x - %d, y - %d\n", x, y);
	return 0;
}

//swap y1 line and y2
void swapY(int y1, int y2) {//WORKS!
	if (y1 < MAX_Y && y2 < MAX_Y && y1 >= 0 && y2 >= 0) {
		int temp;
		for (int x = 0; x < MAX_X; x++) {
			temp = array_2d_r(x, y1);
			array_2d_w(x, y1, array_2d_r(x, y2));
			array_2d_w(x, y2, temp);
		}
	}
	else
		printf("swapY: error these Y does not exist in array_2d: %d or %d", y1, y2);
}

//copy y1 line to y2
void copyY(int y1, int y2) { //WORKS!
	if (y1 < MAX_Y && y2 < MAX_Y && y1 >= 0 && y2 >= 0)
		for (int x = 0; x < MAX_X; x++)
			array_2d_w(x, y2, array_2d_r(x, y1));
	else
		printf("copyY: error these Y does not exist in array_2d: %d or %d", y1, y2);
}

//str s has bigger or equal size than MAX_X
void copytostr(int y, int s[]) { //WORKS!
	if (y < MAX_Y && y >= 0)
		for (int x = 0; x < MAX_X && (s[x] = array_2d_r(x, y)) != '\0'; x++)
			;
	else
		printf("copytostr: error that Y does not exist in array_2d: %d", y);
}

//str s has bigger or equal size than MAX_X
void copyfromstr(int y, int s[]) {
	if (y < MAX_Y && y >= 0)
		for (int x = 0; x < MAX_X && array_2d_w(x, y, s[x]) != '\0'; x++)
			;
	else
		printf("copyfromstr: error that Y does not exist in array_2d: %d", y);
}

//returns 0 if strings are the same
//1 if fisrt is higher
//2 if second is higher
int alphabetY(int y1, int y2) //WORKS!
{
	int isletter(int a);
	if (y1 >= MAX_Y || y2 >= MAX_Y || y1 < 0 || y2 < 0) {
		printf("alphabetY: error, these Y does not exist: %d or %d", y1, y2);
		return -1;
	}
	short st1, st2;
	int c1, c2;
	int i = 0, j = 0;
	do {
		for (; isletter(array_2d_r(i, y1)) == 0; i++);
		for (; isletter(array_2d_r(j, y2)) == 0; j++);
		st1 = isletter(array_2d_r(i, y1));
		st2 = isletter(array_2d_r(j, y2));
		if (st1 == 1)
			c1 = array_2d_r(i, y1) - 'a';
		else if (st1 == 2)
			c1 = array_2d_r(i, y1) - 'A';
		else if (st1 == -1)
			c1 = -1;

		if (st2 == 1)
			c2 = array_2d_r(j, y2) - 'a';
		else if (st2 == 2)
			c2 = array_2d_r(j, y2) - 'A';
		else if (st2 == -1)
			c2 = -1;

		if (c1 < c2)
			return 1;
		else if (c2 < c1)
			return 2;
	} while (st1 != -1 && st2 != -1 && c1 == c2 && i++ < MAX_X && j++ < MAX_X);
	return 0;
}

//ASCII
//returns -1 if it is \0
//returns 0 if it is not letter
//returns 1 if it is eng letter in lowercase
//returns 2 if it is eng letter in uppercase
int isletter(int a) { //TESTED
	if (a >= 'a' && a <= 'z')
		return 1;
	else if (a >= 'A' && a <= 'Z')
		return 2;
	else if (a == '\0')
		return -1;
	else
		return 0;
}

#endif