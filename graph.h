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
    int dist;
    struct GRAPH_NODE_ *tag;
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
    //struct GRAPH_NODE_ *orig;  //this helps with PQ
    int visited;
    struct GRAPH_NODE_ *pqnext; // same^.- instead of copyGraph()
} node, *pnode;

typedef struct Graph_{
    int init;
    int size;
    pnode head;
} graph, *pgraph;

// ADDED SIGNATURES

void free_edges_mem(pnode head);
pnode dijkstra(int src, int dest);

// ORIGINAL SIGNATURES

void build_graph_cmd(graph *g);
void insert_node_cmd(pnode head);
void delete_node_cmd(int id);
void printGraph_cmd(graph *g); // for self debug
void deleteGraph_cmd(pnode *head);
void shortsPath_cmd(int src, int dest);
void TSP_cmd(graph *g);

#endif
