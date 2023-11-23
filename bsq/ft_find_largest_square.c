/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_largest_square.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:48:22 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/23 13:48:43 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_find_largest_square(GameBoard *board)
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
