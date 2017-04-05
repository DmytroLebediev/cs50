#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    short row;
    short column;
} POSITION;

void print_position(POSITION p);

int main()
{
    POSITION* position_ptr = NULL;
    
    position_ptr = malloc(10 * sizeof(POSITION));
    position_ptr->row = 0;
    position_ptr->column = 0;
    
    (position_ptr + 2)->row
    
    (*position_ptr).row = 1;
    (*position_ptr).column = 1;
    position_ptr[0].row = 1;
    position_ptr[0].column = 1;
    
    POSITION position;
    position.row = 0;
    position.column = 0;
    
    print_position(*position_ptr);
    print_position(position);
}

void print_position(POSITION p)
{
    printf("row: %i;\tcolumn: %i\n", p.row, p.column);
}