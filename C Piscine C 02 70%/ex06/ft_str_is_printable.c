/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 00:04:46 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/06 00:04:46 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;
	char	
		c;
	int	response;

	response = 1;
	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c < 32 || c == 127)
		{
			response = 0;
		}
		i++;
	}
	return (response);
}
