#include "AMLGraph.h"

int main() {
    AMLGraph G;
    CreateDN(&G);
    PrintEdges(&G);
    printf("ɾ�� A-B �ߣ�\n");
    DeleteEdge(&G, 'A', 'B');
    PrintEdges(&G);
    DeleteDN(&G);
    PrintEdges(&G);
    return 0;
}
