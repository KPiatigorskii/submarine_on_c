enum field_status { with_ship = 2, empty = 0, near_of_ship = 1 };
enum field_state { close = 0, open = 1 };



struct Play_area
{
    int fields_arr[10][10];
};

void open_field() {};

void close_all_fields() {};

//void init_all_fields(struct Play_area *area) {
//    for (int i = 0; i < 12; i++)
//    {
//        for (int j = 0; j < 12; j++) 
//        {
//            area->fields_arr[i][j] = 0;
//        }
//    }
//};

void set_field_status() {};

void print_area() {};
