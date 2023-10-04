#include <stdio.h>

int main(void)
{
    int decimal, digit, binary, product, multiplier = 1;
    scanf("%d", &decimal);
    while(decimal > 0)
    {
        product = decimal / 2;
        digit = decimal % 2;
        decimal = product;
        binary += digit * multiplier;
        multiplier *= 10;
    }
    printf("%i", binary);
}