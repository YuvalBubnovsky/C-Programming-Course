// PROJECT INCLUDES

#include "graph.h"

// GENERAL INCLUDES

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

// DEFINES
//TODO: change getNext to be more precise such that getNext(node) is node->next
#define getNext next->next
#define getHead graph->head
//TODO: define a getId(node) as node->node_num

// GLOBALS

graph *g;


// HELPERS

void free_node_mem(pnode head)
{
    //TODO: figure out
    pnode node = (pnode)head;
    free(node->next);
    free(node->edges);
}

// ALGORITHMS

void build_graph_cmd(pnode *head)
{
    //TODO: while loop that applies free_node_mem to all nodes in current grap
    g = (graph *)malloc(sizeof(struct Graph_));
    g->head = head; 
}

void insert_node_cmd(pnode *head)
{
    node *next = *(g->head);

    while (next != NULL) // O(n)
    {
        if (next->node_num == (*head)->node_num)
        {
            // If found node in graph - override it's values to apply new ones.
            // also free old memory
            free_node_mem(next);
            next->next = (*head)->next;
            next->edges = (*head)->edges;
            return;
        }
        next = getNext;
    }

    //If we did not find the node - push it to the start of the list -> O(1)

    node *temp = *(g->head);
    *(g->head) = (pnode)head;
    (*(g->head))->next = temp;

}

void delete_node_cmd(pnode *head)
{
    // TODO: fix this to use the fact that *head is given!!!!!!!!!!!
    node *next = *(g->head);

    // if we need to delete the head of the graph
    if (next->node_num == (*head)->node_num) 
    {
        *(g->head) = next->next;
        free_node_mem(*head);
        return;
    }

    while (next != NULL) // O(n)
    {
        if (getNext->node_num == (*head)->node_num)
        {
            getNext = (*head)->next;
            free_node_mem(*head);
            return;
        }
        next = getNext;
    }

    //If we did not find the node - we ponder why this method was called
}

void printGraph_cmd(pnode head)
{
    node *next = head;
    edge *edge;

    while (next != NULL)
    {
        printf("\n Node: %d\n Edges: ",next->node_num);
        edge = next->edges;
        while (edge != NULL)
        {
            printf("(%d,%d)",next->node_num,edge->endpoint->node_num);
        }
    }
    
}

void deleteGraph_cmd(pnode *head)
{
    node *next = *(g->head);
    node *temp;

    while (next != NULL)
    {
        temp = getNext;
        free_node_mem(next);
        next = temp;
    }

}
// priority 5
void shortsPath_cmd(pnode head)
{
    //use dijkstra
}
// priority 6
void TSP_cmd(pnode head)
{
    // Implement with O(n!) naive solution
}
