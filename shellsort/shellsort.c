#include <stdio.h>

#define N 100

void shellsort(int v[], int n);

main() {
	int a[N];
	for (int i = 0; i < N; i++) {
		a[i] = N - i;
		printf("%d ", a[i]);
	}
	printf("\n");	
	shellsort(a, N);
	for (int i = 0; i < N; i++)
		printf("%d ", a[i]);
}

void shellsort(int v[], int n) { //WORKS!
	int gap, i, j, temp;
	for (gap = n / 2; gap > 0; gap /= 2)
		for (i = gap; i < n; i++) {
			temp = v[i];
			for (j = i - gap; j >= 0 && temp < v[j]; j -= gap) {
				v[j + gap] = v[j];
			}
			v[j + gap] = temp;
		}
}