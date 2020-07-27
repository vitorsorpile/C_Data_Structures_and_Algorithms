#include <stdlib.h>
#define TYPE int 


typedef struct node
{
    TYPE value;
    struct node *prv;
    struct node *next; 
    
}node_t;

typedef struct list_t
{
    node_t *head;
    int size;

}list_t;


/*
 * METHODS
*/

list_t *list_create(void);

int list_add_node(list_t *l, TYPE val, int position);

int list_remove_node_by_value(list_t *l, TYPE val);

void list_destroy(list_t **l);

void list_print_int(list_t *l);