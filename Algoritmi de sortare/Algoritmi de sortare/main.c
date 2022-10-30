#include <stdlib.h>
#include <stdio.h>
#include "Sortari.h"

int main() {

	int arr[100], n;
	printf("Lungime vector= ");
	scanf_s("%d", &n);

	printf("\n");
	for (int i = 1; i <= n; i++) {
		scanf_s("%d", &arr[i]);
	}

	PrintArray(arr, n);
	InsertionSort(arr, n);
	PrintArray(arr, n);

	return 0;
}