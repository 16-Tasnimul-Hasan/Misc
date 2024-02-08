#include <stdio.h>

int main(void)
{
    int m, n, p;
    scanf("%i%i%i", &m, &n, &p);
    int mat1[m][n], mat2[n][p], mat3[m][p];
    int (*ptr1)[n] = mat1, (*ptr2)[n] = mat2, (*ptr3)[n] = mat3;
    
    for(int i = 0 ; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%i", (*(ptr1+i)+j));
   
    for(int i = 0; i < n; i++)
        for(int j = 0; j < p; j++)
            scanf("%i", (*(ptr2+i)+j));

    for(int i = 0; i < m; i++)
        for(int j = 0; j < p; j++)
        {
            int I = 0, J = 0;
            *(*(ptr3+i)+j) = 0;
            for(int k = 0; k < n; k++)
            {
                *(*(ptr3+i)+j) += (*(*(ptr1+i)+J)) * (*(*(ptr2+I)+j));
                I++;
                J++;
            }
        }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < p; j++)
            printf("%i ", *(*(ptr3+i)+j));
        printf("\n");
    }
}