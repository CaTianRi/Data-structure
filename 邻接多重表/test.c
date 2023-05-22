#include "AMLGraph.h"

int main() {
    AMLGraph G;
    CreateDN(&G);
    PrintEdges(&G);
    printf("É¾³ý A-B ±ß£º\n");
    DeleteEdge(&G, 'A', 'B');
    PrintEdges(&G);
    DeleteDN(&G);
    PrintEdges(&G);
    return 0;
}
