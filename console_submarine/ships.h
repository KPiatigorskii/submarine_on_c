#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include <string.h>

int ship_counter = 0;

struct Ship
{
    int coords[4][2];
    int id;
    int health;
};

struct Ship ships[10];

int* get_coords(int x, int y, int deck_count, int direction) {
    int arr[2];
    switch (direction) {
    case 0:
        arr[0] = x;
        arr[1] = y - deck_count + 1;
        break;
    case 1:
        arr[0] = x + deck_count - 1;
        arr[1] = y;
        break;
    case 2:
        arr[0] = x;
        arr[1] = y + deck_count - 1;
        break;
    case 3:
        arr[0] = x - deck_count + 1;
        arr[1] = y;
        break;
    default:
        break;
    }
    return arr;

}

int* get_adders(int direction) {
    int dir_arr[2];
    switch (direction) {
    case 0:
        dir_arr[0] = 1;
        dir_arr[1] = -1;
        break;
    case 1:
        dir_arr[0] = 1;
        dir_arr[1] = 1;
        break;
    case 2:
        dir_arr[0] = 1;
        dir_arr[1] = 1;
        break;
    case 3:
        dir_arr[0] = -1;
        dir_arr[1] = 1;
        break;

    default:
        dir_arr[0] = 1;
        dir_arr[1] = -1;
        break;
    }
    return dir_arr;
}

void print_area_0(int area[12][12]) {
    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 11; j++)
        {
            printf("%d ", area[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int check_cells(int area[12][12], int start_x, int start_y, int stop_x, int stop_y, int adders[2], int flag) {
    int add_x = adders[0];
    int add_y = adders[1];
    printf("x_adder in check: %d\n", add_x);
    printf("y_adder in check: %d\n", add_y);
    printf("y: from %d to %d\n", (start_y - add_y), (stop_y + 1 * add_y));
    printf("x: from %d to %d\n", (start_x - add_x), (stop_x + 1 * add_x));
    for (int i = start_y - add_y; i != stop_y + 2 * add_y; i = i + add_y) {
        for (int j = start_x - add_x; j != stop_x + 2 * add_x; j = j + add_x) {
            printf("check cell {%d, %d} \n", i, j);
            if (j >= 1 && j <= 10 && i >= 1 && i <= 10) {
                printf("coordinates correct\n");
                if (area[i][j] == 2 && flag == 0) {
                    printf("detect 2 in area\n");
                    return 1;
                }
                if (flag == 1)
                    area[i][j] = 1;
            }
        }
    }

    for (int i = start_y; i != stop_y + add_y; i = i + add_y) {
        for (int j = start_x; j != stop_x + add_x; j = j + add_x) {
            if (flag == 0) {
                if (i < 1 || j < 1 || i > 10 || j > 10)
                    return 1;
            }
            else
                area[i][j] = 2;
        }
    }
    return 0;
}

void create_ship(int start_x, int start_y, int stop_x, int stop_y, int adders[2], int ship_counter)
{
    int add_x = adders[0];
    int add_y = adders[1];
    int cell_counter = 0;
    ships[ship_counter].id = ship_counter;
    for (int i = start_y; i != stop_y + add_y; i = i + add_y) {
        for (int j = start_x; j != stop_x + add_x; j = j + add_x) {
            
            ships[ship_counter].coords[cell_counter][0] = i;
            ships[ship_counter].coords[cell_counter][1] = j;
            cell_counter++;
        }
    }
    ships[ship_counter].health = cell_counter;
}

void generate_ship(int area[12][12], int deck_count) {
    int i, n;
    time_t t;

    srand((unsigned)time(&t));
    int start_x;
    int start_y;
    int counter = 0;

    while (1) {
        counter++;
        while (1) {
            start_x = rand() % 9 + 1;
            start_y = rand() % 9 + 1;
            if (area[start_y][start_x] == 0)
                break;
        }

        int direction = rand() % 3;

        int* adders_ptr;
        int* second_coords;
        adders_ptr = get_adders(direction);
        int arr[2];
        arr[0] = *(adders_ptr);
        arr[1] = *(adders_ptr + 1);
        second_coords = get_coords(start_x, start_y, deck_count, direction);
        int stop_x = *(second_coords);
        int stop_y = *(second_coords + 1);
        printf("stop_x: %d\n", stop_x);
        printf("stop_y: %d\n", stop_y);
        if (1 <= stop_x && stop_x <= 10 && 1 <= stop_y && stop_y <= 10)
            if (check_cells(area, start_x, start_y, stop_x, stop_y, arr, 0) == 0) {
                check_cells(area, start_x, start_y, stop_x, stop_y, arr, 1);
                create_ship(start_x, start_y, stop_x, stop_y, arr, ship_counter);
                ship_counter = ship_counter + 1;
                break;
            }
        if (counter > 10)
            break;
    }
    //printf("%d \n", start_x);
    //printf("%d \n", start_y);
    //print_area_0(area);
}