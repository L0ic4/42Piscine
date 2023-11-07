/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:57:29 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/06 22:57:29 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lowercase_letter(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	is_uppercase_letter(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_word_separator(char c)
{
	return (!is_lowercase_letter(c) && !is_uppercase_letter(c) && !is_digit(c));
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	new_word = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (new_word && is_lowercase_letter(str[i]))
		{
			if ((i == 0 || is_word_separator(str[i - 1])))
			{
				str[i] -= 'a' - 'A';
			}
			new_word = 0;
		}
		else if (is_word_separator(str[i]))
			new_word = 1;
		i++;
	}
	return (str);
}
