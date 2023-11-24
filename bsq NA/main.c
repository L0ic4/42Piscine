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
        ft_init_game_board(&board, argv[i]);
        ft_find_largest_square(&board);
        ft_print_game_board(&board);
        i++;
        if (i != argc)
            write(1, "\n", 1);
    }
    return 0;
}
