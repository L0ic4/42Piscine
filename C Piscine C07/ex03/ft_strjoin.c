/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:33:22 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/16 14:16:42 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <stdio.h>

int	ft_strlen(char *strs)
{
	int	count;

	count = 0;
	while (*strs++ != '\0')
		count++;
	return (count);
}

int	ft_total_len(int size, char **strs, char *sep)
{
	int	i;
	int	total_length;

	total_length = 0;
	i = 0;
	while (i < size)
	{
		total_length += ft_strlen(strs[i]);
		i++;
	}
	total_length += ft_strlen(sep) * (size - 1);
	return (total_length);
}

void	ft_concat_sep(int *result_index, char *response,
	char *strs_sep, int is_strs)
{
	int	i;

	i = 0;
	if (is_strs == 1)
	{
		while (strs_sep[i] != '\0')
		{
			response[*result_index] = strs_sep[i];
			*result_index = *result_index + 1;
			i++;
		}
	}
	else
	{
		while (strs_sep[i] != '\0')
		{
			response[*result_index] = strs_sep[i];
			*result_index = *result_index + 1;
			i++;
		}
	}
}

char	*ft_concat(int size, char **strs, char *sep)
{
	int	result_index;
	int	i;
	char
		*response;

	response = malloc(ft_total_len(size, stirs, sep) + 1 
		* sizeof(int) + sizeof('\0'));
	i = 0;
	result_index = 0;
	while (i < size)
	{
		ft_concat_sep(&result_index, response, strs[i], 1);
		if (i < (size - 1))
		{
			ft_concat_sep(&result_index, response, sep, 0);
		}
		i++;
	}
	response[result_index] = '\0';
	return (response);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char
		*response;

	if (size == 0)
		return (0);
	response = ft_concat(size, strs, sep);
	return (response);
}

// int main(void)
// {
// 	char	*strs[1];
// 	strs[0] = "test1";
// 	// strs[1] = "test2";
// 	// strs[2] = "test3";
// 	char	*sep = "*";
// 	int	size = 1;
// 	printf("%s\n", ft_strjoin(size,strs,sep));
// 	return (0);
// }
