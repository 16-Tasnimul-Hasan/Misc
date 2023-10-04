#include <stdio.h>

int main(void)
{
    int a, b, GCD;
    scanf("%i%i", &a, &b);
    if (a < b)
    {
        for(int i = 1; i <= a; i++)
        {
            if(a % i == 0 && b % i == 0)
            {
                GCD = i;
            }
        }
    }
    else
    {
        for(int i = 1; i <= b; i++)
        {
            if(a % i == 0 && b % i == 0)
            {
                GCD = i;
            }
        }        
    }
    printf("GCD is %i\n", GCD);
}