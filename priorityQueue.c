#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "priorityQueue.h"
#include "graph.h"

ppq prio = NULL;

ppq emptyPQ()
{
    ppq pq = (ppq)malloc(sizeof(pq));
    pq->size = 0;
    pq->head = (pnode)malloc(sizeof(node));
    prio = pq;
    return pq;
}

ppq newPQ(pnode head)
{
    ppq pq = (ppq)malloc(sizeof(pq)+sizeof(node));
    pq->size = 1;
    pq->head = head;
    pq->head->pqnext = NULL;
    prio = pq;
    prio->head = head;
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
    pr->head->pqnext = NULL;
    while (pr->head->pqnext != NULL)
    {
        if (node->dist < pr->head->pqnext->dist)
        {
            node->pqnext = pr->head->pqnext;
            pr->head->pqnext = node;
            prio->size++;
            return;
        }
        pr->head = pr->head->pqnext;
        prio++;
    }
    
    pr->head->pqnext = node; // in case it's at the bottom
}

int isEmpty()
{
    if (prio->size == 0)
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