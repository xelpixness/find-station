#include "logic.h"

int main(void) {
    
    int p1 = 0;
    int p2 = 0;

    int input_succeed = ask_for_stations(&p1, &p2); 

    if (!input_succeed) {
        printf("bad input!\n");
        return 1;
    }

    STATION * st = init_stations();
    setup_all_stations_links(st);

    // путь хранится в стековом фрейме ¯\_(ツ)_/¯
    STATION * path[max_path_station]; 
    int count_st = 0; 

    STATION * start = &st[p1 - 1];
    STATION * end = &st[p2 - 1];

    find_path(start, end, path, &count_st);
    print_path(path, count_st);

    free_stations(st);

    return 0;
}

