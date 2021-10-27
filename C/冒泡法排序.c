#include<stdio.h>
int main()
{
    int a[10],i,j,t;
    printf("Input 10 numbers:\n");
    for(i=1;i<=10;i++)
        scanf("%d",&a[i]);
    puts("");
    for(i=0;i<9;i++)
        for(j=0;j<10-i;j++)
            if(a[j]>a[j+1])
                {t=a[j];a[j]=a[j+1];a[j+1]=t;}
    printf("The sorted number:\n");
    for(i=1;i<=10;i++)
        printf("%d ",a[i]);
    puts("");        
    return 0;
}