#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    t_lista L;
    t_nod_lista *x;
    int s = -1, key;

    MakeNull(&L);

    printf("\nMeniu principal \n");
    printf("1 pentru inserare \n");
    printf("2 pentru cautare \n");
    printf("3 pentru stergere \n");
    printf("4 pentru afisare \n");
    printf("0 pentru iesire din program \n");

    while(s != 0){
        printf("\n optiunea: ");
        scanf("%d", &s);

        switch(s){
        case 1: /// Inserare
            printf("Key= ");
            scanf("%d", &key);
            x = (t_nod_lista*)malloc(sizeof(t_nod_lista));
            x->key = key;
            ListInsert(&L, x);
            break;
        case 2: /// Cautare
            printf("Key= ");
            scanf("%d", &key);
            x = ListSearch(L, key);
            if(x != NULL){
                printf("Gasita");
            }else{
                printf("Nu exista");
            }
            break;
        case 3: /// Stergere
            printf("Key= ");
            scanf("%d", &key);
            x = ListSearch(L, key);
            if(x != NULL){
                ListDelete(&L, x);
            }
            break;

        case 4: /// Afisare
            printf("Lista contine: ");
            ListPrint(L);
            break;
        }
    }


    return 0;
}
