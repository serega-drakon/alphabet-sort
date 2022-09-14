#ifndef FILEIO
#define FILEIO

#include <stdio.h>

//Читает посимвольно строку из потока ввода и записывает её в s[]
//lim - размер массива s[]
//символ новой строки в коне файла рекомендую поставить, чтобы строки потом не слиплись
int getline_(int s[], int lim, FILE* in) {
	int i; int c;
	for (i = 0; i < lim - 1 && (c = getc(in)) != '\n' && c != EOF; i++) 
		s[i] = c;
	if(c == '\n')
		s[i++] = '\n';
	s[i] = '\0';
	return i;
}

//puts s[] to file out
void fprint(int s[], FILE* out) { 
	for (int i = 0; s[i] != '\0'; i++)
		putc(s[i], out);
}

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

#endif
