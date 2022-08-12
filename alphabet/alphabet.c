#include <stdio.h>
#include <Windows.h>
#include <string.h>

int isletter(int a);

//returns 0 if strings are the same
//1 if fisrt is higher
//2 if second is higher
main() {
	SetConsoleCP(1251); //localization
	SetConsoleOutputCP(1251); // encoding of txt must be ANCI !!!!
	char c;
	printf("%d\n",isletter(c = getchar()));

	printf("%d\n", isletter(207));


	char line1[] = "baa";
	char line2[] = "baab";
	int st1, st2;
	int c1, c2;
	int i = 0, j = 0;
	do {
		for (; !isletter(line1[i]); i++);
		for (; !isletter(line2[j]); j++);
		st1 = isletter(line1[i]);
		st2 = isletter(line2[j]);
		if (line1[i] != '\0')
			printf("line1: %c\n", line1[i]);
		else
			printf("line1: \\0\n");
		if (line2[j] != '\0')
			printf("line2: %c\n", line2[j]);
		else
			printf("line2: \\0\n");

		if (st1 == 1)
			c1 = line1[i] - 'a';
		else if (st1 == 2)
			c1 = line1[i] - 'A';
		else if (st1 == -1)
			c1 = 'Z' > 'z' ? 'Z' + 1 : 'z' + 1;

		if (st2 == 1)
			c2 = line2[j] - 'a';
		else if (st2 == 2)
			c2 = line2[j] - 'A';
		else if (st2 == -1)
			c2 = 'Z' > 'z' ? 'Z' + 1 : 'z' + 1;

		if (c1 < c2)
			printf("1");
		else if (c2 < c1)
			printf("2");
	} while (line1[i++] != '\0' && line2[j++] != '\0' && c1 == c2);
}

//ASCII
//returns -1 if it is \0
//returns 0 if it is not letter
//returns 1 if it is eng letter in lowercase
//returns 2 if it is eng letter in uppercase
int isletter(int a) { //FIXME
	if (a >= 'a' && a <= 'z')
		return 1;
	else if (a >= 'A' && a <= 'Z')
		return 2;
	else if (a >= ('а' & 255) && a <= ('я' & 255))
		return 3;
	else if (a >= ('А' & 255) && a <= ('Я' & 255))
		return 4;
	else if (a == '\0')
		return -1;
	else
		return 0;
}
