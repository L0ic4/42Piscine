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

#include <stdlib.h>

int	ft_strlen(char *strs)
{
	int	count;

	count = 0;
	while (*strs++ != '\0')
		count++;
	return (count);
}

char **ft_split(char *str, char *charset)
{
	char **response;

	response = malloc(sizeof(char *) )	
}
