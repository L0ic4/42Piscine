/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:52:58 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/08 15:45:04 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;
	char	
		c;
	int	response;

	i = 0;
	response = 1;
	while (str[i] != '\0')
	{
		c = str[i];
		if (!(c >= '0' && c <= '9'))
		{
			response = 0;
		}
		i++;
	}
	return (response);
}
