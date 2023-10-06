#include <stdio.h>

int main(void)
{
    char Conf;
    do
    {
        int n;
        double V;
        do 
        {
            printf("Enter the Voltage: ");
            scanf("%lf", &V);
        }
        while(V == '\0');
        do 
        {
            printf("Enter the number of resistors: ");
            scanf("%i", &n);
        }
        while(n < 0);
        double R[n], RT = 0, I;
        if(n == 0)
        {
            printf("Short Circuit!\n");
            goto Repeater;
        }
        for(int i = 0; i < n; i++)
        {
            do
            {
                printf("Enter Resistor%i: ", i + 1);
                scanf("%lf", &R[i]);
            }
            while(R[i] < 0);
        }
        do
        {
            printf("Enter S if the resistors are in series\nEnter P if the resistors are in parallel\n");
            scanf(" %c", &Conf);
        } 
        while (Conf != 'p' && Conf != 'P' && Conf != 's' && Conf != 'S');
        if(Conf == 's' || Conf == 'S')
        {
            for(int i = 0; i < n; i++)
            {
                RT += R[i];
            }
        }
        else
        {
            for(int i = 0; i < n; i++)
            {
                if(R[i] != 0)
                {
                    RT += 1 / R[i];
                }
            }
            RT = 1 / RT;
        }
        printf("Total Resistance = %.2lf Ohm\nCurrent = %.2lf A\n", RT, V / RT);        
        Repeater:
        do
        {
            printf("Want to calculate again? [Y/N]\n");
            scanf(" %c", &Conf);
        }
        while(Conf != 'y' && Conf != 'Y' && Conf != 'n' && Conf != 'N');
    }
    while(Conf == 'y' || Conf == 'Y');
}