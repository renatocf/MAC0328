/* Default libraries */
#include <stdio.h>
#include <stdlib.h>

/* Libraries */
#include "GRAPH.h"

/* Complexity: Theta(r*c) */
int **MATRIXint(int r, int c, int val)
{
    Vertex i, j;
    int **M = malloc(r * sizeof(int *));
    for(i = 0; i < r; i++)
        M[i] = malloc(c * sizeof(int));
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            M[i][j] = val;
    
    return M;
}

Digraph DIGRAPHinit(int V)
{
    Digraph G = malloc(sizeof(*G));
    G->V = V;
    G->A = 0;
    G->adj = MATRIXint(V, V, 0);
    return G;
}

void DIGRAPHinsertA(Digraph G, Vertex v, Vertex w)
{
    if(v != w && !G->adj[v][w]) {
        G->adj[v][w] = 1;
        G->A++; /* The if is needed mainly to avoid this sum */
    }
}

void DIGRAPHremoveA(Digraph G, Vertex v, Vertex w)
{
    if(G->adj[v][w])
    {
        G->adj[v][w] = 0;
        G->A--;
    }
}

void DIGRAPHshow(Digraph G)
{
    Vertex v, w;
    for(v = 0; v < G->V; v++)
    {
        printf("%d:", v);
        for(w = 0; w < G->V; w++)
            if(G->adj[v][w] == 1)
                printf(" %d", w);
        printf("\n");
    }
}

void GRAPHinsertA(Graph G, Vertex v, Vertex w)
{
    DIGRAPHinsertA(G,v,w);
    DIGRAPHinsertA(G,w,v);
}

void GRAPHremoveA(Graph G, Vertex v, Vertex w)
{
    DIGRAPHremoveA(G,v,w);
    DIGRAPHremoveA(G,w,v);
}

static int lbl[maxV], parnt[maxV];
int DIGRAPHpath(Digraph G, Vertex s, Vertex t)
{
    Vertex v;
    for(v = 0; v < G->V; v++) 
    {
        lbl[v] = 0;
        parnt[v] = -1;
    }
    
    parnt[s] = s;
    pathR(G,s);
    
    return lbl[t];
}

void pathR(Digraph G, Vertex v)
{
    Vertex w;
    lbl[v] = 1;
    for(w = 0; w < G->V; w++)
        if(G->adj[v][w] && !lbl[w])
        {
            parnt[w] = v;
            pathR(G,w);
        }
}

int st_cut(Digraph G, Vertex s, Vertex t)
{
    /* S := {v : lbl[v] == 1} */
    /* T := {v : lbl[v] == 0} */
    Vertex v, w;
    
    /* If there is a path, nothing to do */
    if(!lbl[s] || lbl[t]) return 0;
    
    /* Otherwise, check for each connected pair (v,w)
     * if v is in S, then w is in T */
    for(v = 0; v < G->V; v++)
        for(w = 0; w < G->V; w++)
            /* v is in S, w is in T, in a ST-cut */
            if(G->adj[v][w] && lbl[v] && !lbl[w])
                return 0;
    return 1;
}

int st_path(Digraph G, Vertex s, Vertex t)
{
    Vertex v, w;
    
    /* Base: t is not in the arborescence.
     *       s is not the root of the arborescence. */
    if(parnt[t] == -1 || parnt[s] != s) return 0;
    
    /* Pass: reverse the parnt's untill get in 's' */ 
    for(w = t; w != s; w = v)
    {
        v = parnt[w];
        if(!G->adj[v][w]) return 0;
    }
    return 1;
}
