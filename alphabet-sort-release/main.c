#include <stdio.h>
#include "include/intArray2d.h"
#include "include/funcs2d.h"
#include "include/alphabet.h"

enum errors{
    UnknownError = -1,
    Success = 0,
    MemoryError = 1,
    NoInputFile = 2,
    NoOutputFile = 3
};

int main(void) {
    //file initialization
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
    //array initialization
    struct dArray *array = arrayInit();
    arraySwitch(array);
    //loading from file
    int nextfreeY = 0;//следующая свободная позиция в массиве
	int status; //хранит код ошибки
    status = loadFromFile2d(in, &nextfreeY);
	//shell's sort algorithm
	int gap, i, j;
    int buf[ MAX_X ];
	for(gap = nextfreeY / 2; gap > 0; gap /= 2)
		for (i = gap; i < nextfreeY; i++) {
            copyToStr(i, buf);
			for (j = i - gap; j >= 0 && compareRU(j, buf) == 2; j -= gap)
				copyY(j, j + gap);
			if(j + gap != i)
                copyFromStr(j + gap, buf);
		}
    //saving&closing files&arrays
	saveToFile2d(out, &nextfreeY);
    arrayFree(array);
	fclose(in);
	fclose(out);
    //end
    switch(status){
        case MEM_ERR:
            return MemoryError;
        case 0:
            return Success;
        default:
            return UnknownError;
    }
}

