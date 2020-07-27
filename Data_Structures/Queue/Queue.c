#include <stdio.h>
#include "Queue.h"

queue_t *queue_create()
{
    queue_t *queue = (queue_t *) malloc(sizeof(queue_t));
    if(!queue)
    {
        printf("Insufficient memory to create queue!\n");
        return NULL;
    } 

    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    return queue;
}

int queue_push(queue_t *queue, TYPE value)
{
    if (!queue)
    {
        printf("Queue not defined!\n");
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
    
    if (!queue->tail)
    {
        queue->head = node;
        queue->tail = node;      
    }
    else
    {
        queue->tail->next = node;
        queue->tail = node;        
    }
    
    queue->size++;
    return 0;
}

int queue_pop(queue_t *queue)
{
    if (!queue)
    {
        printf("Queue not defined!\n");
        return 1;
    }

    if(!queue->head)
    {
        printf("Queue already empty!\n");
        return 2;
    }

    node_t *tmp = queue->head;
    
    if(queue->size == 1)
    {
        queue->head = NULL;
        queue->tail = NULL;
    }
    else
    {
        queue->head = queue->head->next;
    }
    
    free(tmp);
    queue->size--;
    return 0;
}

void queue_print(queue_t *queue)
{   
    if (!queue)
    {
        printf("Queue not defined!\n");
        return;
    }

    node_t *aux = queue->head;
    if(!aux)
    {
        printf ("Empty Queue!");
    }

    while(aux)
    {
        printf("%i ", aux->value);
        aux = aux->next;
    }

    printf("\n");
}

void queue_print_reverse(node_t *node)
{
    if(!node) return;

    queue_print_reverse(node->next);
    
    printf("%i ", node->value);
}

void queue_destroy(queue_t **queue)
{
    if(!*queue) return;

    while((*queue)->head)
    {
        queue_pop(*queue);
    }

    free(*queue);
    *queue = NULL;
}


int main()
{
    // Usage example:
    
    queue_t *q = queue_create();
    queue_push(q, 2);
    queue_push(q, 4);
    queue_push(q, 3);
    queue_print(q);
    queue_print_reverse(q->head);
    printf("\n");
    
    queue_pop(q);
    queue_print(q);
    queue_print_reverse(q->head);
    printf("\n");
    
    queue_destroy(&q);
    
    return 0;
}