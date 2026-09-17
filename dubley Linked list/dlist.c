#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include "slist.h"

List *dlist_new(void)
{
    List *list;

    list = (List *)malloc(sizeof(List));

    if (list == NULL)
        return NULL;

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    return list;
}

static Node *list_node_new_(int32_t data)
{   
    Node *node;

    node = (Node *)malloc(sizeof(Node));

    if (node == NULL)
        return NULL;

    node->data = data;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

List *dlist_add_head(List *list, int32_t data)
{
    Node *node = list_node_new_(data);

    if (list->head != NULL)
    {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }
    else
    {
        list->head = list->tail = node;
    }

    ++list->length;

    return list;
}


List *dlist_delete_head(List *list)
{
    Node *node;

    if (list->head != NULL)
    {
        assert(list->length > 0);
        node = list->head;
        list->head = list->head->next;

        if (list->head != NULL)
            list->head->prev = NULL;
        else
            list->tail = NULL;

        --list->length;
        free(node);
    }

    return list;
}

List *dlist_add_tail(List *list, int32_t data)
{
    Node *node = list_node_new_(data);

    if (list->tail != NULL)
    {
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    }
    else
    {
        list->head = list->tail = node;
    }

    ++list->length;

    return list;
}

List *dlist_delete_tail(List *list)
{
    Node *node;

    if (list->tail != NULL)
    {
        assert(list->length > 0);
        node = list->tail;
        list->tail = list->tail->prev;

        if (list->tail != NULL)
            list->tail->next = NULL;
        else
            list->head = NULL;

        --list->length;
        free(node);
    }

    return list;
}



