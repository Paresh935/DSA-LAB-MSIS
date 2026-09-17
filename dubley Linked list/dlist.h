#ifndef _INCLUDE_DLIST_
#define _INCLUDE_DLIST_

#include <stdint.h>

typedef struct _node_ Node;
typedef struct _dlist_ List;

struct _dlist_ {
    Node *head;
    Node *tail;
    uint32_t length;
};

struct _node_ {
    int32_t data;
    Node *next;
    Node *prev;
};

List *dlist_new(void);
List *dlist_add_head(List *list, int32_t data);
List *dlist_delete_head(List *list);
List *dlist_add_tail(List *list, int32_t data);
List *dlist_delete_tail(List *list);

#endif