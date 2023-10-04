#include<stdio.h>
#include<math.h>
int main()
{
    int dec = 872,log = -1,log1;
    scanf("%d",&dec);
    int log2 = dec;
    while(log2)
    {
        log2/=10;
        log++;
    }
    for(;log>=0;log--)
    {
        log1 = dec/pow(16,log);
        dec = dec%(int)pow(16,log);
        if(log1>9)
        printf("%c",log1+55);
        else
        printf("%d",log1);
    }
    return 0;
}