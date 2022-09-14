#include <stdio.h>
#include "include/int_array_2d.h"

int alphabetRUY(int y1, int s[]);

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

    int nextfreeY_2d = 0;//следующая свободная позиция в массиве (нужна для savetofile())
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

//UPDATE: новая функция
//выдает позицию данной буквы по алфавиту,
//в алфавит включены цифры, они стоят после всех букв
//нулевой символ стоит после всех остальных
int alphabetPosRu(int a){
    switch(isletter(a)) {
        case 3: //строчные
            return a - 224;
        case 4: //заглавные
            return a - 192;
        case -1:
            return 255 - 224 + 11;// '\0' идет после всех
            //'я' - 'а' + 10цифр + 1
        case -2: //цифры стоят после букв
            return 255 - 224 + 1 + a - '0';
        default:
            return -1;
    }
}

//UPDATE: сделал код более компактным исп. новую функцию
//returns 0 if strings are the same
//1 if first is higher
//2 if second is higher
int alphabetRUY(int y1, int s[]) //works with ASCII
{
    int st1, st2;
    int i = 0, j = 0;
    do {
        //search for next letter
        for (; (st1 = isletter(array_2d_r(i, y1))) != 3 && st1 != 4 && st1 != -1; i++)
            ;
        for (; (st2 = isletter(s[j])) != 3 && st2 != 4 && st2 != -1; j++)
            ;
        //"alphabetization"
        st1 = alphabetPosRu(array_2d_r(i, y1));
        st2 = alphabetPosRu(s[j]);
        //comparison
        if (st1 < st2)
            return 1;
        else if (st2 < st1)
            return 2;
    } while (st1 != (255 - 224 + 11) && st2 != (255 - 224 + 11) && i++ < MAX_X && j++ < MAX_X);
    return 0;
}