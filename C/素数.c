#include<stdio.h>
int main()
{
	int n,i,j,k=0;//i是2-10000待确认是否为素数的数，j表示i的因子，k表示素数的个数
	scanf("%d",&n);
	for(i=2;i<n;i++)
	{
		for(j=2;j<i;j++)
		{
			if(i%j==0)//判断i是否能被1和本身以外的数整除，%表示求余
			break;//break跳出第二个for循环
		}
		if(j>=i)
		{
			printf("%-4d ",i);
			k++;//每增加一个素数k就加1
			if(k%10==0)//一行打印10个数之后换行
			{
				printf("\n");
			}
		}
	}
}
