/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_game_board.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:47:10 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/22 22:47:10 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void ft_print_game_board(GameBoard *board)
{
    int i = 0;
    char newline = '\n';

    printf("Nombre de lignes : %d\n", board->rows);
    printf("Caractere vide : %c\n", board->empty);
    printf("Caractere obstacle : %c\n", board->obstacle);
    printf("Caractere plein : %c\n", board->full);

    while (i < board->rows)
    {
        int j = 0;
        while (j < board->rows)
        {
            write(1, &board->grid[i][j], 1);
            j++;
        }
        write(1, &newline, 1);
        i++;
    }
}