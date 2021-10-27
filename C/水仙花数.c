#include<stdio.h>
int narcissistic( int number )
{
    int a,a0=1,i,x,y,flag=0,sum=0;
    x=number;
    while(x>0)
    {
        x/=10;
        flag++;
    }
    y=number;
    while(y>0)
    {
        a=y%10;
        y/=10;
        for(i=0;i<flag;i++)
            a0=a0*a;
        sum+=a0;
        a0=1;
    }
    if(sum==number)
        return 1;
    else
        return 0;
}
void PrintN( int m, int n )
{
    if(100<=m&&m<=n)
        for(int i=m+1;i<n;i++)
            if(narcissistic(i))
                printf("%d\n",i);
}
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    PrintN(m, n);
    return 0;
}