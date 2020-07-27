#include <stdio.h>
#include "Stack.h"

stack_t *stack_create()
{
    stack_t *stack = (stack_t *) malloc(sizeof(stack_t));
    if(!stack)
    {
        printf("Insufficient memory to create stack!\n");
        return NULL;
    } 

    stack->head = NULL;
    stack->tail = NULL;
    stack->size = 0;

    return stack;
}

int stack_push(stack_t *stack, TYPE value)
{
    if (!stack)
    {
        printf("Stack not defined!\n");
        return 1;
    }

    node_t* node = (node_t *) malloc(sizeof(node_t));
    if(!node)
    {
        printf("Insufficient memory to alloc new node!\n");
        return 2;
    }

    node->value = value;
    node->next = NULL;
    
    if (!stack->head)
    {
        stack->head = node;
        stack->tail = node;      
    }
    else
    {   
        node->next = stack->head;
        stack->head = node;
    }
    
    stack->size++;
    return 0;
}

int stack_pop(stack_t *stack)
{
    if (!stack)
    {
        printf("stack not defined!\n");
        return 1;
    }

    if(!stack->head)
    {
        printf("stack already empty!\n");
        return 2;
    }

    node_t *tmp = stack->head;
    
    if(stack->size == 1)
    {
        stack->head = NULL;
        stack->tail = NULL;
    }
    else
    {
        stack->head = stack->head->next;
    }
    
    free(tmp);
    stack->size--;
    return 0;
}

void stack_print(stack_t *stack)
{   
    if (!stack)
    {
        printf("stack not defined!\n");
        return;
    }

    node_t *aux = stack->head;
    if(!aux)
    {
        printf ("Empty stack!");
    }

    while(aux)
    {
        printf("%i\n", aux->value);
        aux = aux->next;
    }
}

void stack_print_reverse(node_t *node)
{
    if(!node) return;

    stack_print_reverse(node->next);
    
    printf("%i\n", node->value);
}

void stack_destroy(stack_t **stack)
{
    if(!*stack) return;

    while((*stack)->head)
    {
        stack_pop(*stack);
    }

    free(*stack);
    *stack = NULL;
}


int main()
{
    // Usage example:
    
    stack_t *q = stack_create();
    stack_push(q, 7);
    stack_push(q, 10);
    stack_push(q, -3);
    stack_print(q);

    stack_pop(q);
    stack_print(q);
    
    stack_destroy(&q);
    
    return 0;
}