#include <stdio.h>
main()
{
    int i,n,num,max;
    scanf("%d",&n);
    scanf("%d",&max);
    for(i=1;i<5;i++)
    {
        scanf("%d",&num);
        if(num>max) max=num;
    }
    printf("%d",max);
}
