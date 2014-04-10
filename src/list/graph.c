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
static int brg_cnt, brg_pre[maxV], brg_bcnt, brg_low[maxV];
static int brg_parnt[maxV];
void GRAPHbridge(Graph G)
{
    Vertex v;
    brg_cnt = brg_bcnt = 0;
    for(v = 0; v < G->V; v++)
        brg_pre[v] = -1;
    for(v = 0; v < G->V; v++)
        if(brg_pre[v] == -1)
        {
            brg_parnt[v] = v;
            bridgeR(G,v);
        }
}

void bridgeR(Graph G, Vertex v)
{
    link p; Vertex u;
    brg_low[v] = brg_pre[v] = brg_cnt++;
    for(p = G->adj[v]; p; p = p->next)
    {
        if(brg_pre[u = p->w] == -1)
        {
            brg_parnt[u] = v;
            bridgeR(G,u);
            if(brg_low[v] > brg_low[u]) brg_low[v] = brg_low[u];
            else if(brg_low[u] == brg_pre[u]) {
                brg_bcnt++;
                printf("Bridge found: %d-%d\n", v, u);
            }
        }
        /* return arc */
        else if(u != brg_parnt[v] && brg_low[v] > brg_low[u])
            brg_low[v] = brg_low[u];
    }
}

void bridgeDump(Graph G)
{
    Vertex v;
    printf("\n");
    printf("%d bridges found!\n", brg_bcnt);
    for(v = 0; v < G->V; v++)
        printf("%2d: parnt:%2d [brg_pre:%d,brg_low:%d]\n", 
                v, brg_parnt[v], brg_pre[v], brg_low[v]);
}

/** Articulation **************************************************/
static int art_cnt, art_pre[maxV], art_bcnt, art_low[maxV];
static int art_parnt[maxV];
static int depth = 0;
void GRAPHartic(Graph G)
{
    Vertex v;
    depth = 0;
    art_cnt = art_bcnt = 0;
    for(v = 0; v < G->V; v++)
        art_pre[v] = -1;
    for(v = 0; v < G->V; v++)
        if(art_pre[v] == -1)
        {
            art_parnt[v] = v;
            articR(G,v);
        }
}

void articR(Graph G, Vertex v)
{
    link p; Vertex u;
    int n_sons = 0;
    int aux = depth++;
    art_low[v] = art_pre[v] = art_cnt++;
    while(aux--) printf(" "); printf("articR(%d)\n", v);
    for(p = G->adj[v]; p; p = p->next)
    {
        if(art_pre[u = p->w] == -1)
        {
            art_parnt[u] = v;
            n_sons++;
            articR(G,u);
            /* Check if son's low > our low */
            if(art_low[v] > art_low[u]) art_low[v] = art_low[u];
            /* else if(art_low[u] == art_pre[u]) { */
            /*     art_bcnt++; */
            /*     printf("Articulation found: %d\n", v); */
            /* } */
        }
        /* return arc */
        /* else if(u != art_parnt[v] && art_low[v] > art_pre[u]) */
            /* art_low[v] = art_pre[u]; */
    }
    if(art_low[v] == art_pre[v]) {
        art_bcnt++;
        printf("Articulation found: %d\n", v);
    }
    depth--;
}

void articDump(Graph G)
{
    Vertex v;
    printf("\n");
    printf("%d articulations found!\n", art_bcnt);
    for(v = 0; v < G->V; v++)
        printf("%2d: parnt:%2d [art_pre:%d,art_low:%d]\n", 
                v, art_parnt[v], art_pre[v], art_low[v]);
}
