#include <stdio.h>
#include "include/int_array_2d.h"
#include "funcs2d.h"
#include "alphabet.h"

int main(void) {
	FILE* in;
	FILE* out;
	in = fopen("main_in.txt", "r");
    out = fopen("main_out.txt", "w");
    //error check
    if(in == 0){
        printf("error: there are no main_in.txt");
        return -1;
    }
    if(out == 0) {
        printf("error: there are no main_out.txt");
        return -2;
    }

    int nextfreeY_2d = 0;//следующая свободная позиция в массиве
	loadFromFile2d(in, &nextfreeY_2d);

	//shell's sort algorithm
	int gap, i, j;
    int buf[ MAX_X ];
	for(gap = nextfreeY_2d / 2; gap > 0; gap /= 2)
		for (i = gap; i < nextfreeY_2d; i++) {
            copytostr(i, buf);
			for (j = i - gap; j >= 0 && alphabetRUY(j, buf) == 2; j -= gap)
				copyY(j, j + gap);
			if(j + gap != i)
                copyfromstr(j + gap, buf);
		}

	saveToFile2d(out, &nextfreeY_2d);
	fclose(in);
	fclose(out);
    return 0;
}

