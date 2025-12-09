#ifndef STRUCT_H
#define STRUCT_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Road {
    int directionID;
    char* name;
    double weight;
    struct Road* next;
} Road;

typedef struct Vertex {
    int ID;
    struct Road* road;
    struct Vertex* next;
} Vertex;

typedef struct Fastest {
    double distance;
    bool final;
    int parent;
    char* road_name;
} Fastest;

int create_Vertex(Vertex** vertex, char* file_name);
void print_vertex(Vertex* vertex);
int lenght_of_vertex(Vertex* vertex);

#endif