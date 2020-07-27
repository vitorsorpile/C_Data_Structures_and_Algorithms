#include <stdlib.h>
#include <stdio.h>
#include "DoublyLinkedList.h"


list_t *list_create(void)
{
    list_t *l = (list_t *) malloc(sizeof(list_t));
    if (!l)
    {
        return NULL;
    }

    l->head = NULL;
    l->size = 0; 

    return l;
}

int list_add_node(list_t *l, TYPE val, int position)
{
    if (!l)
    {
        printf("List doesn't defined!\n");
        return 1;
    }

    if (position < 0 || position > l->size)
    {   
        printf("Invalid insertion position!\n");
        return 2;
    }

    node_t *n = (node_t *) malloc(sizeof(node_t));
    if (!n)
    {
        printf("Insufficient memory to alloc new node!\n");
        return 3;
    }

    n->value = val;
    n->prv = NULL;
    n->next = NULL;
    l->size++;

    if (position == 0)
    {
        if (!l->head)
        {
            l->head = n;
            return 0;
        }

        n->next = l->head;
        l->head->prv = n;
        l->head = n;
        return 0;
    }

    node_t *aux = l->head;
    int i = 0;

    while (i < position - 1)
    {
        aux = aux->next;
        i++;
    }

    n->prv = aux;
    n->next = aux->next;
    
    if (aux->next)
    {
        aux->next->prv = n;
    }

    aux->next = n;
    

    return 0;
}

int list_remove_node_by_position(list_t *l, int position)
{
    if (!l)
    {
        printf("List doesn't defined!\n");
        return 1;
    }

    if (position < 0 || position >= l->size)
    {
        printf("Invalid remove position!\n");
        return 2;
    }

    node_t *aux = l->head;

    for (int i = 0; i < position; i++)
    {
        aux = aux->next;
    }

    if (aux == l->head)
    {
        l->head = aux->next;
    }
    else
    {
        aux->prv->next = aux->next;
    }

    if(aux->next)
    {
        aux->next->prv = aux->prv;
    }       
    
    free(aux);
    l->size--;

    return 0;
}

int list_remove_node_by_value(list_t *l, TYPE val)
{
    if (!l)
    {
        printf("List doesn't defined!\n");
        return 1;
    }

    node_t *aux = l->head;
    int position = 0;
    while (aux && aux->value != val)
    {
        aux = aux->next;
        position++;
    }

    if (aux)
    {
        list_remove_node_by_position(l, position);
    }

    return 0;
}

void list_destroy(list_t **l)
{
    if(!*l)
    {
        return;
    }

    while((*l)->head)
    {
        list_remove_node_by_position(*l, 0);
    }

    free(*l);
    *l = NULL;
    return;
}

void list_print(list_t *l)
{
    if (!l)
    {
        printf("List doesn't defined!\n");
        return;
    }

    if (l->size == 0)
    {
        printf("Empty list.\n");
        return;
    }

    node_t *aux = l->head;

    while(aux)
    {
        printf("%i ",aux->value);
        aux = aux->next;
    }
    printf("\n");
    return;
}

int main()
{
    list_t *l = list_create();
    list_add_node(l, 3, 0);
    list_add_node(l, 5, 0);
    list_add_node(l, 8, 2);
    list_add_node(l, 92, 3);
    list_print(l);

    list_remove_node_by_position(l,3);
    list_remove_node_by_position(l,2);
    list_print(l);

    list_remove_node_by_value(l,5);
    list_print(l);
    
    list_destroy(&l);
    list_print(l);

    return 0;
}
