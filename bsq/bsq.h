#define MAX_SIZE 100

typedef struct
{
    int rows;
    char empty;
    char obstacle;
    char full;
    char grid[MAX_SIZE][MAX_SIZE];
} GameBoard;