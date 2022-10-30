#include <stdlib.h>
#include <stdio.h>
#include "arbore.h"

int main() {

	t_rb_arbore t;
	t_rb_node* r, * n;
	int x;

	printf("root= ");
	scanf_s("%d", &x);

	r = MakeRoot(&t, x);

	printf("\nintroduceti pana la citirea lui 0\n");
	printf("x= ");
	scanf_s("%d", &x);

	while (x != 0) {
		n = CreateNode(x);
		RbInsert(&t, n);
		printf("\nx= ");
		scanf_s("%d", &x);
	}

	printf("\nIn Order Walk:\n");
	InOrderWalk(r);

	return 0;
}