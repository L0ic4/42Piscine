/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:53:08 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/05 23:53:08 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
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
		if (c > 32 && (c < 65 || c > 90))
		{
			response = 0;
		}
		i++;
	}
	return (response);
}
