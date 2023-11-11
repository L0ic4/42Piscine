/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:50:27 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/11 13:50:27 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// Fonction pour échanger deux chaînes de caractères
void swap(char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}

// Fonction de comparaison de deux chaînes de caractères
// Retourne 1 si la première chaîne est "plus grande" que la deuxième, 0 sinon
int compareStrings(char *a, char *b)
{
    while (*a != '\0' && *b != '\0')
    {
        if (*a > *b)
        {
            return 1;
        }
        else if (*a < *b)
        {
            return 0;
        }
        a++;
        b++;
    }

    // Si les chaînes sont égales jusqu'à la fin de la plus courte
    // la chaîne la plus courte est "plus petite"
    return (*a != '\0');
}

// Fonction de tri à bulles avec une boucle while
void bubbleSort(char *arr[], int n)
{
    int swapped = 1; // Indique si un échange a été effectué
    while (swapped)
    {
        swapped = 0;
        int i = 0;
        while (i < n - 1)
        {
            if (compareStrings(arr[i], arr[i + 1]))
            {
                swap(&arr[i], &arr[i + 1]);
                swapped = 1;
            }
            i++;
        }
    }
}

int main(int argc, char *argv[])
{
    // Vérifie si au moins un argument est passé en ligne de commande
    if (argc > 1)
    {
        // Trie le tableau d'arguments par ordre ASCII en utilisant le tri à bulles avec une boucle while
        bubbleSort(argv + 1, argc - 1);

        // Affiche les arguments triés
        int i = 1;
        while (i < argc)
        {
            printf("%s\n", argv[i]);
            i++;
        }
    }
    else
    {
        // Aucun argument n'a été passé
        printf("Aucun argument fourni.\n");
    }

    return 0;
}
