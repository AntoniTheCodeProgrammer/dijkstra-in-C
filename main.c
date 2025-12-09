#include <stdio.h>
#include <stdlib.h>

#include "dijkstra.h"
#include "struct.h"

int main() {
    Vertex* vertex = NULL;
    if (create_Vertex(&vertex, "data.txt") != 0) {
        return 1;
    }

    print_vertex(vertex);

    dijkstra(vertex, 0, 6);
    return 0;
}
