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

	if (size == 0)
		return (1);
	total_length = 0;
	i = 0;
	while (i < size)
	{
		total_length += ft_strlen(strs[i]);
		i++;
	}
	total_length += ft_strlen(sep) * (size - 1);
	return (total_length + 1);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	destlen;

	i = 0;
	destlen = ft_strlen(dest);
	while (src[i])
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = 0;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;

	result = malloc(ft_total_len(size, strs, sep) * sizeof(char));
	if (!result)
		return (NULL);
	result[0] = 0;
	if (size == 0)
		return (result);
	i = 0;
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i != size - 1)
			ft_strcat(result, sep);
		i++;
	}
	result[ft_strlen(result)] = 0;
	return (result);
}

// int main(void)
// {
// 	int	size = 3;
// 	char	*strs[size];
// 	strs[0] = "test1";
// 	strs[1] = "test2";
// 	strs[2] = "test3";
// 	char	*sep = "*";
// 	printf("%s\n", ft_strjoin(size,strs,sep));
// 	return (0);
// }
