#include "struct.h"

int create_Vertex(Vertex** vertex, char* file_name) {
    FILE* file = fopen(file_name, "r");

    if (file == NULL) {
        printf("Nie udalo sie otworzyc pliku!\n");
        return 1;
    }
    int n = 0;
    int m = 0;

    fscanf(file, "%d %d", &n, &m);

    Vertex* tail = NULL;
    for (int i = 0; i < n; i++) {
        Vertex* v = malloc(sizeof(Vertex));
        v->ID = i;
        v->road = NULL;
        v->next = NULL;

        if (tail != NULL) {
            tail->next = v;
        } else {
            *vertex = v;
        }
        tail = v;
    }

    int parent, child, weight;
    for (int i = 0; i < m; i++) {
        fscanf(file, "%d %d %d", &parent, &child, &weight);
        Road* new_road = malloc(sizeof(Road));
        new_road->directionID = child;
        new_road->weight = weight;
        Vertex* current = *vertex;
        while (current != NULL && current->ID != parent) {
            current = current->next;
        }
        if (current != NULL) {
            new_road->next = current->road;
            current->road = new_road;
        }
    }
    fclose(file);

    return 0;
}

void print_vertex(Vertex* vertex) {
    Vertex* v_ptr = vertex;
    printf("Structure:\n");
    while (v_ptr != NULL) {
        printf("%i -> { ", v_ptr->ID);
        Road* r_ptr = v_ptr->road;
        int roads = 0;
        while (r_ptr != NULL) {
            printf("[%d (weight: %d)] ", r_ptr->directionID, r_ptr->weight);
            r_ptr = r_ptr->next;
            roads++;
        }
        if(roads == 0){
            printf("NULL ");
        }
        printf("}\n");
        v_ptr = v_ptr->next;
    }
    printf("\n");
}