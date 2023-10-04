#include <stdio.h>
int main(void)
{
    int n;
    scanf("%i", &n);
    int array[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = i - 1; j >= 0; j--)
        {
            if(array[j] == array[i])
            {
                array[i] = '\0';
                break;
            }
        }    
    }

    for(int i = 0; i < n; i++)
    {
        if(array[i] == '\0')
        {
            for(int j = i + 1; j < n; j++)
            {
                if(array[j] != '\0')
                {
                    array[i] = array[j];
                    array[j] = '\0';
                    break;
                }
            }
        }
        
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }

}