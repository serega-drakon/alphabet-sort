///////////////////// языковые функции //////////////////////////////////

#include "alphabet.h"
#include "intArray2d.h"

#define LINE_TERMINATOR 255 - 224 + 11
#define FRST_DIGIT_IN_ALPH 255 - 224 + 1
#define CHAR_A_LOW 224
#define CHAR_A_UP 192
#define CHAR_YA_LOW 255
#define CHAR_YA_UP 223

//Дает 3 если кириллица в нижнем регистре
// 4 - кириллица в верхнем
int isletter(int a) { //works with ASCII
    if (a >= 'a' && a <= 'z')
        return 1;
    else if (a >= 'A' && a <= 'Z')
        return 2;
    else if (a >= CHAR_A_LOW && a <= CHAR_YA_LOW)
        return 3;
    else if (a >= CHAR_A_UP && a <= CHAR_YA_UP)
        return 4;
    else if (a == '\0')
        return -1;
    else if (a >= '1' && a <= '9')
        return -2;
    else
        return 0;
}

//выдает позицию данной буквы по алфавиту,
//в алфавит включены цифры, они стоят после всех букв
//нулевой символ стоит после всех остальных
int alphabetPosRu(int a){
    switch(isletter(a)) {
        case 3: //строчные
            return a - CHAR_A_LOW;
        case 4: //заглавные
            return a - CHAR_A_UP;
        case -1:
            return LINE_TERMINATOR;// '\0' идет после всех
            //'я' - 'а' + 10цифр + 1
        case -2: //цифры стоят после букв
            return FRST_DIGIT_IN_ALPH + a - '0';
        default:
            return -1;
    }
}

//returns 0 if strings are the same
//1 if first is higher
//2 if second is higher
int compareRU(int frstLineNum, int scndLineStr[]) //works with ASCII
{
    int letterToCmp1, letterToCmp2;
    int i = 0, j = 0;
    do {
        //search for next letter
        for (; (letterToCmp1 = isletter(array2d_r(i, frstLineNum))) != 3 && letterToCmp1 != 4 && letterToCmp1 != -1 && letterToCmp1 != -2; i++)
            ;
        for (; (letterToCmp2 = isletter(scndLineStr[j])) != 3 && letterToCmp2 != 4 && letterToCmp2 != -1 && letterToCmp2 != -2; j++)
            ;
        //"alphabetization"
        letterToCmp1 = alphabetPosRu(array2d_r(i, frstLineNum));
        letterToCmp2 = alphabetPosRu(scndLineStr[j]);
        //comparison
        if (letterToCmp1 < letterToCmp2)
            return 1;
        else if (letterToCmp2 < letterToCmp1)
            return 2;
    } while (letterToCmp1 != LINE_TERMINATOR && letterToCmp2 != LINE_TERMINATOR && i++ < MAX_X && j++ < MAX_X);
    return 0;
}