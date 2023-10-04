#include <stdio.h>

int main(void)
{
    int n;
    scanf("%i", &n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1, k = 0; j <= 2*n; j++)
        {
            if(j <= i)
            {
                printf("*");
                k++;
            }
            else if(j <= 2*n - k)
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }
    printf("\n");
    }

}
