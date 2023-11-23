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