#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

void MakeNull(t_lista *L){
    L->head = (t_nod_lista*)malloc(sizeof(t_nod_lista));
    L->head->next = L->head->prev = NULL;
}

void ListInsert(t_lista *L, t_nod_lista *x){
    if(x == NULL){
        return;
    }

    x->next = L->head->next;

    if(L->head->next != NULL){
        L->head->next->prev = x;
    }

    L->head->next = x;
    x->prev = L->head;
}

void ListPrint(t_lista L){
    t_nod_lista *x;
    x = L.head->next;

    if(x == NULL){
        printf("Lista e vida!\n");
    }

    while(x != NULL){
        printf("%d ", x->key);
        x = x->next;
    }
}

void ListDelete(t_lista *L, t_nod_lista *x){
    if(x->prev != NULL){
        x->prev->next = x->next;
    }else{
        L->head->next = x->next;
    }

    if(x->next != NULL){
        x->next->prev = x->prev;
    }
}

void ListFree(t_lista *L){
    t_nod_lista *x;
    x = L->head->next;

    while(x != NULL){
        ListDelete(&L, x);
        x = L->head->next;
    }
}

t_nod_lista* ListSearch(t_lista L, int key){
    t_nod_lista *x;
    x = L.head->next;

    while(x != NULL && x->key != key){
        x = x->next;
    }

    return x;
}
