/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:29:24 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/11 13:29:24 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char const *argv[])
{
	int	i;

	argc = 0;
	i = 0;
	while (argv[argc][i])
		i++;
	write(1, argv[argc], i);
	write(1, "\n", 1);
	return (0);
}
