/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game_board.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:51:51 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/22 22:51:51 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

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

    return (firstLine);
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

void ft_init_game_board(GameBoard *board, char *filename)
{
    char *firstline = getFirstLine(filename);
    set_board_info(board, firstline);
    readFileAndSetGrid(board, filename);
}