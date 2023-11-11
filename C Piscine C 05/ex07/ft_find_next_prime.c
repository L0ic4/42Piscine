/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:03:36 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/11 13:03:36 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	if (nb == 0 || nb == 1)
		return (0);
	i = 2;
	while (i < nb / 2)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb))
		return (nb);
	while (!ft_is_prime(nb))
	{
		nb++;
	}
	return (nb);
}

int	main(void)
{
	int	test_cases[] = {5, 10, 20, 25, 30};
	int	num_test_cases = sizeof(test_cases) / sizeof(test_cases[0]);
	
	for (int i = 0; i < num_test_cases; i++)
	{
		int result = ft_find_next_prime(test_cases[i]);
		printf("Next prime after %d: %d\n", test_cases[i], result);
	}
	return (0);
}
