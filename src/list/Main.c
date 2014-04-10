/* Default libraries */
#include <stdio.h>
#include <stdlib.h>

/* Libraries */
#include "list/GRAPH.h"

int main()
{
    /** INITIALIZATION ************************************************/
        Digraph G = DIGRAPHinit(8);
        Graph   H = GRAPHinit(11);
        
    /** DIGRAPH *******************************************************/
        printf("\n-- DIGRAPH ------------------\n");
        
        DIGRAPHinsertA(G,0,7);
        DIGRAPHinsertA(G,0,5);
        DIGRAPHinsertA(G,7,1);
        DIGRAPHinsertA(G,5,7);
        DIGRAPHinsertA(G,5,2);
        DIGRAPHinsertA(G,2,1);
        DIGRAPHinsertA(G,1,5);
        DIGRAPHinsertA(G,3,6);
        DIGRAPHinsertA(G,6,4);
        DIGRAPHinsertA(G,6,3);
        DIGRAPHinsertA(G,3,4);
        DIGRAPHinsertA(G,4,7);
        DIGRAPHinsertA(G,4,0);
        
        DIGRAPHshow(G);
        
    /** GRAPH *********************************************************/
        printf("\n-- GRAPH --------------------\n");
        
        GRAPHinsertA(H,0,2);
        GRAPHinsertA(H,0,3);
        GRAPHinsertA(H,2,8);
        GRAPHinsertA(H,2,3);
        GRAPHinsertA(H,3,8);
        GRAPHinsertA(H,8,10);
        GRAPHinsertA(H,8,1);
        GRAPHinsertA(H,10,7);
        GRAPHinsertA(H,10,4);
        GRAPHinsertA(H,4,9);
        GRAPHinsertA(H,4,7);
        GRAPHinsertA(H,9,6);
        GRAPHinsertA(H,9,5);
        GRAPHinsertA(H,5,6);
        
        GRAPHshow(H);
        
        GRAPHbridge(H);
        bridgeDump(H);
        
        GRAPHartic(H);
        articDump(H);
        
    /** MEMORY FREE ********8******************************************/
        printf("\n");
        free(G); /* Free Digraph */
        free(H); /* Free Graph */
    
    return 0;
}
