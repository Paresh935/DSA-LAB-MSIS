#include <stddef.h>
#include <stdint.h>
#include <assert.h>

#include "dlist.h"

void test_dlist_generic(void)
{
    List *list = dlist_new();

    /* Check list creation */
    assert(list != NULL);
    assert(dlist_length(list) == 0);
    assert(list->head == NULL);
    assert(list->tail == NULL);

    
    #check adding a node to the head of the list

    dlist_add_head(list, 10);
    assert(dlist_length(list) == 1);
    assert(list->head != NULL);
    assert(list->tail != NULL);
    assert(list->head->data == 10);
    assert(list->tail->data == 10);
    assert(list->head->next == NULL);
    assert(list->head->prev == NULL);

    