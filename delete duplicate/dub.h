#ifndef _INCLUDE_SLIST_
#define _INCLUDE_SLIST_

#include <stdint.h>

typedef struct _node_ Node;
typedef struct _slist_ List;

struct _slist_ {
    Node *head;
    Node *tail;
    uint32_t length;
};

struct _node_ {
    int32_t data;
    Node *next;
};

List *slist_delete_duplicates(List *list);

#endif