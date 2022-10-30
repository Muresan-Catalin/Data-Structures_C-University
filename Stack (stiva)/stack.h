#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct stiva{
    int top;
    int *data;
}t_stiva;

void init_stack(t_stiva *s, int init_size);

void push(t_stiva *s, int e);

void print_stack(t_stiva s);

int stack_pop(t_stiva *s);

int stack_empty(t_stiva s);

void free_stack(t_stiva *s);

#endif // STACK_H_INCLUDED
