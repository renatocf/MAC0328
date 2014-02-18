#ifndef H_GRAPH_DEFINED
#define H_GRAPH_DEFINED

/* Vertex, Arc and Edge */
#define Vertex int
typedef struct {
    Vertex v;
    Vertex w;
} Arc;
#define Edge Arc

/* Create new Arc/new Edge */
Arc ARC(Vertex v, Vertex w);
#define EDGE ARC

/* Initialize an integer Matrix */
int **MATRIXint(int r, int c, int val);

/* Digraph and graph */
struct digraph {
    int V;
    int A;
    int **adj;
};
#define graph digraph

typedef struct digraph *Digraph;
#define Graph Digraph

/* Function to manipulate digraph */
Digraph DIGRAPHinit(int V);
    
/* Function to manipulate graph */
#define GRAPHinit DIGRAPHinit

#endif
