#include <stdio.h>
int main(void)
{
    int a = 1, b = 1, n;
    scanf("%d", &n);
    printf("1 1");
    for(int i = 0; i < n - 2; i++)
    {
        a += b;
        b = a - b;
        a -= b;
        b += a;
        printf(" %i",b);
    }
}