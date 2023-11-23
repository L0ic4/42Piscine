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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
char** getAllLinesExceptFirst(char *filename, size_t *numLines) {
    int fileDescriptor = open(filename, O_RDONLY);
    if (fileDescriptor == -1) {
        perror("Error opening the file");
        return NULL;
    }
    // Count the number of lines in the file
    *numLines = 0;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;
    while ((bytesRead = read(fileDescriptor, buffer, sizeof(buffer))) > 0) {
        for (ssize_t i = 0; i < bytesRead; i++) {
            if (buffer[i] == '\n') {
                (*numLines)++;
            }
        }
    }
    lseek(fileDescriptor, 0, SEEK_SET); // Reset file pointer to the beginning
    // Allocate memory for the 2D array
    char **lines = malloc((*numLines) * sizeof(char*));
    if (lines == NULL) {
        perror("Error allocating memory");
        close(fileDescriptor);
        return NULL;
    }
    // Read and store lines in the array
    size_t lineIndex = 0;
    ssize_t bytesRead2;
    while ((bytesRead2 = read(fileDescriptor, buffer, sizeof(buffer))) > 0) {
        for (ssize_t i = 0; i < bytesRead2; i++) {
            if (buffer[i] == '\n') {
                buffer[i] = '\0'; // Null-terminate the line
                lines[lineIndex] = strdup(buffer);
                if (lines[lineIndex] == NULL) {
                    perror("Error allocating memory");
                    close(fileDescriptor);
                    for (size_t j = 0; j < lineIndex; j++) {
                        free(lines[j]);
                    }
                    free(lines);
                    return NULL;
                }
                lineIndex++;
            }
        }
    }
    close(fileDescriptor);
    return lines;
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
    firstLine = malloc(ft_strlen(buffer) + 1);
    if (firstLine == NULL)
    {
        perror("Error allocating memory");
        close(fileDescriptor);
        return NULL;
    }

    // Copy the first line to the allocated memory
    ft_strcpy(firstLine, buffer);

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

void set_board_grid(GameBoard *board,char **arr)
{
    int i;
    int j;

    i = 0;
    while(array[i] != '\0')
    {
        while
    }
}

void ft_init_game_board(GameBoard *board, char *filename)
{
    char *firstline = getFirstLine(filename);
    set_board_info(board, firstline);
    readFileAndSetGrid(board, filename);
}