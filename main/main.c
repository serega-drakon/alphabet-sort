#include <stdio.h>
#include "int_array_2d.h"

main() { //only ANSI txt!
	FILE* in;
	FILE* out;
	in = fopen("main_in.txt", "r");
	out = fopen("main_out.txt", "w");
	loadfromfile2d(in);
	/*	
	* алгоритм сортировки Шелла для чиселок:
	int gap, i, j, temp;
	for (gap = n / 2; gap > 0; gap /= 2)
		for (i = gap; i < n; i++) {
			temp = v[i];
			for (j = i - gap; j >= 0 && temp < v[j]; j -= gap) {
				v[j + gap] = v[j];
			}
			v[j + gap] = temp;
	}
	*/
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