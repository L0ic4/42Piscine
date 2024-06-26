/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:43:54 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/07 10:43:54 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	
		temp_tab[size];
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		temp_tab[i] = tab[size - i - 1];
		i++;
	}
	j = 0;
	while (j < size)
	{
		tab[j] = temp_tab[j];
		j++;
	}
}
