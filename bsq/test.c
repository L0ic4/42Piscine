#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct
{
    int rows;
    char empty;
    char obstacle;
    char full;
    char grid[MAX_SIZE][MAX_SIZE];
} GameBoard;

// Fonction pour initialiser le plateau de jeu à partir d'un fichier
void initializeGameBoard(GameBoard *board, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    // Lecture des informations de la première ligne
    fscanf(file, "%d %c %c %c", &board->rows, &board->empty, &board->obstacle, &board->full);

    // Lecture du plateau de jeu
    for (int i = 0; i < board->rows; i++)
    {
        fscanf(file, "%s", board->grid[i]);
    }

    fclose(file);
}

// Fonction pour afficher le plateau de jeu
void printGameBoard(const GameBoard *board)
{
    // printf("Nombre de lignes : %d\n", board->rows);
    // printf("Caractère vide : %c\n", board->empty);
    // printf("Caractère obstacle : %c\n", board->obstacle);
    // printf("Caractère plein : %c\n", board->full);

    printf("Plateau de jeu :\n");
     for (int i = 0; i < board->rows; i++) {
        for (int j = 0; j < board->rows; j++) {
            printf("%c ", board->grid[i][j]);
        }
        printf("\n");
    }
}

void findLargestSquare(GameBoard *board)
{
    int **dp = (int **)malloc(board->rows * sizeof(int *));
    for (int i = 0; i < board->rows; i++)
    {
        dp[i] = (int *)malloc(board->rows * sizeof(int));
    }

    int maxSize = 0;
    int maxI = 0;
    int maxJ = 0;

    for (int i = 0; i < board->rows; i++)
    {
        for (int j = 0; j < board->rows; j++)
        {
            if (board->grid[i][j] == board->obstacle)
            {
                dp[i][j] = 0; // Obstacle, donc la taille maximale est 0.
            }
            else if (i == 0 || j == 0)
            {
                dp[i][j] = 1; // Première ligne ou première colonne.
            }
            else
            {
                dp[i][j] = 1 + fmin(dp[i - 1][j], fmin(dp[i][j - 1], dp[i - 1][j - 1]));
            }

            if (dp[i][j] > maxSize)
            {
                maxSize = dp[i][j];
                maxI = i;
                maxJ = j;
            }
        }
    }

    // Mettez à jour la matrice d'origine en remplaçant les '.' par 'X' dans la sous-matrice maximale.
    for (int i = maxI; i > maxI - maxSize; i--)
    {
        for (int j = maxJ; j > maxJ - maxSize; j--)
        {
            board->grid[i][j] = board->full;
        }
    }

    // Libérez la mémoire allouée pour dp.
    for (int i = 0; i < board->rows; i++)
    {
        free(dp[i]);
    }
    free(dp);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <nom_fichier>\n", argv[0]);
        return EXIT_FAILURE;
    }

    GameBoard board;
    initializeGameBoard(&board, argv[1]);

    printf("Original Matrix:\n");
    printGameBoard(&board);

    findLargestSquare(&board);
    printf("Largest Square:\n");
    printGameBoard(&board);

    return EXIT_SUCCESS;
}
