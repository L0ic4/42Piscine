/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:14:57 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/03 14:59:23 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	positif;
	char	negatif;

	positif = 'P';
	negatif = 'N';
	if (n < 0)
		write(1, &negatif, 1);
	else
		write(1, &positif, 1);
}
