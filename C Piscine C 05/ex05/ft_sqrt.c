/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:34:50 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/11 12:34:50 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_sqrt(int nb)
{
    if (nb == 0)
    {
        return 0;
    }

    int i = 1;
    while (i <= nb / 2)
    {
        if (i * i == nb)
        {
            return i;
        }
        i++;
    }
    return 0;
}

int main()
{
    int nombre = 81;
    int resultat = ft_sqrt(nombre);

    if (resultat != 0)
    {
        printf("La racine carrée entière de %d est : %d\n", nombre, resultat);
    }
    else
    {
        printf("La racine carrée de %d n'est pas un nombre entier.\n", nombre);
    }

    return 0;
}