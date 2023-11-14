/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:33:22 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/13 14:21:44 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int	total_length;
	int	i;
	int	j;
	int	result_index;
	char
		*result;

	total_length = 0;
	i = 0;
	while (i < size)
	{
		total_length += ft_strlen(strs[i]);
		i++;
	}
	total_length += ft_strlen(sep) * (size - 1);
	result = malloc(total_length + 1);
	if (result == NULL)
		return (0);
	result_index = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			result[result_index++] = strs[i][j++];
		if (i < size - 1)
		{
			int sep_index = 0;
			while ((result[result_index++] = sep[sep_index++]));
			--result_index;
		}
		i++;
	}
	result[result_index] = '\0';
	return (result);
}
