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

int ft_strlen (char *str)
{
	int count;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char **ft_split(char *str, char *charset)
{
  int i;
  int j;
  int k;
  int len;
  char **tab;

  i = 0;
  j = 0;
  k = 0;

  len = ft_strlen(str);
  /* Allocation du tableau */
  tab = (char **)malloc(sizeof(char *) * (len + 1));
  if (tab == NULL)
    return (NULL);
  /* Boucle de découpage */
  while (i < len)
  {
    while (str[i] && strchr(charset, str[i]) == NULL)
      i++;
    if (str[i])
    {
      len = i - j;
      tab[k] = (char *)malloc(sizeof(char) * (len + 1));
      if (tab[k] == NULL)
        return (NULL);
      ft_strncpy(tab[k], str + j, len);
      tab[k][len] = '\0';
      k++;
      j = i + 1;
    }
  }
  tab[k] = NULL;
  return (tab);
}
