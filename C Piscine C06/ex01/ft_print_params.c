/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:42:45 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/11 13:42:45 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char *argv[])
{
    // Vérifier s'il y a au moins un argument (le nom du programme lui-même)
    if (argc < 2)
    {
        return 1;
    }

    // Utiliser une boucle while pour afficher les arguments un par un, à partir du deuxième (argv[1])
    int i = 1;
    while (i < argc)
    {
        write(1, argv[i], strlen(argv[i]));
        write(1, "\n", 1);
        i++;
    }

    return 0;
}
