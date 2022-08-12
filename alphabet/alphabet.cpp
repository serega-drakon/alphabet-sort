#include <stdio.h>
#include <string.h>

int isletter(char a);

main() {
	char line1[] = "caaa";
	char line2[] = "baab";
	int st1, st2;
	int c1, c2;
	int i = 0, j = 0;
	do {
		for (; !isletter(line1[i]); i++);
		for (; !isletter(line2[j]); j++);
		st1 = isletter(line1[i]);
		st2 = isletter(line2[j]);
		printf("line1: %c\n", line1[i]);
		printf("line2: %c\n", line2[j]);

		if (st1 == 1)
			c1 = line1[i] - 'a';
		else if (st1 == 2)
			c1 = line1[i] - 'A';
		else if (st1 == -1)
			c1 = -1;

		if (st2 == 1)
			c2 = line2[j] - 'a';
		else if (st2 == 2)
			c2 = line2[j] - 'A';
		else if (st2 == -1)
			c2 = -1;

		if (c1 < c2)
			printf("1");
		else if (c2 < c1)
			printf("2");
		i++; j++;
	} while (line1[i] != '\0' && line2[j] != '\0' && c1 == c2);
}

//ASCII
//returns -1 if it is \0
//returns 0 if it is not letter
//returns 1 if it is eng letter in lowercase
//returns 2 if it is eng letter in uppercase
int isletter(char a) {
	if (a >= 'a' && a <= 'z')
		return 1;
	else if (a >= 'A' && a <= 'Z')
		return 2;
	else if (a == '\0')
		return -1;
	else 
		return 0;
}