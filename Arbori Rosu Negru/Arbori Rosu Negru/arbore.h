#pragma once

typedef struct rb_node {
	enum {red, black} color;
	int key;
	struct rb_node* left, * right, * parent;
}t_rb_node;

typedef struct {
	t_rb_node* root;
}t_rb_arbore;

t_rb_node* MakeRoot(t_rb_arbore* a, int key);

t_rb_node* CreateNode(int key);

void InOrderWalk(t_rb_node* root);

t_rb_node* TreeSearch(t_rb_node* n, int key);

void RbInsert(t_rb_arbore* a, t_rb_node* z);

void LeftRotate(t_rb_arbore* a, t_rb_node* x);

void RightRotate(t_rb_arbore* a, t_rb_node* x);

void RbInsertFixup(t_rb_arbore* a, t_rb_node* z);
