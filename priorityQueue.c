#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "priorityQueue.h"
#include "graph.h"

ppq prio;

ppq emptyPQ()
{
    ppq pq = (ppq)malloc(sizeof(ppq));
    pq->size = 0;
    pq->head = (pnode)malloc(sizeof(pnode));
    prio = pq;
    return pq;
}

ppq newPQ(pnode head)
{
    ppq pq = (ppq)malloc(sizeof(ppq));
    pq->size = 1;
    pq->head = head;
    prio = pq;
    return pq;
}

void push(pnode node, ppq pr){

    if (isEmpty())
    {
        prio->head = node;
        prio->size = 1;
        return;
    }

    if (node->dist < prio->head->dist)
    {
        node->pqnext =  prio->head;
        prio->head = node;
        prio->size++;
        return;
    }
    

    pnode n = prio->head;

    while (n->pqnext != NULL)
    {
        if (node->dist < n->pqnext->dist)
        {
            node->pqnext = n->pqnext;
            n->pqnext = node;
            prio->size++;
            return;
        }
        n = n->pqnext;
        prio++;
    }
    
    n->pqnext = node; // in case it's at the bottom
}

int isEmpty()
{
    if (prio->head == NULL || prio->size == 0)
    {
        return true;
    }

    return false;
}

pnode peek(){
    return prio->head;
}

pnode pop(){
    pnode ans = prio->head;
    prio->head = ans->pqnext;
    prio->size--;
    ans->pqnext = NULL;
    return ans;
}