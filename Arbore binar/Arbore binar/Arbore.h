#pragma once

typedef struct nod_arb {
	int key;
	struct nod_arb* left, * right, * parent;
}t_nod_arbore;

typedef struct {
	t_nod_arbore* root;
}t_arbore;

t_nod_arbore* MakeRoot(t_arbore* a, int key);

void PreorderWalk(t_nod_arbore *n);

void PostorderWalk(t_nod_arbore *n);

void InOrderWalk(t_nod_arbore* n);

t_nod_arbore* TreeSearch(t_nod_arbore *n, int key);

t_nod_arbore* ItTreeSearch(t_nod_arbore *n, int key);

void TreeInsert(t_arbore* a, t_nod_arbore* n);

void TreeDelete(t_arbore* a, t_nod_arbore* n);

t_nod_arbore* CreateNod(int k);

t_nod_arbore* TreeMax(t_nod_arbore* n);

t_nod_arbore* TreeMin(t_nod_arbore* n);

t_nod_arbore* TreeSuccesor(t_nod_arbore* n);

void TreeDelete(t_arbore* a, t_nod_arbore* n);
