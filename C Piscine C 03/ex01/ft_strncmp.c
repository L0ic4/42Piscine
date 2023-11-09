/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:25:55 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/08 17:05:39 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;

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
