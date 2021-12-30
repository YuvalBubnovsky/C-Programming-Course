// PROJECT INCLUDES

#include "graph.h"

// GENERAL INCLUDES

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

// DEFINES
// TODO: change getNext to be more precise such that getNext(node) is node->next
#define getNext next->next
#define getHead graph->head
// TODO: define a getId(node) as node->node_num

// GLOBALS

graph *g;

// HELPERS

void free_edges_mem(pnode head)
{
    edge *next = head->edges;
    edge *edgeToDelete;

    while (next != NULL)
    {
        edgeToDelete = next;
        next = next->next;
        free(edgeToDelete);
    }
}

// ALGORITHMS

void build_graph_cmd(graph *head)
{
    // deleteGraph_cmd(g->head);
    // g = (graph *)malloc(sizeof(struct Graph_));
    g = head;
    g->init = 1;
}

void insert_node_cmd(pnode head)
{
    node *next = g->head;

    if (next->node_num == head->node_num)
    {
        pnode temp = next->next;
        free_edges_mem(next);
        next = head;
        g->head = head;
        next->next = temp;
        next->edges = head->edges;
        return;
    }

    while (next->next != NULL) // O(n)
    {
        if (next->next->node_num == head->node_num)
        {
            // If found node in graph - override it's values to apply new ones.
            // also free old edge memory
            pnode temp = next->next->next;
            free_edges_mem(next->next);
            next->next = head;
            next->next->next = temp;
            next->next->edges = head->edges;
            return;
        }
        next = getNext;
    }

    // If we did not find the node - push it to the start of the list -> O(1)

    node *temp = g->head;
    g->head = (pnode)head;
    g->head->next = temp;
}

void delete_node_cmd(int id)
{
    // TODO: fix this to use the fact that *head is given!!!!!!!!!!!
    node *next = g->head;

    // if we need to delete the head of the graph
    if (next->node_num == id)
    {
        g->head = next->next;
        free_edges_mem(next);
        free(next);
        return;
    }

    while (next->next != NULL)
    {
        if (next->next->node_num == id)
        {
            pnode temp = next->next->next;
            free_edges_mem(next->next);
            free(next->next);
            next->next = temp;
        }
        next = next->next;
    }
}

void printGraph_cmd(graph *g)
{
    pnode next = g->head;

    if (next == NULL)
    {
        printf("graph is empty :(");
    }

    edge *edge;

    while (next != NULL)
    {
        printf("\n Node: %d\n Edges: ", next->node_num);
        edge = next->edges;
        while (edge != NULL)
        {
            printf("(src: %d, dest: %d, w = %d) ", next->node_num, edge->endpoint->node_num, edge->weight);
            edge = edge->next;
        }
        next = next->next;
    }
    printf("\n");
}

void deleteGraph_cmd(pnode *head)
{
    node *next = g->head;
    node *nodeToFree;
    edge *edge, *edgeToFree;

    while (next != NULL)
    {
        edge = next->edges;
        while (edge != NULL)
        {
            edgeToFree = edge;
            edge = edge->next;
            free(edgeToFree);
        }
        nodeToFree = next;
        next = next->next;
        free(nodeToFree);
    }
}
// priority 5
void shortsPath_cmd(pnode head)
{
    // use dijkstra
}
// priority 6
void TSP_cmd(pnode head)
{
    // Implement with O(n!) naive solution
}
