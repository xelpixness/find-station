#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

enum { 
    name_length=50,
    total_links=50,
    max_path_station=10,
    unknown=-1, // для инициализации шагов
};

typedef struct tag_station {
    char name[name_length];
    struct tag_station* links[total_links];
    short count_links;
    char steps;
} STATION;

int ask_for_stations(int * p1, int * p2);

STATION* init_stations();
void free_stations(STATION* st);

void setup_all_stations_links(STATION *st);
void set_station_links(STATION* st, int count_links, ...);

STATION * smallest_prev (STATION* current); 

void set_steps(STATION* from, int step);
void find_path(STATION* from, STATION* to, STATION *path[], int* count_st);
void print_path(STATION *path[], int count_st);

