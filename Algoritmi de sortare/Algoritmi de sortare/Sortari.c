#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "Sortari.h"

void PrintArray(int a[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

/// Insertion Sort ///

void InsertionSort(int a[], int n) {
    int key, i;

    for (int j = 2; j <= n; j++) {
        key = a[j];
        i = j - 1;

        while (i > 0 && a[i] > key) {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }
}

/// Merge Sort ///

void mergeLab(int a[], int p, int q, int r) {
    int left[100], right[100];
    int n1 = q - p + 1;
    int n2 = r - q;

    for (int i = 1; i <= n1; i++) {
        left[i] = a[p + i - 1];
    }
    for (int j = 1; j <= n2; j++) {
        right[j] = a[q + j];
    }

    left[n1 + 1] = INT_MAX;
    right[n2 + 1] = INT_MAX;

    int i = 1, j = 1;

    for (int k = p; k <= r; k++) {
        if (left[i] <= right[j]) {
            a[k] = left[i];
            i++;
        }
        else {
            a[k] = right[j];
            j++;
        }
    }
}

void MergeSortLab(int a[], int p, int r) {
    int q = 0;
    if (p < r) {
        q = (p + r) / 2;
        MergeSortLab(a, p, q);
        MergeSortLab(a, q + 1, r);
        mergeLab(a, p, q, r);
    }
}

/// Bubble sort ///
void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void BubbleSort(int arr[], int n) {
    for (int i = n + 1; i >= 1; i--) {
        for (int j = 1; j < i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
            }
        }
    }
}

/// Selection Sort ///
void SelectionSort(int arr[], int n) {
    int Min;
    for (int i = 1; i <= n; i++) {
        Min = i;
        for (int j = i + 1; j <= n; j++) {
            if (arr[j] < arr[Min]) {
                Min = j;
            }
        }
        swap(arr, Min, i);
    }
}