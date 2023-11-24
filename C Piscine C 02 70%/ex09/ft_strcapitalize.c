/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:57:29 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/08 16:32:48 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alpha(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_word_separator(char c)
{
	return (!is_alpha(c) && !is_digit(c));
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] -= 'A' - 'a';
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;
	char
		*response;

	response = ft_strlowcase(str);
	new_word = 1;
	i = 0;
	while (response[i] != '\0')
	{
		if (new_word && is_alpha(response[i]))
		{
			if ((i == 0 || is_word_separator(response[i - 1])))
			{
				response[i] -= 'a' - 'A';
			}
			new_word = 0;
		}
		else if (is_word_separator(response[i]))
			new_word = 1;
		i++;
	}
	return (response);
}
