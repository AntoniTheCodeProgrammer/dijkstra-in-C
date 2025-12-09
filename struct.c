#include "struct.h"

Vertex *new_Vertex(Vertex** vertex, int i, Vertex* tail){
    printf("new vertex");
    Vertex* v = malloc(sizeof(Vertex));
    v->ID = i;
    v->road = NULL;
    v->next = NULL;

    if (tail != NULL) {
        tail->next = v;
    } else {
        *vertex = v;
    }
    return v;
}

int create_Vertex(Vertex** vertex, char* file_name) {
    FILE* file = fopen(file_name, "r");

    if (file == NULL) {
        printf("Nie udalo sie otworzyc pliku!\n");
        return 1;
    }

    Vertex* tail = NULL;
    int n = 0;
    int parent, child;
    double weight;
    char name[256];

    while (fscanf(file, "%d %d %lf %s", &parent, &child, &weight, name) == 4) {
        while(parent > n || child > n){
            tail = new_Vertex(vertex, n, tail);
            n++;
        }

        Road* new_road = malloc(sizeof(Road));
        new_road->directionID = child;
        new_road->name = strdup(name);
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
            printf("[%d via \"%s\" (weight: %f)] ", r_ptr->directionID, r_ptr->name, r_ptr->weight);
            r_ptr = r_ptr->next;
            roads++;
        }
        if (roads == 0) {
            printf("NULL ");
        }
        printf("}\n");
        v_ptr = v_ptr->next;
    }
    printf("\n");
}

int lenght_of_vertex(Vertex* vertex) {
    Vertex* current = vertex;
    int i = 0;
    while (current != NULL) {
        current = current->next;
        i++;
    }
    return i;
}