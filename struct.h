#ifndef STRUCT_H
#define STRUCT_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Road {
    int directionID;
    int weight;
    struct Road* next;
} Road;

typedef struct Vertex {
    int ID;
    struct Road* road;
    struct Vertex* next;
} Vertex;

typedef struct Fastest {
    int distance;
    bool final;
    int parent;
} Fastest;

int create_Vertex(Vertex** vertex, char* file_name);

#endif