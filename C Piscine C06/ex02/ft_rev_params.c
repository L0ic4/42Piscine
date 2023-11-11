/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:45:59 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/11 13:45:59 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;

	if (argc < 2)
		return (1);
	i = argc -1;
	while (i > 0)
	{
		write(1, argv[i], strlen(argv[i]));
		write(1, "\n", 1);
		i--;
	}
	return (0);
}
