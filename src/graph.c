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

int DIGRAPHpath(Digraph G, Vertex s, Vertex t)
{
    return 1;
}
