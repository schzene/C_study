#include<stdio.h>
int main()
{
    int a[11],i,j,min,t;
    printf("Input 10 numbers:\n");
    for(i=1;i<=10;i++)
        scanf("%d",&a[i]);
    puts("");
    for(i=1;i<10;i++)
    {
        min=i;
        for(j=i+1;j<=10;j++)
            if(a[min]>a[j])
                min=j;
        if(min!=i)
            {t=a[i];a[i]=a[min];a[min]=t;}
    }    
    printf("The sorted numbers:\n");
    for(i=1;i<=10;i++) printf("%d ",a[i]);
    puts("");    
    return 0;
}
