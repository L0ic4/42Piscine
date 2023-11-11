/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:05:51 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/11 12:05:51 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	while (power > 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}

int	main(void)
{
	int	base;
	int	exponent;

	base = 2;
	exponent = 3;
	printf("%d^%d = %d\n", base, exponent, ft_iterative_power(base, exponent));
	base = 5;
	exponent = 0;
	printf("%d^%d = %d\n", base, exponent, ft_iterative_power(base, exponent));
	return (0);
}
