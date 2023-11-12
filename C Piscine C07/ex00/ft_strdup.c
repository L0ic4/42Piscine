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

void	ft_strcpy(char *dst, char *src)
{
	while (*src != '\0')
		*dst++ = *src++;
	*dst = '\0';
}

int	ft_strlen(char *src)
{
	int	count;

	count = 0;
	while (*src++ != '\0')
		count++;
	return (count);
}

char	*ft_strdup(char *src)
{
	char	*dst;

	dst = malloc(ft_strlen(src) + 1);
	ft_strcpy(dst, src);
	return (dst);
}
