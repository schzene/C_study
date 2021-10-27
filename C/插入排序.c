#include<stdio.h>
int main()
{
	int a[11],i,j,t,min;
	printf("Input 10 numbers:\n");
	for(i=1;i<=10;i++)
		scanf("%d",&a[i]);
	puts("");
	for(i=2;i<=10;i++)
	{
		a[0]=a[i];
		j=i-1;
		while(a[0]<a[j])
		{a[j+1]=a[j];j=j-1;}
		a[j+1]=a[0];
	}
	printf("The sorted numbers:\n");
	for(i=1;i<=10;i++)
		printf("%d ",a[i]);
	puts("");
	return 0;	
}