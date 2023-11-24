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

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	value;

	i = 0;
	value = 0;
	sign = 1;
	while (is_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (is_integer(str[i]))
	{
		value = value * 10 + str[i] - '0';
		i++;
	}
	return (value * sign);
}
