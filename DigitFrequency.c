#include <stdio.h>

int main(void)
{
    int number;
    scanf("%i", &number);
    for(int i = 0; i < 10; i++)
    {
        int count = 0, product = number, digit;
        while(product)
        {
            digit = product % 10;
            product /= 10;
            if(digit == i)
            {
                count++;
            }
        }
        if(count != 0)
        {
            printf("%i is present %i times\n", i, count);
        }
    }
}