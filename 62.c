#include <stdio.h>

int main(void)
{
    int array[100], n, insert, shift;
    scanf("%i", &n);
    for(int i = 1; i <= n; i++)
        scanf("%i", &array[i]);
    scanf("%i", &insert);
    for(int i = n + 1; insert < i; i--)
    {
        shift = array[i - 1];
        array[i] = shift;
    }
    scanf("%i", &array[insert]);
    for(int i = 1; i <= n + 1; i++)
        printf("%i ", array[i]);
}