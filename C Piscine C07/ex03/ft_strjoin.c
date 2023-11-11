/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:33:22 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/11 16:33:22 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>

// char *ft_strjoin(int size, char **strs, char *sep)
// {
//     int i;
//     char *response = malloc(size * 2);

//     i = 0;
//     while ((*strs)[i] != '\0')
//     {
//         response[i] = (*strs)[i] + sep[i];
//         i++;
//     }
//     return response;
// }

#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *src)
{
    int i;

    i = 0;
    while (src[i] != '\0')
    {
        i++;
    }
    return (i);
}

char *ft_strjoin(int size, char **strs, char *sep)
{
    int total_length = 0;
    int i;

    i = 0;
    // Calculate the total length of the joined string
    while (i < size)
    {
        total_length += ft_strlen(strs[i]);
        i++;
    }

    total_length += ft_strlen(sep) * (size - 1); // Add the length of separators

    // Allocate memory for the result string
    char *result = malloc(total_length + 1); // +1 for the null-terminator

    if (result == NULL)
    {
        return 0;
    }

    int result_index = 0;

    // Copy each string from strs array to the result
    i = 0;
    while (i < size)
    {
        int j = 0;
        while (strs[i][j] != '\0')
        {
            result[result_index++] = strs[i][j++];
        }

        // Append separator if it's not the last string
        if (i < size - 1)
        {
            int sep_index = 0;

            while (result[result_index++] = sep[sep_index++]);
            --result_index;
        }
        i++;
    }

    // Null-terminate the result string
    result[result_index] = '\0';

    return result;
}

int main()
{
    char *arr[] = {"Hello", "world", "!"};
    char *separator = "*";

    char *result = ft_strjoin(3, arr, separator);

    if (result != NULL)
    {
        printf("%s\n", result);
        free(result); // Don't forget to free the allocated memory
    }

    return 0;
}
