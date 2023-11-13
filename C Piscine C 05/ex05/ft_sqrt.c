/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:34:50 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/13 11:26:04 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	unsigned int		index;

	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (nb);
	index = 0;
	while ((index * index) < (unsigned int)nb)
	{
		index++;
	}
	if (index * index == (unsigned int)nb)
	{
		return (index);
	}
	else
		return (0);
}

int	main(void)
{
	printf("%d\n", ft_sqrt(25));
	return (0);
}
