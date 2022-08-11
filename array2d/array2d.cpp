#include <stdio.h>

#define READ 0
#define WRITE 1
#define MAX_X 3
#define MAX_Y 3

int array_2d(int x, int y, const _Bool mode, const int value);
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

}

int static arr2d[MAX_X * MAX_Y];


int array_2d(int x, int y, const _Bool mode, const int value) {//WORKS!
	if (mode) { //write
		if (x < MAX_X && y < MAX_Y) {
			arr2d[y * MAX_X + x] = value;
			return 0;
		}
		else
			printf("array_2d: error this element of arrange does not exist: x - %d, y - %d\n", x, y);
	}
	else { //read
		if (x < MAX_X && y < MAX_Y)
			return arr2d[y * MAX_X + x];
		else
			printf("array_2d: error this element of arrange does not exist: x - %d, y - %d\n", x, y);
	}
	return -1;
}

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
		printf("swapY: error that Y does not exist in array_2d: %d or %d", y1,y2);
}

int alphabetY(int y1, int y2)
{
	return 0;
}
