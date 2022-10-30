#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct nod_lista{
    int key;
    struct nod_lista *next, *prev;
}t_nod_lista;

typedef struct{
    t_nod_lista *head;
}t_lista;

void MakeNull(t_lista *L);

t_nod_lista* ListSearch(t_lista L, int key);

void ListInsert(t_lista *L, t_nod_lista *x);

void ListFree(t_lista *L);

void ListPrint(t_lista L);

void ListDelete(t_lista *L, t_nod_lista *x);

#endif // LISTA_H_INCLUDED
