#include <stdio.h>

#define READ 0
#define WRITE 1
#define MAX_X 3
#define MAX_Y 3

int array_2d(int x, int y, const _Bool mode, const int value);
void swapY(int y1, int y2);

main() { /* test */
	for (int i = 0; i < MAX_Y; i++)
		for (int j = 0; j < MAX_X; j++)
			array_2d(j, i, WRITE, getchar());
	for (int i = 0; i < MAX_Y; i++)
		for (int j = 0; j < MAX_X; j++)
			printf("%c", array_2d(j, i, READ, 0));

}

int static arr2d[MAX_X * MAX_Y];

//WORKS!
int array_2d(int x, int y, const _Bool mode, const int value) {
	if (mode) { //write
		if (x < MAX_X && y < MAX_Y) {
			arr2d[y * MAX_X + x] = value;
			return 0;
		}
		else
			printf("arr..2d: error this element of arrange does not exist: x - %d, y - %d\n", x, y);
	}
	else { //read
		if (x < MAX_X && y < MAX_Y)
			return arr2d[y * MAX_X + x];
		else
			printf("arr..2d: error this element of arrange does not exist: x - %d, y - %d\n", x, y);
	}
	return -1;
}

void swapY(int y1, int y2) {

}