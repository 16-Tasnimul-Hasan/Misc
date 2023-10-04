#include <stdio.h>
int main(void)
{
    int n, m;
    scanf("%i%i", &n, &m);
    for(; n <= m; n++)
    {
        if(n == 2)
        {
            printf("%i is prime.\n", n);
        }
        else
        {
            for(int i = 2, j = 0; i < n; i++)
            {
                if(n % i != 0)
                {
                    j++;
                }
                if(j == n - 2)
                {
                    printf("%i is prime.\n", n);
                }
            }
        }
    }
}