#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    t_stiva s;
    int e = -1;

    init_stack(&s, 20);

    printf("\ne= ");
    scanf("%d", &e);
    while(e != 0){
        push(&s, e);
        print_stack(s);
        printf("\ne= ");
        scanf("%d", &e);
    }

    print_stack(s);

    while(stack_empty(s) == 0){
        printf("\n");
        stack_pop(&s);
        print_stack(s);
    }
    free_stack(&s);

    return 0;
}
