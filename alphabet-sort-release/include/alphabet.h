#ifndef ALPHABET_SORT_NEW_ALPHABET_H
#define ALPHABET_SORT_NEW_ALPHABET_H

#include "int_array_2d.h"

///////////////////// языковые функции //////////////////////////////////

//UPDATE: теперь поддерживает цифры
//Дает 3 если кириллица в нижнем регистре
// 4 - кириллица в верхнем
int isletter(int a) { //works with ASCII
    if (a >= 'a' && a <= 'z')
        return 1;
    else if (a >= 'A' && a <= 'Z')
        return 2;
    else if (a >= 224 && a <= 255)
        return 3;
    else if (a >= 192 && a <= 223)
        return 4;
    else if (a == '\0')
        return -1;
    else if (a >= '1' && a <= '9')
        return -2;
    else
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
        for (; (st1 = isletter(array_2d_r(i, y1))) != 3 && st1 != 4 && st1 != -1 && st1!= -2; i++)
            ;
        for (; (st2 = isletter(s[j])) != 3 && st2 != 4 && st2 != -1 && st2 != -2; j++)
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


#endif //ALPHABET_SORT_NEW_ALPHABET_H
