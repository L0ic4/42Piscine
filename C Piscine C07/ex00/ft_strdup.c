/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:45:18 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/11 15:45:18 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_strcpy(char *dst, char *src)
{
	while (*src != '\0')
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = '\0';
}

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dst;

	dst = malloc(ft_strlen(src) + 1);
	ft_strcpy(dst, src);
	return (dst);
}

int	main(void)
{
	char	source[] = "GeeksForGeeks";
	char	*target = strdup(source);
	char	*test = ft_strdup(source);
	printf("%s\n", target);
	printf("%s\n", test);
	return (0);
}
