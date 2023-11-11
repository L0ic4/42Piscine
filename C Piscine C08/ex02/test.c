#include <stdio.h>
#include "ft_abs.h"

int main()
{
    int num1 = -5;
    int num2 = -10;

    printf("Original values: num1 = %d, num2 = %d\n", num1, num2);

    // Using the ABS macro
    ABS(num1);
    ABS(num2);

    printf("Absolute values: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}
