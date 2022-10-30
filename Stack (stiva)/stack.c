#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void init_stack(t_stiva *s, int init_size){
    s->data = (int *)malloc(init_size * sizeof(int));
    s->top = 0;
}

void push(t_stiva *s, int e){
    s->top = s->top + 1;
    s->data[s->top] = e;
}

void print_stack(t_stiva s){
    for(int i = 1; i<=s.top; i++){
        printf("%d ", s.data[i]);
    }
}

int stack_empty(t_stiva s){
    if(s.top == 0){
        return 1;
    }else{
        return 0;
    }
}

int stack_pop(t_stiva *s){
    if(stack_empty(*s) == 1){
        printf("Stiva este goala");
        return -1;
    }else{
        int e = s->data[s->top];
        s->data[s->top] = 0;
        s->top = s->top - 1;
        return e;
    }
}


void free_stack(t_stiva *s){
    s->data = NULL;
    s->top = -1;
}
