/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:16:42 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/11 16:16:42 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
    if (min >= max)
    {
        *range = NULL;
        return 0;
    }
    int size = max - min;

    *range = (int *)malloc(size);
    if (*range == NULL)
    {
        return -1; // Allocation échouée
    }
    int i;
    i = 0;
    while (i < size)
    {
        (*range)[i] = min + i;
        i++;
    }
    return size;
}

#include <stdio.h>

int main()
{
    int *arr;
    int size = ft_ultimate_range(&arr, 5, 10);

    if (size == -1)
    {
        printf("Échec d'allocation mémoire\n");
        return 1;
    }
    else if (size == 0)
    {
        printf("min est supérieur ou égal à max\n");
        return 0;
    }
    else
    {
        printf("Tableau alloué avec succès : ");
        for (int i = 0; i < size; ++i)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // N'oubliez pas de libérer la mémoire une fois que vous avez terminé avec le tableau
        free(arr);
    }

    return 0;
}
