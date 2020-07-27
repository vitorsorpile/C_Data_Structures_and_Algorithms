#include <stdlib.h>
#define TYPE int 

typedef struct node
{
    TYPE value;
    struct node *next; 
    
}node_t;

typedef struct queue
{
    node_t *head;
    node_t *tail;
    int size;
}queue_t;

queue_t *queue_create();
int queue_push(queue_t *queue, TYPE value);
int queue_pop(queue_t *queue);
void queue_print(queue_t *queue);
void queue_print_reverse(node_t *node);