#include <stdio.h>
main()
{
    int i,n,n1,n2,sum=0;
    n1=1;
    n2=1;
    for (i = 0; i < 5; i++)
    {
        sum = sum + n1;
        n = n1 + n2;
        n1 = n2;
        n2 = n;
    }
    printf("%d",sum);
}
