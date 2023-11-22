/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:39:34 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/22 17:39:34 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "utils.c"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

void printGameBoard(GameBoard *board)
{
    int i = 0;
    char newline = '\n';

    printf("Nombre de lignes : %d\n", board->rows);
    printf("Caractère vide : %c\n", board->empty);
    printf("Caractère obstacle : %c\n", board->obstacle);
    printf("Caractère plein : %c\n", board->full);

    while (i < board->rows)
    {
        int j = 0;
        while (j < board->rows)
        {
            write(STDOUT_FILENO, &board->grid[i][j], 1);
            j++;
        }
        write(STDOUT_FILENO, &newline, 1);
        i++;
    }
}

void readFileAndSetGrid(GameBoard *gameBoard, char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    int row = 0;
    int currentLine = 0; // Variable to keep track of the current line
    char buffer[MAX_SIZE];

    while (fgets(buffer, MAX_SIZE, file) != NULL)
    {
        // Skip the first line
        if (currentLine > 0)
        {
            for (int col = 0; col < gameBoard->rows; col++)
            {
                gameBoard->grid[row][col] = buffer[col];
            }
            row++;
        }

        currentLine++;
    }

    fclose(file);
}

char *getFirstLine(char *filename)
{
    int fileDescriptor;
    char buffer[BUFFER_SIZE];
    char *firstLine = NULL;

    // Open the file
    fileDescriptor = open(filename, O_RDONLY);
    if (fileDescriptor == -1)
    {
        perror("Error opening the file");
        return NULL;
    }

    // Read the contents of the file into a buffer
    ssize_t bytesRead = read(fileDescriptor, buffer, BUFFER_SIZE - 1);
    if (bytesRead == -1)
    {
        perror("Error reading the file");
        close(fileDescriptor);
        return NULL;
    }
    buffer[bytesRead] = '\0'; // Null-terminate the buffer

    // Find the end of the first line
    char *endOfLine = strchr(buffer, '\n');
    if (endOfLine != NULL)
    {
        *endOfLine = '\0'; // Null-terminate the first line
    }

    // Allocate memory for the first line
    firstLine = malloc(strlen(buffer) + 1);
    if (firstLine == NULL)
    {
        perror("Error allocating memory");
        close(fileDescriptor);
        return NULL;
    }

    // Copy the first line to the allocated memory
    strcpy(firstLine, buffer);

    // Close the file
    if (close(fileDescriptor) == -1)
    {
        perror("Error closing the file");
        return NULL;
    }

    return firstLine;
}

void set_board_info(GameBoard *gameBoard, char *first_line)
{
    int l;
    int i;
    char *rows;

    l = ft_strlen(first_line);

    rows = malloc(sizeof(char) * (l - 3));

    i = l - 4;
    while (i >= 0)
    {
        rows[i] = first_line[i];
        i--;
    }

    gameBoard->full = first_line[l - 1];
    gameBoard->obstacle = first_line[l - 2];
    gameBoard->empty = first_line[l - 3];
    gameBoard->rows = ft_atoi(rows);

    free(rows);
}

void initializeGameBoard(GameBoard *board, char *filename)
{
    char *firstline = getFirstLine(filename);
    set_board_info(board, firstline);
    readFileAndSetGrid(board, filename);
}

void findLargestSquare(GameBoard *board)
{
    int **dp = (int **)malloc(board->rows * sizeof(int *));
    int d = 0;
    while (d < board->rows)
    {
        dp[d] = (int *)malloc(board->rows * sizeof(int));
        d++;
    }

    int maxSize = 0;
    int maxI = 0;
    int maxJ = 0;

    int i = 0;
    int j = 0;

    while (i < board->rows)
    {
        while (j < board->rows)
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
                dp[i][j] = 1 + ft_min(dp[i - 1][j], ft_min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
            if (dp[i][j] > maxSize)
            {
                maxSize = dp[i][j];
                maxI = i;
                maxJ = j;
            }
            j++;
        }
        j = 0;
        i++;
    }
    // Mettez à jour la matrice d'origine en remplaçant les '.' par 'X' dans la sous-matrice maximale.
    int a = maxI;
    while (a > maxI - maxSize)
    {
        int b = maxJ;
        while (b > maxJ - maxSize)
        {
            board->grid[a][b] = board->full;
            b--;
        }
        a--;
    }
    // Libérez la mémoire allouée pour dp.
    int c = 0;
    while (c < board->rows)
    {
        free(dp[c]);
        c++;
    }
    free(dp);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        return (0);
    }
    int i = 1;
    while (i < argc)
    {
        GameBoard board;
        initializeGameBoard(&board, argv[i]);
        findLargestSquare(&board);
        printGameBoard(&board);
        i++;
        if (i != argc)
            write(1, "\n", 1);
    }
    return 0;
}
