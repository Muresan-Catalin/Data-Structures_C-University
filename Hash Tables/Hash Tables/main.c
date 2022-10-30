#include <stdlib.h>
#include <stdio.h>
#include "table.h"

int main() {

	int t[100], m, k, j;
	printf("Lungimea t= ");
	scanf_s("%d", &m);

	hash_init(t, m);

	printf("Dati numere pana la citirea lui 0: \n");
	scanf_s("%d", &k);

	while (k != 0) {
		j = hash_insert(t, k, m);
		printf("Cheia inserata la locatia %d\n", j);
		scanf_s("%d", &k);
	}

	hash_print(t, m);

	printf("\nCautare cheie\n");

	scanf_s("%d", &k);

	j = hash_search(t, k, m);
	if (j > -1) {
		printf("Cheia gasita la locatia %d\n", j);
	}
	else {
		printf("Cheia nu a fost gasita\n");
	}

	printf("Stergere cheie: ");
	scanf_s("%d", &k);

	j = hash_delete(t, k, m);
	if (j > -1) {
		printf("Cheie stearsa de la locatia %d\n", j);
		hash_print(t, m);
	}
	else {
		printf("Cheia nu a fost stearsa\n");
	}

	return 0;
}