#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "graph.h"

// HELPERS

void updateEndpoint(graph *g, pnode *arr)
{
    node *next = g->head;
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

pnode getNode(int id, graph *g)
{
    node *next = g->head;

    while (next != NULL)
    {
        if(next->node_num == id)
        {
            return next;
        }
        next = next->next;
    } 
    return NULL;
}

// MAIN

int main()
{
    // char c;
    // int i;
    char userInput;
    bool flag = true;
    int temp;
    //  int nodeid;
    pnode n = NULL;
    pnode n2 = (pnode)malloc(sizeof(pnode));
    pedge e = (pedge)malloc(sizeof(pedge));

    graph *g = (graph *)malloc(sizeof(struct Graph_));
    g->head = (pnode)malloc(sizeof(pnode));
    g->head = n;
    g->init = 0;
    while (true)
    {
        userInput = getchar();
    SC:
        switch (userInput)
        {
        case 'E': // EXIT
        {
            return 0;
            break;
        }
        case 'P': // PRINT
        {
            printGraph_cmd(g);
            break;
        }
        case 'A':
        {
            //deleteGraph_cmd(g->head);
            scanf(" %c", &userInput); // tells me how many nodes there are
            g->size = (userInput - '0');
            pnode arr[g->size]; // IMPORTANT - no need to free local variables.
            for (int i = 0; i < g->size; i++)
            {
                arr[i] = (pnode)malloc(sizeof(pnode)); // TODO: FREE
            }
            n = (pnode)malloc(sizeof(struct GRAPH_NODE_));
            while (true)
            {
                scanf(" %c", &userInput);

                // TODO: consider using - if ('A'<= userInput <= 'Z')
                if (userInput == 'A' || userInput == 'B' || userInput == 'D' || userInput == 'S' || userInput == 'T' /* this is the nastiest IF */
                    || userInput == 'P' || userInput == 'E')
                {
                    // TODO: figure out how to just break to leave the loop.
                    g->head = n->next;
                    updateEndpoint(g, arr);
                    build_graph_cmd(g);
                    //build_graph_cmd(&(n->next));
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
                    n->next->tag = NULL;
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
            updateEndpoint(g, arr);
            //build_graph_cmd(&(n->next));
            break;
        }
        case 'B':
        {
            scanf("%c", &userInput);
            n = (node *)malloc(sizeof(struct GRAPH_NODE_));
            n->node_num = (userInput - '0');
            n->next = NULL;
            n->edges = NULL;

            while (true)
            {
                scanf(" %c", &userInput);
                if (userInput == 'A' || userInput == 'B' || userInput == 'D' || userInput == 'S' || userInput == 'T' /* this is the nastiest IF */
                    || userInput == 'P' || userInput == 'E')
                {
                    insert_node_cmd(n);
                    goto SC;
                    break;
                }
                
                e->next = n->edges;
                n->edges = (pedge)malloc(sizeof(struct edge_));
                n->edges->dest = (userInput - '0');
                n->edges->endpoint = getNode(n->edges->dest, g);
                scanf(" %c", &userInput);
                n->edges->weight = (userInput - '0');
                n->edges->next = e->next;
            }

            insert_node_cmd(n);
            break;
        }
        case 'D':
        {
            scanf("%c",&userInput);
            delete_node_cmd(userInput-'0');
            break;
        }
        case 'S':
        {
            scanf("%c",&userInput);
            temp = (userInput -'0');
            scanf("%c",&userInput);
            shortsPath_cmd(temp, (userInput - '0'));
            scanf("%c",&userInput);
            goto SC;
            break;
        }
        case 'T':
        {
            //scanf("%c", &userInput);
            int *cities = (int*)malloc(sizeof(int)*g->size); //assumes size is relevant!
            int i = 0;
            while (!(userInput == 'A' || userInput == 'B' || userInput == 'D' || userInput == 'S' || userInput == 'T' /* this is the nastiest IF */
                    || userInput == 'P' || userInput == 'E'))
            {
                scanf(" %c", &userInput);
                cities[i++] = userInput -'0'; // -> cities[0] is source.
            }
            TSP_cmd(cities);
            goto SC;
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