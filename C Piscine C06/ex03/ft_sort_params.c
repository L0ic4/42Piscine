/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:50:27 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/11 13:50:27 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	compare_strings(char *a, char *b)
{
	while (*a != '\0' && *b != '\0')
	{
		if (*a > *b)
			return (1);
		else if (*a < *b)
			return (0);
		a++;
		b++;
	}
	return (*a != '\0');
}

void	bubble_sort(char *arr[], int n)
{
	int	swapped;
	int	i;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < n - 1)
		{
			if (compare_strings(arr[i], arr[i + 1]))
			{
				swap(&arr[i], &arr[i + 1]);
				swapped = 1;
			}
			i++;
		}
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc > 1)
	{
		bubble_sort(argv + 1, argc - 1);
		i = 1;
		while (i < argc)
		{
			printf("%s\n", argv[i]);
			i++;
		}
	}
	return (0);
}
