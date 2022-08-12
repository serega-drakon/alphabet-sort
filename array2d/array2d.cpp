#include <stdio.h>

#define READ 0
#define WRITE 1
#define MAX_X 3
#define MAX_Y 3

int array_2d(int x, int y, const _Bool mode, const int value);
void copyY(int y1, int y2);
void copytostr(int y, int s[]);
void copyfromstr(int y, int s[]);
void swapY(int y1, int y2);
int alphabetY(int y1, int y2);

main() { /* test */
	//array_2d test:
	for (int i = 0; i < MAX_Y; i++)
		for (int j = 0; j < MAX_X; j++)
			array_2d(j, i, WRITE, getchar());
	for (int i = 0; i < MAX_Y; i++) {
		for (int j = 0; j < MAX_X; j++)
			printf("%c", array_2d(j, i, READ, 0));
		printf("\n");
	}
	//swapY test:
	printf("swap!\n");
	swapY(1, 2);
	for (int i = 0; i < MAX_Y; i++) {
		for (int j = 0; j < MAX_X; j++)
			printf("%c", array_2d(j, i, READ, 0));
		printf("\n");
	}
	printf("swap!\n");
	swapY(0, 1);
	for (int i = 0; i < MAX_Y; i++) {
		for (int j = 0; j < MAX_X; j++)
			printf("%c", array_2d(j, i, READ, 0));
		printf("\n");
	}
	//alphabetY test:
	printf("alphabetY: %d, %d\n", alphabetY(0, 1), alphabetY(1, 2));
	//copyY test:
	printf("copy!\n");
	copyY(1, 2);
	for (int i = 0; i < MAX_Y; i++) {
		for (int j = 0; j < MAX_X; j++)
			printf("%c", array_2d(j, i, READ, 0));
		printf("\n");
	}
	//copytostr test:
	printf("copy to str!\n");
	int line[4];
	copytostr(0, line);
	line[3] = '\0';
	for(int i = 0; i < 4; i++)
		printf("%c", line[i]);
	printf("\n");
	copytostr(1, line);
	for (int i = 0; i < 4; i++)
		printf("%c", line[i]);
	printf("\n");
	copytostr(2, line);
	for (int i = 0; i < 4; i++)
		printf("%c", line[i]);
	printf("\n");
}

int arr2d[MAX_X * MAX_Y];

int array_2d(int x, int y, const _Bool mode, const int value) {//WORKS!
	if(x < MAX_X && y < MAX_Y && x >= 0 && y >= 0)
		if (mode) { //write
			arr2d[y * MAX_X + x] = value;
			return value;
		}
		else { //read
			return arr2d[y * MAX_X + x];
		}
	else
		printf("array_2d: error this element of array does not exist: x - %d, y - %d\n", x, y);
	return -1;
}

//swap y1 line and y2
void swapY(int y1, int y2) {//WORKS!
	if (y1 < MAX_Y && y2 < MAX_Y && y1 >= 0 && y2 >= 0) {
		int temp;
		for (int x = 0; x < MAX_X; x++) {
			temp = array_2d(x, y1, READ, 0);
			array_2d(x, y1, WRITE, array_2d(x, y2, READ, 0));
			array_2d(x, y2, WRITE, temp);
		}
	}
	else 
		printf("swapY: error these Y does not exist in array_2d: %d or %d", y1, y2);
}

//copy y1 line to y2
void copyY(int y1, int y2) { //WORKS!
	if (y1 < MAX_Y && y2 < MAX_Y && y1 >= 0 && y2 >= 0)
		for (int x = 0; x < MAX_X; x++)
			array_2d(x, y2, WRITE, array_2d(x, y1, READ, 0));
	else
		printf("copyY: error these Y does not exist in array_2d: %d or %d", y1, y2);
}

//str s has bigger or equal size than MAX_X
void copytostr(int y, int s[]) { //WORKS!
	if (y < MAX_Y && y >= 0)
		for (int x = 0; x < MAX_X && (s[x] = array_2d(x, y, READ, 0)) != '\0'; x++)
			;
	else
		printf("copytostr: error that Y does not exist in array_2d: %d", y);
}

//str s has bigger or equal size than MAX_X
void copyfromstr(int y, int s[]) {
	if (y < MAX_Y && y >= 0)
		for (int x = 0; x < MAX_X && array_2d(x, y, WRITE, s[x]) != '\0'; x++)
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
		for (; isletter(array_2d(i, y1, READ, 0)) == 0; i++);
		for (; isletter(array_2d(j, y2, READ, 0)) == 0; j++);
		st1 = isletter(array_2d(i, y1, READ, 0));
		st2 = isletter(array_2d(j, y2, READ, 0));
		if (st1 == 1)
			c1 = array_2d(i, y1, READ, 0) - 'a';
		else if (st1 == 2)
			c1 = array_2d(i, y1, READ, 0) - 'A';
		else if (st1 == -1)
			c1 = -1;

		if (st2 == 1)
			c2 = array_2d(j, y2, READ, 0) - 'a';
		else if (st2 == 2)
			c2 = array_2d(j, y2, READ, 0) - 'A';
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

