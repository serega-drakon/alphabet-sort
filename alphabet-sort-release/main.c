#include <stdio.h>
#include "include/intArray2d.h"
#include "include/funcs2d.h"
#include "include/alphabet.h"

int main(void) {
    enum errors{
        Success = 0,
        StackIsFull = 1,
        NoInputFile = 2,
        NoOutputFile = 3
    };

	FILE* in;
	FILE* out;
	in = fopen("main_in.txt", "r");
    out = fopen("main_out.txt", "w");
    //error check
    if(in == 0){
        printf("error: there are no main_in.txt");
        return NoInputFile;
    }
    if(out == 0) {
        printf("error: there are no main_out.txt");
        return NoOutputFile;
    }

    int nextfreeY_2d = 0;//следующая свободная позиция в массиве
	int status; //проверка на наличие ошибок
    status = loadFromFile2d(in, &nextfreeY_2d);

	//shell's sort algorithm
	int gap, i, j;
    int buf[ MAX_X ];
	for(gap = nextfreeY_2d / 2; gap > 0; gap /= 2)
		for (i = gap; i < nextfreeY_2d; i++) {
            copyToStr(i, buf);
			for (j = i - gap; j >= 0 && compareRU(j, buf) == 2; j -= gap)
				copyY(j, j + gap);
			if(j + gap != i)
                copyFromStr(j + gap, buf);
		}

	saveToFile2d(out, &nextfreeY_2d);
	fclose(in);
	fclose(out);

    switch(status){
        case -1:
            return StackIsFull;
        case 0:
            return Success;
    }
}

