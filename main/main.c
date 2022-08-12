#include <stdio.h>
#include <Windows.h>
#include "int_array_2d.h"

main() {
	SetConsoleCP(1251); //localization
	SetConsoleOutputCP(1251); // encoding of txt must be ANCI !!!!
	FILE* in;
	FILE* out;
	in = fopen("main_in.txt", "r");
	out = fopen("main_out.txt", "w");
	loadfromfile2d(in);

	extern int nextfreeY_2d;

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
	int gap, i, j, temp[MAX_X];
	for(gap = (nextfreeY_2d + 1) / 2; gap > 0; gap /= 2)
		for (i = gap; i < (nextfreeY_2d + 1); i++) {
			copytostr(i,temp);
			for (j = i - gap; j >= 0 && alphabetRUY(i, j) == 1; j -= gap)
				copyY(j, j + gap);
			if(j + gap != i)
				copyfromstr(j + gap, temp);
		}

	savetofile2d(out);
	fclose(in);
	fclose(out);
}