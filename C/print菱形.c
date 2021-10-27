#include<stdio.h>
#include<math.h>
//实心菱形
/*
int main()
{
    int i, j, n,N ; 
    printf("Please input a number:");
    scanf("%d",&n);
    if(n%2==0)
        puts("ERROR");
    else
    {    
        N=(n+1)/2;
        //上半部分
        for(i = 0; i < N; i++) //N控制上半部分行数
        {   
            for(j = i; j < N-1; j++) //随行数递增，空格数递减
                printf(" ");
            for(j = 0; j < 2*i+1; j++) //随行数递增，“*”数递增
                printf("*");
            printf("\n"); //记得换行
        }   
        //下半部分，其实就是上半部分的翻转
        for(i = N-2; i >= 0; i--) //这里i从N-2开始的，不知道为什么的可以换成N-1试试，保证秒懂
        {
            for(j = i; j < N-1; j++) //这里的空格数刚好相反，是随行数递增的
                printf(" ");
            for(j = 0; j < 2*i+1; j++) //这里的“*”数则是递减的（想想图形的样子）
                printf("*");
            printf("\n"); //同样的记得换行
        }
    }
    return 0;
}
*/
//空心菱形与实心菱形最大的不同就在于：实心菱形每行的“*”是一次性连续打印完的；而空心菱形每行的“*”之间穿插了空格，故需要分两次打印每一行的“*”与空格。
int main()
{
    int i, j, k, n,N;
    printf("Please input a number:");
    scanf("%d",&n);
    if(n%2==0)
        puts("ERROR");
    else
    {
        N=(n+1)/2;
        //up
        for(i = 0; i < N; i++)
        {
            for(j = 0; j < N-i-1; j++) //上下两部分每一行前面的空格数没有变化
                printf(" ");
            printf("*"); //注意这里只打印了一个“*”
            if(0 != i) //这里判断条件的意思是仅当不是第一行时，后面每行才有第二个“*”需要打印
            {   
                for(k = 0; k < 2*i-1; k++) //这里是确定一行中两个“*”之间间隔的空格数
                    printf(" ");
                printf("*"); //后面补上一个“*”
            }   
            puts(""); //已打印完一行了，换一行继续
        }   
        //down
        for(i = N-2; i >= 0; i--) //下半部分是上半部分的倒置，试着自己阅读代码思考一下原理吧
        {   
            for(j = 0; j < N-i-1; j++)
                printf(" ");
            printf("*");
            if(0 != i)
            {
                for(k = 0; k < 2*i-1; k++)
                    printf(" ");
                printf("*");
            }
            puts("");
        }
    }
    return 0;
}
//what i do
/*
int main()
{
    int n,n0,i,j;
    scanf("%d",&n);
    if(n%2==0)
        printf("Error");
    else
    {
        n0=(n+1)/2;
        for(i=0;i<n0;i++)
        {
            for(j=i;j<n0-1;j++)
                printf(" ");
            printf("*");
            if(i!=0)
            {
                for(j=0;j<2*i-1;j++)
                    printf(" ");
                printf("*");
            }
            printf("\n");
        }
        for(i=n0-2;i>=0;i--)
        {
            for(j=i;j<n0-1;j++)
                printf(" ");   
            printf("*");
            if(i!=0)
            {
                for(j=0;j<2*i-1;j++)
                    printf(" ");
                printf("*");      
            }
             printf("\n");   
        }
    }
    return 0;
}
*/
