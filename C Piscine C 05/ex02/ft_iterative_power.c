/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lny-tina <lny-tina@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:05:51 by lny-tina          #+#    #+#             */
/*   Updated: 2023/11/11 12:05:51 by lny-tina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_iterative_power(int nb, int power)
{
    int result;
    int i;

    result = 1;
    while (power > 0)
    {
        result *= nb;
        power--;
    }
    return (result);
}

int main()
{
    // Test cases
    int base, exponent;

    // Test case 1: base = 2, exponent = 3
    base = 2;
    exponent = 3;
    printf("%d^%d = %d\n", base, exponent, ft_iterative_power(base, exponent));

    // Test case 2: base = 5, exponent = 0
    base = 5;
    exponent = 0;
    printf("%d^%d = %d\n", base, exponent, ft_iterative_power(base, exponent));

    // Test case 3: base = 4, exponent = 2
    base = 4;
    exponent = 2;
    printf("%d^%d = %d\n", base, exponent, ft_iterative_power(base, exponent));

    // Add more test cases as needed

    return 0;
}