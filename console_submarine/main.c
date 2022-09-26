#include <stdio.h>
#include <string.h>
#include "ships.h"
#include <stdlib.h>


void generate_ships() {
    int area[12][12] = { 0 };
    generate_ship(area, 4);
    printf("after 1st:\n");
    print_area_0(area);
    generate_ship(area, 3);
    printf("after 2nd:\n");
    print_area_0(area);
    generate_ship(area, 3);
    printf("after 3rd:\n");
    print_area_0(area);
    generate_ship(area, 2);
    printf("after 4th:\n");
    print_area_0(area);
    generate_ship(area, 2);
    printf("after 5th:\n");
    print_area_0(area);
    generate_ship(area, 2);
    printf("after 6th:\n");
    print_area_0(area);
    generate_ship(area, 1);
    printf("after 7th:\n");
    print_area_0(area);
    generate_ship(area, 1);
    printf("after 8th:\n");
    print_area_0(area);
    generate_ship(area, 1);
    printf("after 9th:\n");
    print_area_0(area);
    generate_ship(area, 1);
    printf("after 10th:\n");
    print_area_0(area);
    for (int i = 0; i < 10; i++)
    {
        printf("ship id:%d\n", ships[i].id);
        printf("ship health:%d\n", ships[i].health);
        printf("ship 1st cell: %d,%d\n", ships[i].coords[0][0], ships[i].coords[0][1]);
        printf("ship 2st cell: %d,%d\n", ships[i].coords[1][0], ships[i].coords[1][1]);
        printf("ship 3st cell: %d,%d\n", ships[i].coords[2][0], ships[i].coords[2][1]);
        printf("ship 4st cell: %d,%d\n", ships[i].coords[3][0], ships[i].coords[3][1]);
        printf("==================================\n");
    }
}


void main() {
    generate_ships();
}