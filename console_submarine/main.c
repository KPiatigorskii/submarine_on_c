#include <stdio.h>
#include <string.h>
#include "ships.h"
#include <stdlib.h>

void main() {
    int area[12][12] = {0};
    generate_ship(area,4);
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
};