#ifndef H_GRAPH_DEFINED
#define H_GRAPH_DEFINED

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

int  DIGRAPHpath (Digraph G, Vertex s, Vertex t);
void pathR       (Digraph G, Vertex v);
int  st_cut      (Digraph G, Vertex s, Vertex t);
int  st_path     (Digraph G, Vertex s, Vertex t);

#endif
