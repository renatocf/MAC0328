/* Default libraries */
#include <stdlib.h>

/* Libraries */
#include "GRAPH.h"

int main()
{
    Graph g = GRAPHinit(5);
    free(g);
    return 0;
}
