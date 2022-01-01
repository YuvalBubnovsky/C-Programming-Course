// PROJECT INCLUDES

#include "graph.h"

// GENERAL INCLUDES

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "priorityQueue.h"
#include <string.h>

// DEFINES

#define INF 9999

// GLOBALS

graph *g;
graph *copy;

/* APPEND BUFFER */

struct abuf
{
    char *b;
    int len;
};

#define ABUF_INIT \
    {             \
        NULL, 0   \
    }

void abAppend(struct abuf *ab, const char *s, int len)
{
    char *new = realloc(ab->b, ab->len + len);

    if (new == NULL)
        return;
    memcpy(&new[ab->len], s, len);
    ab->b = new;
    ab->len += len;
}

void abFree(struct abuf *ab)
{
    free(ab->b);
}

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

pnode dijkstra(int src, int dest)
{
    emptyPQ();

    pnode n = g->head;
    pnode source;
    while (n != NULL)
    {
        n->dist = INF;
        n->tag = NULL;
        n->visited = 0;
        if (n->node_num == src)
            source = n;
        n = n->next;
    }
    source->dist = 0;
    push(source);

    pedge edge;
    int weight;
    while (!isEmpty())
    {
        n = pop();
        n->visited = 1;
        if (n->node_num == dest)
            return n;
        weight = n->dist;
        edge = n->edges;

        while (edge != NULL)
        {
            if (weight + edge->weight < edge->endpoint->dist)
            {
                edge->endpoint->tag = n;
                edge->endpoint->dist = weight + edge->weight;
            }
            if (edge->endpoint->visited == 0)
                push(edge->endpoint);
            edge = edge->next;
        }
    }

    return NULL;
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
        next = next->next;
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
        g->size--;
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
    g->size--;
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
void shortsPath_cmd(int src, int dest)
{
    printf(" ");
    pnode n = dijkstra(src, dest);
    if (n == NULL)
    {
        printf("-1");
        return;
    }

    pnode temp = n;
    temp = NULL;
    while (n != NULL)
    {
        n->pqnext = temp;
        temp = n;
        n = n->tag;
    }

    int p;
    //printf("sad");
    while (temp != NULL)
    {
        p = temp->node_num;
        //printf(" af");
        printf("%d", p);
        temp = temp->pqnext;
    }

    // abFree(&buf);
}
// priority 6
void TSP_cmd(graph *g)
{
    // Implement with O(n!) naive solution
}
