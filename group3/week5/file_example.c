#include <stdio.h>

typedef struct
{
    short row;
    short column;
} POSITION;

void print_position(POSITION p);

int main()
{
    POSITION empty_position = { .row = 3, .column = 3 };
    POSITION positions[15];
    
    for (int i = 1; i < 16; i++)
    {
        positions[i - 1].row = (i - 1) / 4; 
        positions[i - 1].column = (i - 1) % 4;
    }
    
    char* filename = "fifteen_backup";
    
    // create or open file to save data 'w+'
    FILE* file = fopen(filename, "w+");
    // save binary data to file
    //  - array of positions
    fwrite(positions, sizeof(POSITION), 15, file);
    //  - empty element position
    fwrite(&empty_position, sizeof(POSITION), 1, file);
    // close file
    fclose(file);
    
    // open file again to read
    file = fopen(filename, "r");
    // read 15 elements POSITION to array
    POSITION positions_copy[15];
    fread(positions_copy, sizeof(POSITION), 15, file);
    // read empty element
    POSITION empty_copy;
    fread(&empty_copy, sizeof(POSITION), 1, file);
    // close file
    fclose(file);
    
    // print POSITIONs array on screen
    printf("array before:\n");
    for (int i = 0; i < 15; i++)
    {
        print_position(positions[i]);
    }
    printf("array after:\n");
    for (int i = 0; i < 15; i++)
    {
        print_position(positions_copy[i]);
    }
    
    printf("\nempty before:\n");
    print_position(empty_position);
    printf("empty after:\n");
    print_position(empty_copy);
}

void print_position(POSITION p)
{
    printf("row: %i;\tcolumn: %i\n", p.row, p.column);
}