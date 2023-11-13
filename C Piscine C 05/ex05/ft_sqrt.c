/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:34:50 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/13 09:34:44 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	unsigned int		sqrt;
	unsigned int		index;

	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (nb);
	index = 0;
	while (sqrt < (unsigned int)nb)
	{
		sqrt = index * index;
		index++;
	}
	if (index * index == (unsigned int)nb)
	{
		return (index);
	}
	else
		return (0);
}
