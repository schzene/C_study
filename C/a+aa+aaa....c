#include <stdio.h>
#include <math.h>
int main()
{
    int a,n;
    long sum=0;
    long term=0;  //       
    scanf("%d %d",&a,&n);
    for (int i=1;i<=n;i++)
    {
        term = term+pow(10,i-1)*a ;//
        printf("%d\n",term);
        sum = sum + term;
    }
    printf("sum=%ld",sum);
        return 0;
}
