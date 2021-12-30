#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "graph.h"

// HELPERS

void updateEndpoints(graph *g, pnode *arr)
{
    node *next = *(g->head);
    edge *edge;

    while (next != NULL)
    {
        edge = next->edges;
        while (edge != NULL)
        {
            edge->endpoint = arr[edge->dest]->next;
            edge = edge->next;
        }
        next = next->next;
    }
}

// MAIN

int main()
{
    // char c;
    // int i;
    char userInput;
    bool flag = true;
    // int temp;
    //  int nodeid;
    pnode n = NULL;
    pnode n2 = (pnode)malloc(sizeof(pnode));
    pedge e = (pedge)malloc(sizeof(pedge));

    graph *g = (graph *)malloc(sizeof(struct Graph_));
    g->head = &n;
    while (true)
    {
        userInput = getchar();
    SC:
        switch (userInput)
        {
        case 'E': // EXIT
        {
            break;
        }
        case 'P': // PRINT
        {
            printGraph_cmd(*(g->head));
            break;
        }
        case 'A':
        {
            // deleteGraph_cmd(g->head);
            scanf(" %c", &userInput); // tells me how many nodes there are
            g->size = (userInput - '0');
            pnode arr[g->size]; // IMPORTANT - no need to free local variables.
            for (int i = 0; i < g->size; i++)
            {
                arr[i] = (pnode)malloc(sizeof(pnode));
            }
            n = (pnode)malloc(sizeof(struct GRAPH_NODE_));
            while (true)
            {
                scanf(" %c", &userInput);

                // TODO: consider using - if ('A'<= userInput <= 'Z')
                if (userInput == 'A' || userInput == 'B' || userInput == 'D' || userInput == 'S' || userInput == 'T' /* this is the nastiest IF */
                    || userInput == 'P' || userInput == 'E')
                {
                    updateEndpoints(g, arr);
                    // free(arr);
                    goto SC;
                    break; // just in case.
                }

                if (userInput == 'n' || userInput == 'N')
                {
                    n2->next = n->next;
                    n->next = (node *)malloc(sizeof(struct GRAPH_NODE_));
                    // n->next->node_num = NULL;
                    n->next->next = n2->next;
                    n->next->edges = NULL;
                    flag = true;
                }
                else
                {
                    if (flag)
                    {
                        n->next->node_num = (userInput - '0');
                        arr[userInput - '0']->next = n->next;
                        flag = false;
                    }
                    else
                    {
                        e->next = n->next->edges;
                        n->next->edges = (pedge)malloc(sizeof(struct edge_));
                        n->next->edges->dest = (userInput - '0');
                        n->next->edges->endpoint = (pnode)malloc(sizeof(pnode));
                        scanf(" %c", &userInput);
                        n->next->edges->weight = (userInput - '0');
                        n->next->edges->next = e->next;
                    }
                }
            }
            updateEndpoints(g, arr);
            break;
        }
        case 'B':
        {
            goto SC;
            break;
        }
        case 'D':
        {
            break;
        }
        case 'S':
        {
            break;
        }
        case 'T':
        {
            break;
        }
        default:
        {
            break;
        }
        }
    }
    free(e);
    free(n);
    free(n2);
    free(g);
    return 0;
}