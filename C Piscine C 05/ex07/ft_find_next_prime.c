/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:03:36 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/13 11:35:25 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prime_recursive(int nb, int i)
{
	if (nb <= 1)
		return (0);
	if (i > nb / 2)
		return (1);
	if (nb % i == 0)
		return (0);
	return (is_prime_recursive(nb, i + 1));
}

int	ft_is_prime(int nb)
{
	return (is_prime_recursive(nb, 2));
}

int	find_next_prime_recursive(int nb)
{
	if (ft_is_prime(nb))
		return (nb);
	return (find_next_prime_recursive(nb + 1));
}

int	ft_find_next_prime(int nb)
{
	return (find_next_prime_recursive(nb));
}
