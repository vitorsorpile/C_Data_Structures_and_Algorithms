#include <stdlib.h>
#define TYPE int 

typedef struct node
{
    TYPE value;
    struct node *next; 
    
}node_t;

typedef struct stack
{
    node_t *head;
    node_t *tail;
    int size;
}stack_t;

stack_t *stack_create();
int stack_push(stack_t *stack, TYPE value);
int stack_pop(stack_t *stack);
void stack_print(stack_t *stack);
void stack_print_reverse(node_t *node);