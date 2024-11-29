#include "logic.h"

STATION* init_stations() {
    STATION *st = malloc(10 * sizeof(STATION)); 
    if (st == NULL) {
        perror("Failed to allocate memory");
        return NULL; 
    }

    strcpy(st[0].name, "St #1"); st[0].count_links = 0; st[0].steps = unknown;
    strcpy(st[1].name, "St #2"); st[1].count_links = 0; st[1].steps = unknown;
    strcpy(st[2].name, "St #3"); st[2].count_links = 0; st[2].steps = unknown;
    strcpy(st[3].name, "St #4"); st[3].count_links = 0; st[3].steps = unknown;
    strcpy(st[4].name, "St #5"); st[4].count_links = 0; st[4].steps = unknown;
    strcpy(st[5].name, "St #6"); st[5].count_links = 0; st[5].steps = unknown;
    strcpy(st[6].name, "St #7"); st[6].count_links = 0; st[6].steps = unknown;
    strcpy(st[7].name, "St #8"); st[7].count_links = 0; st[7].steps = unknown;
    strcpy(st[8].name, "St #9"); st[8].count_links = 0; st[8].steps = unknown;
    strcpy(st[9].name, "St #10"); st[9].count_links = 0; st[9].steps = unknown;
    return st; 
}

void free_stations(STATION* st) {
    free(st);
}

void setup_all_stations_links(STATION *st) {
    set_station_links(&st[0], 2, &st[1], &st[2]);
    set_station_links(&st[1], 3, &st[0], &st[3], &st[4]);
    set_station_links(&st[2], 2, &st[0], &st[5]);
    set_station_links(&st[3], 2, &st[1], &st[5]);
    set_station_links(&st[4], 2, &st[1], &st[7]);
    set_station_links(&st[5], 4, &st[2], &st[3], &st[6], &st[8]);
    set_station_links(&st[6], 2, &st[5], &st[8]);
    set_station_links(&st[7], 2, &st[4], &st[8]);
    set_station_links(&st[8], 4, &st[5], &st[6], &st[7], &st[9]);
    set_station_links(&st[9], 1, &st[8]);
}

void set_station_links(STATION* st, int count_links, ...) {
    va_list arg;     
    va_start(arg, count_links); 

    st->count_links = count_links; 

    for (int i = 0; i < count_links; i++) 
        st->links[i] = va_arg(arg, STATION*);

    va_end(arg);
}

void set_steps(STATION* from, int step) {

    if (from->steps == unknown || from->steps > step)
        from->steps = step;
    else 
        return; 
    
    for (int i = 0; i < from->count_links; i++) 
        set_steps(from->links[i], step + 1);
}


STATION * smallest_prev (STATION* current) {
    int prev_steps = current->steps - 1;

    for (int i = 0; i < current->count_links; i++) {
        if (current->links[i]->steps == prev_steps) {
            return current->links[i];
        }
    } 
}

void find_path(STATION* from, STATION* to, STATION *path[], int* count_st) {
    
    set_steps(from, 0);

    // станций (вершин) будет на 1 больше, чем шагов (ребер).❓
    int num_of_stations = to->steps + 1; // локальная переменная для удобства
    *count_st = num_of_stations;

    STATION * current = to; 

     for (int i = num_of_stations - 1; i >= 0; i--) {
        path[i] = current; 
        current = smallest_prev(current); 

        if (i == 0) {
            path[i] = from;
        }
    }
}




int ask_for_stations(int * p1, int * p2) {

    int scanf_res = 0;

    printf("------------------\n");

    do {
        printf("from station (1 - %d): ", max_path_station);
        scanf_res = scanf("%d", p1);
        if (!scanf_res) 
            return 0;

    } while (*p1 < 1 || *p1 > max_path_station);
    
    
    do {
        printf("  to station (1 - %d): ", max_path_station);
        scanf_res = scanf("%d", p2);
        if (!scanf_res) 
            return 0;

    } while (*p2 < 1 || *p2 > max_path_station);
    
    return 1;
}


void print_path(STATION *path[], int count_st) {
    printf("------------------\n");
    for (int i = 0; i < count_st; i++) 
        printf("step %d - %s \n", i + 1, path[i]->name);
    printf("------------------\n");
}
