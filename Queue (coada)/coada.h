#ifndef COADA_H_INCLUDED
#define COADA_H_INCLUDED

typedef struct coada{
    int head, tail, length;
    int *data;
}t_coada;

void init_queue(t_coada *q, int init_size);

void free_queue(t_coada *q);

void enqueue(t_coada *q, int e);

int dequeue(t_coada *q);

void print_queue(t_coada q);

int queue_empty(t_coada q);

#endif // COADA_H_INCLUDED
