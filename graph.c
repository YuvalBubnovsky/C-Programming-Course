// PROJECT INCLUDES

#include "graph.h"

// GENERAL INCLUDES

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "priorityQueue.h"
#include <string.h>

// GLOBALS

graph *g;
graph *copy;

int N;
int best;
int temp;

// HELPERS
void updateOtherEdges(pnode new)
{
    pnode n = g->head;
    pedge edge;
    while (n != NULL)
    {
        edge = n->edges;

        while (edge != NULL)
        {
            if (edge->dest == new->node_num)
            {
                edge->endpoint = new;
            }
            edge = edge->next;
        }
        n = n->next;
    }
}

void freeOtherEdges(int id)
{
    pnode n = NULL;
    n = g->head;
    pedge edg = NULL;
    pedge e = NULL;
    while (n != NULL)
    {
        edg = n->edges;
        if (edg == NULL)
        {
            n = n->next;
            continue;
        }

        if (n->edges->dest == id)
        {
            edg->endpoint = NULL;
            n->edges = edg->next;
            n = n->next;
            free(edg);
            free(e);
            continue;
        }

        while (edg != NULL)
        {
            if (edg->dest == id)
            {
                edg->endpoint = NULL;
                e->next = edg->next;
            }
            e = edg;
            edg = edg->next;
        }
        n = n->next;
    }
    free(edg);
    free(e);
    free(n);
}

void free_edges_mem(pnode head)
{
    edge *next = head->edges;
    pedge edgeToDelete = NULL;

    while (next != NULL)
    {
        edgeToDelete = next;
        next = next->next;
        free(edgeToDelete);
    }
    free(next);
    free(head);
}

pnode dijkstra(int src, int dest)
{

    pnode n = g->head;
    pnode source;
    while (n != NULL)
    {
        n->dist = __INT_MAX__;
        n->tag = NULL;
        n->visited = 0;
        if (n->node_num == src)
            source = n;
        n = n->next;
    }
    source->dist = 0;
    ppq pq = newPQ(source);
    pq->head->pqnext = NULL;

    // push(source, pq);

    pedge edge = (pedge)malloc(sizeof(edge));
    int weight;
    pnode ans = NULL;
    free(edge);
    while (!isEmpty())
    {
        n = pop();
        n->visited = 1;
        if (n->node_num == dest)
            ans = n;
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
                push(edge->endpoint, pq);
            edge = edge->next;
        }
    }
    free(pq);
    free(edge);
    return ans;
}

bool findNode(int id, int cities[], size_t length)
{
    int i = -1;
    int s = id;
    for (i = 0; i < sizeof(int) * length; i++)
    {
        if (cities[i] == s)
            return true;
    }
    return false;
}

void permutation(int adj[N][N], size_t length, int counter, int i, int cities[], bool visited[N], int level, int sum)
{
    if (level == counter)
    {
        if (sum < best)
            best = sum;
        return;
    }
    visited[i] = true;
    for (int r = 0; r < N; r++)
    {
        if (visited[r] != true && adj[i][r] != -1)
        {
            if (findNode(r, cities, length))
                permutation(adj, length, counter, r, cities, visited, level + 1, sum + adj[i][r]);
            else
                permutation(adj, length, counter, r, cities, visited, level, sum + adj[i][r]);

            visited[r] = false; // for others.
        }
    }
    visited[i] = false;
    return;
}

// ALGORITHMS

void build_graph_cmd(graph *head)
{
    g = head;
    g->size = head->size;
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
        updateOtherEdges(head);
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
            updateOtherEdges(head);
            return;
        }
        next = next->next;
    }

    // If we did not find the node - push it to the start of the list -> O(1)

    node *temp = g->head;
    g->head = (pnode)head;
    g->head->next = temp;
    g->size++;
}

void delete_node_cmd(int id)
{
    node *next = g->head;

    // if we need to delete the head of the graph
    if (next->node_num == id)
    {
        g->head = next->next;
        free_edges_mem(next->next);
        free(next);
        freeOtherEdges(id);
        return;
    }

    while (next->next != NULL)
    {
        if (next->next->node_num == id)
        {
            pnode temp = next->next->next;
            freeOtherEdges(id);
            free_edges_mem(next->next);
            next->next = temp;
            return;
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
    node *next = *head;
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
    // printf(" ");
    pnode n = dijkstra(src, dest);
    if (n == NULL)
    {
        printf("-1 \n");
        return;
    }
    printf("Dijsktra shortest path: %d \n", n->dist);

    // abFree(&buf);
}
// priority 6
void TSP_cmd(int cities[], int k)
{
    int max = 0;
    pnode n = g->head;
    while (n != NULL)
    {
        if (n->node_num > max)
            max = n->node_num;
        n = n->next;
    }

    N = max + 1;
    int adj[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            adj[i][j] = -1;
        }
    }
    n = g->head;
    pedge edge;
    while (n != NULL)
    {
        edge = n->edges;
        while (edge != NULL)
        {
            adj[n->node_num][edge->dest] = edge->weight;
            edge = edge->next;
        }
        n = n->next;
    }

    bool visited[N];
    memset(visited, false, sizeof(bool) * N);
    int temp = __INT_MAX__;

    n = g->head;
    size_t length = k;
    if (k > 2)
    {
        k++;
    }
    int r = 1;
    while (n != NULL)
    {
        memset(visited, false, sizeof(bool) * N);
        best = __INT_MAX__;
        r = n->node_num;
        if (findNode(r, cities, length))
            permutation(adj, length, k, r, cities, visited, 1, 0);
        else
            permutation(adj, length, k, r, cities, visited, 0, 0);
        if (best < temp)
            temp = best;
        // printf("best from node %d is %d\n",n->node_num,best);
        n = n->next;
    }

    if (temp == __INT_MAX__)
        temp = -1;
    printf("TSP shortest path: %d \n", temp);
    // free(cities);
}
