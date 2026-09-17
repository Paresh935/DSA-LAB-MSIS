#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "dub.h"

int main(void)
{
    List *list = malloc(sizeof(List));

    assert(list != NULL);

    /* Initialize empty list */
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    /* Create nodes */
    Node *n1 = malloc(sizeof(Node));
    Node *n2 = malloc(sizeof(Node));
    Node *n3 = malloc(sizeof(Node));
    Node *n4 = malloc(sizeof(Node));
    Node *n5 = malloc(sizeof(Node));

    assert(n1 != NULL);
    assert(n2 != NULL);
    assert(n3 != NULL);
    assert(n4 != NULL);
    assert(n5 != NULL);

    /* Store data */
    n1->data = 10;
    n2->data = 20;
    n3->data = 10;
    n4->data = 30;
    n5->data = 20;

    /* Link nodes */
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;

    /* Set list information */
    list->head = n1;
    list->tail = n5;
    list->length = 5;

    /* Print before deletion */
    printf("Before deleting duplicates:\n");

    Node *temp = list->head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\nLength = %u\n", list->length);

    /* Check initial list */
    assert(list->length == 5);
    assert(list->head->data == 10);
    assert(list->tail->data == 20);

    /* Delete duplicates */
    slist_delete_duplicates(list);

    /* Print after deletion */
    printf("\nAfter deleting duplicates:\n");

    temp = list->head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\nLength = %u\n", list->length);

    /* Assertions after deletion */

    assert(list->length == 3);

    assert(list->head != NULL);
    assert(list->head->data == 10);

    assert(list->head->next != NULL);
    assert(list->head->next->data == 20);

    assert(list->head->next->next != NULL);
    assert(list->head->next->next->data == 30);

    assert(list->head->next->next->next == NULL);

    assert(list->tail->data == 30);

    printf("\nAll assertions passed!\n");

    /* Free remaining nodes */
    temp = list->head;

    while (temp != NULL)
    {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }

    free(list);

    return 0;
}
