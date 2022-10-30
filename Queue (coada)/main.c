#include <stdio.h>
#include <stdlib.h>
#include "coada.h"

int main()
{
    t_coada q;
    int e = -1, n;

    init_queue(&q, 20);

    printf("Cate elemente in Queue: ");
    scanf("%d", &n);
    init_queue(&q, n);

    for(int i = 1; i<=n, e != 0; i++){
        printf("elementul %d: ", i);
        scanf("%d", &e);
        enqueue(&q, e);
    }

    printf("\n\nQueue curent: ");
    print_queue(q);

    printf("\n");
    while(queue_empty(q) == 1){
        dequeue(&q);
        print_queue(q);
        printf("\n");
    }
    free_queue(&q);

    return 0;
}
