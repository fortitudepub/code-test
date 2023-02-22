#include "stdio.h"
#include "stdlib.h"

typedef struct _link_node {
    struct _link_node *next;
    int seq_no;
} link_node;

#ifdef __x86_64__
#error "ok"
#endif

int main()
{
    int i = 0;

    link_node *cur, *prev;

    link_node *head = malloc(sizeof(link_node));
    head->seq_no = 1;
    cur = head;

    for (i = 1; i < 10; i++)
    {
        link_node *n = malloc(sizeof(link_node));
        n->seq_no = i+1;
        n->next = NULL;

        cur->next = n;
        cur = n;
    }

    cur = head;
    for (; cur != NULL;)
    {
        printf("seq: %d\n", cur->seq_no);
        prev = cur;
        cur = cur->next;
        free(prev);
    }

}
