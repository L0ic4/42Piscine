#define MAX_SIZE 1024
#define BUFFER_SIZE 1024

typedef struct
{
    int rows;
    char empty;
    char obstacle;
    char full;
    char grid[MAX_SIZE][MAX_SIZE];
} GameBoard;