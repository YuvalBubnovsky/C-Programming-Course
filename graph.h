#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;
;

typedef struct edge_
{
    int weight;
    int dest;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;

typedef struct GRAPH_NODE_
{
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

typedef struct Graph_{
    int init;
    int size;
    pnode head;
} graph, *pgraph;

// ADDED SIGNATURES

void free_edges_mem(pnode head);
void dijkstra();

// ORIGINAL SIGNATURES

void build_graph_cmd(graph *head);
void insert_node_cmd(pnode head);
void delete_node_cmd(int id);
void printGraph_cmd(graph *head); // for self debug
void deleteGraph_cmd(pnode *head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);

#endif
