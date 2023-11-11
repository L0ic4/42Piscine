/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:54:22 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/11 12:54:22 by lny-tina         ###   ########.fr       */
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

int	main(void)
{
	int	test1 = 1;
	int	test2 = 25;
	int	test3 = 7;
	printf("%d est premier : %s\n", test1, ft_is_prime(test1) ? "Oui" : "Non");
	printf("%d est premier : %s\n", test2, ft_is_prime(test2) ? "Oui" : "Non");
	printf("%d est premier : %s\n", test3, ft_is_prime(test3) ? "Oui" : "Non");
	return (0);
}
