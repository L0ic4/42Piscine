/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:51:06 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/09 11:57:55 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0') && i < n)
	{
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	else
		return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	len;

	len = ft_strlen(to_find);
	i = 0;
	while (str[i + (len - 1)] != '\0')
	{
		if (ft_strncmp(&str[i], to_find, len) == 0)
		{
			return (&str[i]);
		}
		i++;
	}
	return (0);
}
