#ifndef PRIO_Q
#define PRIO_Q
#include "graph.h"

typedef struct PRIORITY_QUEUE
{
    int size;
    pnode head;
} pq, *ppq;

ppq emptyPQ();
ppq newPQ(pnode head);
void push(pnode node);
int isEmpty();
pnode peek();
pnode pop(); //i.e deleteMin().

#endif
