/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:04:57 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/11 16:04:57 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int *ft_range(int min, int max)
{
    int size = max - min;
    int *response = malloc(size);
    int i;

    i = 0;
    while (i < size)
    {
        response[i] = min + i;
        i++;
    }
    response[size] = '\0';
    return response;
}

int main()
{
    int min = 5;  // Set your desired minimum value
    int max = 15; // Set your desired maximum value

    // Call the ft_range function
    int *result = ft_range(min, max);

    // Check if the result is NULL (indicating an error)
    if (result == NULL)
    {
        printf("Error: Unable to allocate memory or invalid range.\n");
        return 1; // Exit with an error code
    }

    // Print the elements in the array
    printf("Result: ");
    for (int i = 0; result[i] != '\0'; ++i)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(result);

    return 0; // Exit successfully
}