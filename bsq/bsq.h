/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:55:11 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/22 22:55:11 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H

#define BSQ_H

#define MAX_SIZE 1024
#define BUFFER_SIZE 1024

typedef struct
{
    int rows;
    char empty;
    char obstacle;
    char full;
    char grid[MAX_SIZE][MAX_SIZE];
} GameBoard;

void ft_find_largest_square(GameBoard *board);
void ft_init_game_board(GameBoard *board, char *filename);
void ft_print_game_board(GameBoard *board);

#endif