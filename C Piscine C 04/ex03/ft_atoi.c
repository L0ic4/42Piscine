/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:53:36 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/11 10:53:36 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_integer(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_positif(char *str)
{
	int	i;
	int	minus;

	minus = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
		{
			minus++;
		}
		i++;
	}
	return (minus % 2 == 0);
}

int	to_int(char *str)
{
	int	i;
	int	result;

	result = 0;
	i = 0;
	while (str[i] != '\0' && !is_integer(str[i]))
	{
		i++;
	}
	while (str[i] != '\0' && is_integer(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int	ft_atoi(char *str)
{
	int	response;

	response = to_int(str);
	if (!is_positif(str))
	{
		response *= (-1);
	}
	return (response);
}
