#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "graph.h"

// HELPERS

void createGraph(char *str) // 4n12234n12355n13456
{
    node *temp = (node *)malloc(sizeof(struct GRAPH_NODE_));
    int i = 1;
    bool flag = true;
    int nodes = (int)str[0];
    while (i < strlen(str)){
        if (str[i] == 'n'){
            temp->next = (node *)malloc(sizeof(struct GRAPH_NODE_));
            flag = true;
        }
        else {
            if (flag){
                temp->next->node_num = (int)str[i];
                flag = false;
            }
            else {
                temp->next->edges = (edge *)malloc(sizeof(struct edge_));
                temp->next->edges->endpoint = NULL;
                temp->next->edges->weight = (int)str[i+1];
                i++;
            }
        }
        i++;
    }

    build_graph_cmd(temp->next);
    free(temp);
}

// MAIN

int main()
{
    char c;
    char userInput;
    bool flag = true;
    bool new = true;
    int temp;
    //int nodeid;
    pnode n;

    graph *g = (graph *)malloc(sizeof(struct Graph_));

    while (flag)
    {
        userInput = getchar();
        switch (userInput)
        {
        case 'E': // EXIT
            flag = false;
            break;
        case 'P': // PRINT
            printGraph_cmd(g->head);
        case 'A':
            deleteGraph_cmd(g->head);
            /* convert to string */
        }
    }
    return 0;
}