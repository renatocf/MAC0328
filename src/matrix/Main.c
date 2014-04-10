/* Default libraries */
#include <stdio.h>
#include <stdlib.h>

/* Libraries */
#include "matrix/GRAPH.h"

int main()
{
    /** INITIALIZATION ************************************************/
        Digraph G = DIGRAPHinit(6);
        Graph   H = GRAPHinit(6);
        
    /** DIGRAPH *******************************************************/
        printf("\n-- DIGRAPH ------------------\n");
        
        DIGRAPHinsertA(G,0,2);
        DIGRAPHinsertA(G,0,3);
        DIGRAPHinsertA(G,0,4);
        DIGRAPHinsertA(G,2,1);
        DIGRAPHinsertA(G,2,4);
        DIGRAPHinsertA(G,3,4);
        DIGRAPHinsertA(G,3,5);
        DIGRAPHinsertA(G,4,1);
        DIGRAPHinsertA(G,4,5);
        DIGRAPHinsertA(G,5,1);
        
        DIGRAPHshow(G);
        
        if(DIGRAPHpath(G,0,1))
            printf("There is path between 0 and 1\n");
        if(st_cut(G,0,1))
            printf("There is a cut between 0 and 1\n");
        if(st_path(G,0,1))
            printf("There is path between 0 and 1\n");
        
        if(DIGRAPHpath(G,5,4))
            printf("There is path between 5 and 4\n");
        if(st_cut(G,5,4))
            printf("There is a cut between 5 and 4\n");
        if(st_path(G,5,4))
            printf("There is path between 5 and 4\n");
    
    /** GRAPH *********************************************************/
        printf("\n-- GRAPH --------------------\n");
        
        GRAPHinsertA(H,0,2);
        GRAPHinsertA(H,0,3);
        GRAPHinsertA(H,0,4);
        GRAPHinsertA(H,2,1);
        GRAPHinsertA(H,2,4);
        GRAPHinsertA(H,3,4);
        GRAPHinsertA(H,3,5);
        GRAPHinsertA(H,4,1);
        GRAPHinsertA(H,4,5);
        GRAPHinsertA(H,5,1);
        
        GRAPHshow(H);
        
    /** MEMORY FREE ********8******************************************/
        printf("\n");
        free(G); /* Free Digraph */
        free(H); /* Free Graph */
    
    return 0;
}
