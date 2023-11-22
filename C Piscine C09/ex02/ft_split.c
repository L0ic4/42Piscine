/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 08:27:17 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/21 10:08:06 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*dest;

	if (!src)
		return (NULL);
	i = 0;
	if (!(dest = (char *)malloc((n + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	if (c == '\0')
		return (1);
	while (charset[i])
	{
		if (c == (charset[i]))
			return (1);
		i++;
	}
	return (0);
}

int		count_words(char *str, char *charset)
{
	int	i;
	int	nb_word;

	nb_word = 0;
	if (!is_sep(str[0], charset))
		nb_word++;
	i = 1;
	while (str[i])
	{
		if (!is_sep(str[i], charset) && is_sep(str[i - 1], charset))
			nb_word++;
		i++;
	}
	return (nb_word);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	tab = (char **)malloc((count_words(str, charset) + 1) * sizeof(char *));
	k = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (!is_sep(str[i + j], charset))
			j++;
		if (j)
		{
			tab[k] = ft_strndup(&str[i], j);
			k++;
			i = i + j;
		}
		i++;
	}
	tab[k] = 0;
	return (tab);
}


