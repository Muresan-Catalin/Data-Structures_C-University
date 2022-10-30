#include "Arbore.h"
#include <stdlib.h>
#include <stdio.h>

t_nod_arbore* MakeRoot(t_arbore* a, int key) {
	a->root = (t_nod_arbore*)malloc(sizeof(t_nod_arbore));
	a->root->key = key;
	a->root->left = NULL;
	a->root->right = NULL;
	a->root->parent = NULL;

	return a->root;
}

void PreorderWalk(t_nod_arbore *n) {
	if (n != NULL) {
		printf("%d ", n->key);
		PreorderWalk(n->left);
		PreorderWalk(n->right);
	}
}

void PostorderWalk(t_nod_arbore* n) {
	if (n != NULL) {
		PostorderWalk(n->left);
		PostorderWalk(n->right);
		printf("%d ", n->key);
	}
}

void InOrderWalk(t_nod_arbore* n) {
	if (n != NULL) {
		InOrderWalk(n->left);
		printf("%d ", n->key);
		InOrderWalk(n->right);
	}
}

t_nod_arbore* CreateNod(int k) {
	t_nod_arbore* n;
	n = (t_nod_arbore*)malloc(sizeof(t_nod_arbore));
	n->key = k;
	n->left = NULL;
	n->right = NULL;
	n->parent = NULL;

	return n;
}

void TreeInsert(t_arbore* a, t_nod_arbore* n) {
	t_nod_arbore* y, * x;
	y = NULL;
	x = a->root;

	while(x != NULL){
		y = x;
		if (n->key < x->key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}

	n->parent = y;
	if (y == NULL) {
		a->root = n;
	}
	else if (n->key < y->key) {
		y->left = n;
	}
	else {
		y->right = n;
	}
}

t_nod_arbore* TreeSearch(t_nod_arbore* n, int key) {
	if (n == NULL || key == n->key) {
		return n;
	}

	if (key < n->key) {
		return TreeSearch(n->left, key);
	}
	else {
		return TreeSearch(n->right, key);
	}
}

t_nod_arbore* ItTreeSearch(t_nod_arbore* n, int key) {
	while (n != NULL && key != n->key) {
		if (key < n->key) {
			n = n->left;
		}
		else {
			n = n->right;
		}
	}

	return n;
}

t_nod_arbore* TreeMax(t_nod_arbore* n) {
	while (n->right != NULL) {
		n = n->right;
	}

	return n;
}

t_nod_arbore* TreeMin(t_nod_arbore* n) {
	while (n->left != NULL) {
		n = n->left;
	}

	return n;
}

t_nod_arbore* TreeSuccesor(t_nod_arbore* n) {
	t_nod_arbore* y;
	if (n->right != NULL) {
		return TreeMin(n->right);
	}

	y = n->parent;

	while (y != NULL && n == y->right) {
		n = y;
		y = y->parent;
	}

	return y;
}

void Transplant(t_arbore* a, t_nod_arbore* u, t_nod_arbore* v) {
	if (u->parent == NULL) {
		a->root = v;
	}
	else if (u == u->parent->left) {
		u->parent->left = v;
	}
	else {
		u->parent->right = v;
	}

	if (v != NULL) {
		v->parent = u->parent;
	}
}

void TreeDelete(t_arbore* a, t_nod_arbore* n) {
	t_nod_arbore* y;

	if (n->left == NULL) {
		Transplant(a, n, n->right);
	}
	else if (n->right == NULL) {
		Transplant(a, n, n->left);
	}
	else {
		y = TreeMin(n->right);

		if (y->parent != n) {
			Transplant(a, y, y->right);
			y->right = n->right;
			y->right->parent = y;
		}

		Transplant(a, n, y);
		y->left = n->left;
		y->left->parent = y;
	}
}