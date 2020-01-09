#include <stdio.h>
#include <stdlib.h>

int *merge(int *a, int *b, int an, int bn) {
	int *ret = malloc(sizeof(int) * (an+bn));
	int ai = 0;
	int bi = 0;
	int k = 0;
	while (ai < an && bi < bn) {
		if (a[ai] < b[bi]) {
			ret[k] = a[ai];
			ai++;
		} else {
			ret[k] = b[bi];
			bi++;
		}
		k++;
	}
	while (ai < an) {
		ret[k] = a[ai];
		ai++;
		k++;
	}
	while (bi < bn) {
		ret[k] = b[bi];
		bi++;
		k++;
	}
	return ret;
}

void merge_sort(int *a, int n) {
	if (n == 1) {
		return;
	}
	int mid = n / 2;
	merge_sort(a, mid);
	merge_sort(a + mid, n - mid);
	int *temp = merge(a, a+mid, mid, n-mid);
	// int *temp = malloc(n * sizeof(int));
	// int i = 0;
	// int j = mid;
	// int counter = 0; // index in final array
	// while (i < mid && j < n) {
	// 	if (a[i] < a[j]) {
	// 		temp[counter] = a[i];
	// 		i++;
	// 	} else {
	// 		temp[counter] = a[j];
	// 		j++;
	// 	}
	// 	counter++;
	// }
	// while (i < mid) { //Only one of these 2 while loops will run (other's conditions will not be satisfied)
	// 	temp[counter] = a[i];
	// 	counter++;
	// 	i++;
	// }
	// while (j < n) {
	// 	temp[counter] = a[j];
	// 	counter++;
	// 	j++;
	// }
	for (int i = 0; i < n; i++) {
		a[i] = temp[i];
	}
	free(temp);
}

void sort(int a[], int n) {
	merge_sort(a, n);
}

int main() {
	int a[] = {48, -10, 0, 23, 5, -200, 30, 1923, 6};
	sort(a, 9);
	printf("[");
	for (int i = 0; i < 9; i++) {
		printf("%d ", a[i]);
	}
	printf("]\n");
	return 0;
}