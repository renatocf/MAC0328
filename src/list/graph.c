/* Default libraries */
#include <stdio.h>
#include <stdlib.h>

/* Libraries */
#include "list/GRAPH.h"

link NEW(Vertex w, link next)
{
    link p = malloc(sizeof *p);
    p->w = w;
    p->next = next;
    return p;
}

Digraph DIGRAPHinit(int V)
{
    Vertex v;
    Digraph G = malloc(sizeof *G);
    G->V = V;
    G->A = 0;
    G->adj = malloc(V * sizeof(link));
    for(v = 0; v < V; v++)
        G->adj[v] = NULL;
    return G;
}

void DIGRAPHinsertA(Digraph G, Vertex v, Vertex w)
{
    /* Do nothing if already insereted */
    link p;
    if(v == w) return;
    for(p = G->adj[v]; p != NULL; p = p->next)
        if(p->w == w) return;
    G->adj[v] = NEW(w,G->adj[v]);
    G->A++;
}

void DIGRAPHremoveA(Digraph G, Vertex v, Vertex w)
{
    link p, q;
    if(G->adj[v]->w == w) { free(G->adj[v]); G->A--; }
    for(p = G->adj[v]; p != NULL; p = p->next)
        if(p->next != NULL && p->next->w == w)
        {
            q = p->next;
            p->next = p->next->next;
            free(q); G->A--;
        }
}

void DIGRAPHshow(Digraph G)
{
    Vertex v;
    link p;
    for(v = 0; v < G->V; v++)
    {
        printf("%2d: ", v);
        for(p = G->adj[v]; p != NULL; p = p->next)
            printf("%d ", p->w);
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

/** DFS ***********************************************************/
static int time,dfs_parnt[maxV],d[maxV],f[maxV];
void DIGRAPHdfs(Digraph G)
{
    Vertex v;
    time = 0;
    for(v = 0; v < G->V; v++)
        dfs_parnt[v] = d[v] = f[v] = -1;
    for(v = 0; v < G->V; v++)
        if(d[v] == -1)
        {
            dfs_parnt[v] = v;
            dfsR(G,v);
        }
}

void dfsR(Digraph G, Vertex v)
{
    link p;
    d[v] = time++;
    for(p = G->adj[v]; p != NULL; p = p->next)
        if(d[p->w] == -1)
        {
            dfs_parnt[p->w] = v;
            dfsR(G,p->w);
        }
    f[v] = time++;
}
    
void dfsDump(Digraph G)
{
    Vertex v;
    printf("\n");
    for(v = 0; v < G->V; v++)
        printf("%2d: parnt:%2d [%d,%d]\n", 
                v, dfs_parnt[v], d[v], f[v]);
}

/** Bridges *******************************************************/
static int bridge_cnt, pre[maxV], bridge_bcnt, low[maxV];
static int bridge_parnt[maxV];
void GRAPHbridge(Graph G)
{
    Vertex v;
    bridge_cnt = bridge_bcnt = 0;
    for(v = 0; v < G->V; v++)
        pre[v] = -1;
    for(v = 0; v < G->V; v++)
        if(pre[v] == -1)
        {
            bridge_parnt[v] = v;
            bridgeR(G,v);
        }
}

void bridgeR(Graph G, Vertex v)
{
    link p; Vertex u;
    low[v] = pre[v] = bridge_cnt++;
    for(p = G->adj[v]; p; p = p->next)
    {
        if(pre[u = p->w] == -1)
        {
            bridge_parnt[u] = v;
            bridgeR(G,u);
            if(low[v] > low[u]) low[v] = low[u];
            else if(low[u] == pre[u]) {
                bridge_bcnt++;
                printf("Bridge found: Edge %d-%d", v, u);
            }
        }
        else if(u != bridge_parnt[v] && low[v] > low[u]) /* descendent */
            low[v] = low[u];
    }
}

void bridgeDump(Graph G)
{
    Vertex v;
    printf("\n");
    printf("%d bridges found!\n", bridge_bcnt);
    for(v = 0; v < G->V; v++)
        printf("%2d: parnt:%2d [pre:%d,low:%d]\n", 
                v, bridge_parnt[v], pre[v], low[v]);
}
