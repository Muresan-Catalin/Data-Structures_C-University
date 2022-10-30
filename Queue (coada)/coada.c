#include "coada.h"
#include <stdio.h>
#include <stdlib.h>

void init_queue(t_coada *q, int init_size){
    q->data = (int *)malloc(init_size * sizeof(int));
    q->head = 0;
    q->tail = 0;
    q->length = 0;
}

void free_queue(t_coada *q){
    q->data = NULL;
    q->head = 0;
    q->tail = 0;
}

void enqueue(t_coada *q, int e){
    q->data[q->tail] = e;
    q->length = q->length + 1;

    if(q->tail == q->length){
        q->tail = 1;
    }else{
        q->tail = q->tail + 1;
    }
}

int dequeue(t_coada *q){
    int e = q->data[q->head];
    q->length = q->length - 1;

    if(q->head == q->length){
        q->head = 1;
    }else{
        q->head = q->head + 1;
    }

    return e;
}

void print_queue(t_coada q){
    for(int i = q.head; i<=q.head + q.length - 1; i++){
        printf("%d ", q.data[i]);
    }
}

int queue_empty(t_coada q){
    if(q.length >= 0){
        return 1;
    }else{
        return 0;
    }
}
