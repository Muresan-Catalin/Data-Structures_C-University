#include <stdlib.h>
#include <stdio.h>
#include "Arbore.h"

int main() {

	t_arbore t;
	t_nod_arbore *n, *r, *s;
	int x;

	printf("Nodul radacina are val: ");
	scanf_s("%d", &x);

	r = MakeRoot(&t, x);

	printf("Introduceti x pana la citirea 0 \n");
	printf("x= ");
	scanf_s("%d", &x);

	while (x != 0) {
		n = CreateNod(x);
		TreeInsert(&t, n);
		printf("x= ");
		scanf_s("%d", &x);
	}

	printf("PreOrderWalk... \n");
	PreorderWalk(r);

	printf("\nPostOrderWalk... \n");
	PostorderWalk(r);

	printf("\nInOrderWalk... \n");
	InOrderWalk(r);

	/// CAUTAREA UNUI NOD ///

	printf("\n\nIntroduceti cheia pe care vreti sa o gasiti: ");
	scanf_s("%d", &x);

	n = TreeSearch(r, x);
	if (n == NULL) {
		printf("\nNodul nu a fost gasit RECURSIV\n");
	}
	else {
		printf("\nNodul a fost gasit RECURSIV\n");
	}

	n = ItTreeSearch(r, x);
	if (n == NULL) {
		printf("\nNodul nu a fost gasit ITERATIV\n");
	}
	else {
		printf("\nNodul a fost gasit ITERATIV\n");
	}

	/// GASIREA MINIMULUI SI A MAXIMULUI ///

	n = TreeMin(r);
	printf("\nTree min= %d", n->key);

	n = TreeMax(r);
	printf("\nTree Max= %d", n->key);

	/// GASIREA SUCCESORULUI UNUI NOD ///

	printf("\nSuccesorul lui x= ");
	scanf_s("%d", &x);
	n = TreeSearch(r, x);
	s = TreeSuccesor(n);
	if (s != NULL) {
		printf("\nNod Succesor: %d", s->key);
	}
	else {
		printf("\nSuccesorlu nu a fost gasit (NULL)\n");
	}

	/// STERGEREA UNUI NOD ///

	printf("\nSterge nod cu cheia x= ");
	scanf_s("%d", &x);
	n = TreeSearch(r, x);
	if (n != NULL) {
		TreeDelete(&t, n);
		printf("\nNod Sters!\n");
		InOrderWalk(r);
	}
	else {
		printf("\nNodul nu a fost gasit\n");
	}

	return 0;
}