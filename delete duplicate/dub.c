#include <stdlib.h>
#include <stddef.h>
#include <assert.h>

#include "dub.h"

List *slist_delete_duplicates(List *list)
{
    Node *temp = list->head;
    Node *curr;
    Node *prev;

    while (temp != NULL)
    {
        prev = temp;
        curr = temp->next;

        while (curr != NULL)
        {
            if (curr->data == temp->data)
            {
                prev->next = curr->next;

                Node *duplicate = curr;
                free(duplicate);

                curr = prev->next;
                --list->length;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }

        temp = temp->next;
    }

    /* Update tail */
    list->tail = list->head;

    if (list->tail != NULL)
    {
        while (list->tail->next != NULL)
            list->tail = list->tail->next;
    }

    return list;
}