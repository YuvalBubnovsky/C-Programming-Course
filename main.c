#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "graph.h"

// HELPERS

// MAIN

int main()
{
    //char c;
    //int i;
    char userInput;
    bool flag = true;
    int temp;
    // int nodeid;
    pnode n = NULL;
    pnode n2 = (pnode)malloc(sizeof(pnode));
    pedge e = (pedge)malloc(sizeof(pedge));

    graph *g = (graph *)malloc(sizeof(struct Graph_));
    g->head = &n;
    while (true)
    {
        userInput = getchar();
        SC: switch (userInput)
        {
        case 'E': // EXIT
            break;
        case 'P': // PRINT
            printGraph_cmd(*(g->head));
        case 'A':
            //deleteGraph_cmd(g->head);
            scanf(" %c", &userInput); // tells me how many nodes there are
            pnode arr[(int)(userInput - '0')];
            for(int i=0;i<(userInput - '0'); i++){
                arr[i] = (pnode)malloc(sizeof(pnode));
            }
            n = (pnode)malloc(sizeof(struct GRAPH_NODE_));
            while (true)
            {
                scanf(" %c", &userInput);

                //TODO: consider using - if ('A'<= userInput <= 'Z')
                if (userInput == 'A' || userInput == 'B' || userInput == 'D' 
                || userInput == 'S' || userInput == 'T' /* this is the nastiest IF */
                || userInput == 'P' || userInput == 'E')
                {
                    // TODO: goto relevant case
                    // something like, userInput = (char)temp
                    // then goto line 59 (switch case)
                    //userInput = (char)temp;
                    goto SC;
                }

                if (userInput == 'n' || userInput == 'N')
                {
                    /*
                    if (n->next == NULL)
                    {
                        n->next = (node *)malloc(sizeof(struct GRAPH_NODE_));
                        // n->next->node_num = NULL;
                        n->next->next = NULL;
                        n->next->edges = NULL;
                        flag = true;
                    }
                    else{*/
                        n2->next = n->next;
                        n->next = (node *)malloc(sizeof(struct GRAPH_NODE_));
                        // n->next->node_num = NULL;
                        n->next->next = n2->next;
                        n->next->edges = NULL;
                        flag = true;
                    //}
                }
                else
                {
                    if (flag)
                    {
                        n->next->node_num = (userInput - '0');
                        arr[userInput - '0']->next = n->next; //TODO: consider arr[id] = n->next instead
                        flag = false;
                    }
                    else
                    {
                        /*
                        if (n->next->edges == NULL)
                        {
                            n->next->edges = (pedge)malloc(sizeof(struct edge_));
                            n->next->edges->endpoint = arr[temp]->next; // potentially wrong - if so try without arr->next
                            scanf("%d", &temp);
                            n->next->edges->weight = temp;
                            n->next->edges->next = NULL;
                        }
                        else
                        {*/
                            e->next = n->next->edges;
                            n->next->edges = (pedge)malloc(sizeof(struct edge_));
                            n->next->edges->endpoint = arr[userInput - '0'];
                            scanf(" %c", &userInput);
                            n->next->edges->weight = (userInput - '0');
                            n->next->edges->next = e->next;
                        //}
                    }
                }
                
            }
            // TODO: if arr[temp]->next is wrong, update every endpoint here!
            free(arr);
        }
    }
    free(e);
    free(n);
    free(n2);
    return 0;
}