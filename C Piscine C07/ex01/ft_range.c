/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:04:57 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/11 16:04:57 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*response;
	int	i;

	size = max - min;
	response = malloc(size);
	i = 0;
	while (i < size)
	{
		response[i] = min + i;
		i++;
	}
	response[size] = '\0';
	return (response);
}

int	main(void)
{
	int	min = 5;
	int	max = 15;
	int *result	= ft_range(min, max);
	printf("Result: ");
	for (int i = 0; result[i] != '\0'; ++i)
	{
		printf("%d ", result[i]);
	}
	printf("\n");
	return (0);
}
