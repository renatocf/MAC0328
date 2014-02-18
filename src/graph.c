/* Default libraries */
#include <stdlib.h>

/* Libraries */
#include "GRAPH.h"

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
