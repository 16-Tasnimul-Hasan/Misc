#include <stdio.h>

int main(void)
{
    char Conf;
    do 
    {
        int I, opcount, ai = 0, jay = 0, one = 0, others = 0;

        do
        {
            printf("enter odd order greater than 1: ");
            scanf("%i", &I);
        }
        while(I < 3 || I % 2 == 0);

        int elements[I*I];

        do
        {
            printf("want to input elements manually? [Y/N]\n");
            scanf(" %c", &Conf);
        }
        while(Conf != 'y' && Conf != 'Y' && Conf != 'n' && Conf != 'N');

        if(Conf == 'y' || Conf == 'Y')
        {
            for(int i = 1; i <= I; i++)
            {
                for(int j = 1; j <= I; j++)
                {
                    do
                    {
                        if(one > 1)
                        {
                            one--;
                        }
                        printf("enter element (%i, %i): ", i, j);
                        scanf("%i", &elements[(i-1)*I + (j-1)]);
                        if(elements[(i-1)*I + (j-1)] == 1)
                        {
                            one++;
                        }
                        else
                        {
                            others++;
                        }            
                    }
                    while(one > 1);
                }
            }
        }
        else
        {
            for(int i = 0; i < I*I; i++)
            {
                elements[i] = 0;
            }
        }
        
        if(others == I*I)
        {
            printf("seems like no element is 1\n");
        }

        if(others == I*I || Conf == 'n' || Conf == 'N')
        {
            do
            {
                printf("enter the indexes for 1:\n");
                scanf("%i", &ai);
                scanf("%i", &jay);
            }
            while(ai<1 && ai>I || jay<1 && jay>I);
            elements[(ai-1)*I + (jay-1)] = 1;
        }

        printf("\n\ngiven matrix:\n");

        for(int i = 1; i <= I; i++)
        {
            for(int j = 1; j <= I; j++)
            {
                printf("%i ", elements[(i-1)*I + (j-1)]);
            }
            printf("\n");
        }

        for(int i = 1; i <= I; i++)
        {
            for(int j = 1; j <= I; j++)
            {
                if(elements[(i-1)*I + (j-1)] == 1)
                {
                    if(i < I/2 + 1)
                    {
                        for(; i < I/2 + 1; i++)
                        {
                            opcount++;
                            for(jay = 1; jay <= I; jay++)
                            {
                                elements[i*I + (jay-1)] += elements[(i-1)*I + (jay-1)];
                                elements[(i-1)*I + (jay-1)] = elements[i*I + (jay-1)] - elements[(i-1)*I + (jay-1)];
                                elements[i*I + (jay-1)] -= elements[(i-1)*I + (jay-1)];
                            }
                            printf("\n\noperation %i: swap row %i & row %i\n", opcount, i, i+1);
                            for(int ai = 1; ai <= I; ai++)
                            {
                                for(int jay = 1; jay <= I; jay++)
                                {
                                    printf("%i ", elements[(ai-1)*I + (jay-1)]);
                                }
                                printf("\n");
                            }
                        }
                    }
                    else if(i > I/2 + 1)
                    {
                        for(; i > I/2 + 1; i--)
                        {
                            opcount++;
                            for(jay = 1; jay <= I; jay++)
                            {
                                elements[(i-2)*I + (jay-1)] += elements[(i-1)*I + (jay-1)];
                                elements[(i-1)*I + (jay-1)] = elements[(i-2)*I + (jay-1)] - elements[(i-1)*I + (jay-1)];
                                elements[(i-2)*I + (jay-1)] -= elements[(i-1)*I + (jay-1)];
                            }
                            printf("\n\noperation %i: swap row %i & row %i\n", opcount, i, i-1);
                            for(int ai = 1; ai <= I; ai++)
                            {
                                for(int jay = 1; jay <= I; jay++)
                                {
                                    printf("%i ", elements[(ai-1)*I + (jay-1)]);
                                }
                                printf("\n");
                            }
                        }
                    }

                    if(j < I/2 + 1)
                    {
                        for(; j < I/2 + 1; j++)
                        {
                            opcount++;
                            for(ai = 1; ai <= I; ai++)
                            {
                                elements[(ai-1)*I + (j)] += elements[(ai-1)*I + (j-1)];
                                elements[(ai-1)*I + (j-1)] = elements[(ai-1)*I + (j)] - elements[(ai-1)*I + (j-1)];
                                elements[(ai-1)*I + (j)] -= elements[(ai-1)*I + (j-1)];
                            }
                            printf("\n\noperation %i: swap column %i & column %i\n", opcount, j, j+1);
                            for(int ai = 1; ai <= I; ai++)
                            {
                                for(int jay = 1; jay <= I; jay++)
                                {
                                    printf("%i ", elements[(ai-1)*I + (jay-1)]);
                                }
                                printf("\n");
                            }
                        }
                    }
                    else if(j > I/2 + 1)
                    {
                        for(; j > I/2 + 1; j--)
                        {
                            opcount++;
                            for(ai = 1; ai <= I; ai++)
                            {
                                elements[(ai-1)*I + (j-2)] += elements[(ai-1)*I + (j-1)];
                                elements[(ai-1)*I + (j-1)] = elements[(ai-1)*I + (j-2)] - elements[(ai-1)*I + (j-1)];
                                elements[(ai-1)*I + (j-2)] -= elements[(ai-1)*I + (j-1)];
                            }
                            printf("\n\noperation %i: swap column %i & column %i\n", opcount, j, j-1);
                            for(int ai = 1; ai <= I; ai++)
                            {
                                for(int jay = 1; jay <= I; jay++)
                                {
                                    printf("%i ", elements[(ai-1)*I + (jay-1)]);
                                }
                                printf("\n");
                            }
                        }
                    }
                }
            }
        }
        printf("\n\nnumber of operations: %i\n\n", opcount);
        do
        {
            printf("Want to calculate again? [Y/N]\n");
            scanf(" %c", &Conf);
        }
        while(Conf != 'y' && Conf != 'Y' && Conf != 'n' && Conf != 'N');
    }
    while(Conf == 'y' || Conf == 'Y');
}