/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:03:58 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/11 18:03:58 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ft_putchar.c
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
