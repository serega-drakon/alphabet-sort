#include <stdio.h>
#include "include/int_array_2d.h"

main() { //only ANSI txt!
	FILE* in;
	FILE* out;
	in = fopen("main_in.txt", "r");
	out = fopen("main_out.txt", "w");
	loadfromfile2d(in);

	//shell's sort algorithm
	extern int nextfreeY_2d;
	int gap, i, j;
	for(gap = nextfreeY_2d / 2; gap > 0; gap /= 2)
		for (i = gap; i < nextfreeY_2d; i++) {
			copyY(i, nextfreeY_2d);
			for (j = i - gap; j >= 0 && alphabetRUY(nextfreeY_2d, j) == 1; j -= gap)
				copyY(j, j + gap);
			if(j + gap != i)
				copyY(nextfreeY_2d,j + gap);
		}

	savetofile2d(out);
	fclose(in);
	fclose(out);
}