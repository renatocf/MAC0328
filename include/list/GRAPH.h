#ifndef H_LIST_GRAPH_DEFINED
#define H_LIST_GRAPH_DEFINED

/*
////////////////////////////////////////////////////////////////////////
-----------------------------------------------------------------------
                           GRAPH DEFINITIONS
-----------------------------------------------------------------------
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/

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

/* Node structure */
typedef struct node *link;
struct node {
    Vertex w;
    link next;
};

link NEW(Vertex w, link next);

/* Digraph and graph */
struct digraph {
    int V;
    int A;
    link *adj;
};
#define graph digraph

typedef struct digraph *Digraph;
#define Graph Digraph

#define maxV 100

/*
////////////////////////////////////////////////////////////////////////
-----------------------------------------------------------------------
                         GRAPH MANIPULATION
-----------------------------------------------------------------------
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/

/* Digraph basic functions */
Digraph DIGRAPHinit    (int V);
void    DIGRAPHinsertA (Digraph G, Vertex v, Vertex w);
void    DIGRAPHremoveA (Digraph G, Vertex v, Vertex w);
void    DIGRAPHshow    (Digraph G);
    
/* Graph basic functions */
#define GRAPHinit DIGRAPHinit
#define GRAPHshow DIGRAPHshow
void    GRAPHinsertA (Graph G, Vertex v, Vertex w);
void    GRAPHremoveA (Graph G, Vertex v, Vertex w);

/*
////////////////////////////////////////////////////////////////////////
-----------------------------------------------------------------------
                              ALGORITHMS
-----------------------------------------------------------------------
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/

void DIGRAPHdfs (Digraph G);
void dfsR       (Digraph G, Vertex v);
void dfsDump    (Digraph G);

void GRAPHbridge (Graph G);
void bridgeR     (Graph G, Vertex v);
void bridgeDump  (Graph G);

#endif
