#include "table.h"

void hash_init(int t[], int m) {
	for (int j = 0; j <= m - 1; j++) {
		t[j] = -1;
	}
}

int hash_prim(int k, int m) {
	return k % m;
}

int hash_probe(int k, int i, int m) {
	return (hash_prim(k, m) + i) % m;
}

int hash_insert(int t[], int k, int m) {
	int i = 0;
	do {
		int j = hash_probe(k, i, m); /// pozitia de inserare

		if (t[j] == -1) {
			t[j] = k;  ///alocarea valori la pozitia gasita
			return j;
		}
		else {
			i++;
		}
	} while (i != m);

	return -1;
}

int hash_search(int t[], int k, int m) {
	int i = 0, j;

	do {
		j = hash_probe(k, i, m);

		if (t[j] == k) {
			return j;
		}
		
		i++;
	} while (i != m && t[j] != -1);
	return -1;
}

void hash_print(int t[], int m) {
	for (int j = 0; j <= m - 1; j++) {
		printf("%d ", t[j]);
	}
	printf("\n");
}

int hash_delete(int t[], int k, int m) {
	int j = hash_search(t, k, m);

	if (j > -1) {
		t[j] = -1;
	}
	else {
		return -1;
	}
}