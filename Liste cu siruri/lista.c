#include <string.h>
#include <stdlib.h>
#include "liste.h"

void MakeNull(t_lista *lista){
    lista ->maxlength = 100;
    lista ->last = 0;

    lista ->storage = (int*) malloc(lista->maxlength * sizeof(int));
}

void Destroy(t_lista *lista){
    if(lista->storage != NULL) free(lista->storage);
    lista ->maxlength = lista ->last = 0;
}

void Inflate(t_lista *lista){
    int *newStorage;

    if(lista ->last >= lista ->maxlength-1){
        newStorage = (int*)malloc((lista ->maxlength+100) * sizeof(int));
        memcpy(newStorage, storage, lista ->maxlength * sizeof(int));
        free(lista ->storage);
        lista ->storage = newStorage;
        lista ->maxlength += 100;
    }
}
