/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:27:58 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/12 10:17:17 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*dst;

	dst = dest;
	while (*dst != '\0')
		dst++;
	while (*src != '\0' && nb > 0)
	{
		*dst = *(unsigned char *)src;
		dst++;
		src++;
		nb--;
	}
	*dst = '\0';
	return (dest);
}
