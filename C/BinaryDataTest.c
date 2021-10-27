#include<stdio.h>
//exit函数需要的函数库
#include<stdlib.h>
#define N 10
main()
{
	FILE *fpw,*fpr;  //定义一个用来写的文件指针fpw和一个读文件的指针fpr
	int array[N]={10,9,8,7,6,5,4,3,2,1};//定义整型数组array用来存放将要写入文件和从文件读出的数据
	
	 //建立一个新的数据文件，把数组中的数据,以二进制文件的方式写入文件 
	//数据文件以写二进制文件的wb方式打开
	if((fpw=fopen("d:\\data.dat","wb"))==NULL) 
	{
		//若fpw为空，表示不能创建该文件，也许是文件夹不存在或者磁盘满了，或者磁盘写保护了 
		//则输出该文件不能打开的信息
		printf(" file which  named data.dat cannot be opened\n");    
		//exit()用来关闭所有打开的文件并返回操作系统，参数为0时表示正常返回，为1时表示出错返回
		exit(1);                                                    
	}   
	
	//给文件中写入二进制流，一次写入一个数组的所有数据，不用循环 
	fwrite(array,sizeof(int),N,fpw);   
		                           
	fclose(fpw); 

	//关闭文件
	//运行完之后，打开D盘根目录下的data.dat 观察 
	
	//data.dat 文件需已经在D盘的根目录下
	if((fpr=fopen("d:\\data.dat","rb"))==NULL)   
        //使用fopen函数打开文件data.dat,参数r表示以只读二进制的方式打开
		//使用两个\\的原因请到网上查找
	{
		printf("the file which  named input.dat cannot be opened\n");    //若fpr为空，则输出该文件不能打开的信息
		exit(1);//如果不能打开数据，直接终止程序
		//exit()用来关闭所有打开的文件并返回操作系统，参数为0时表示正常返回，为1时表示出错返回
	}   

    //一次读入所有数据的二进制流，无需使用循环 
    int array1[N];//另外使用一个数组
	
	fread(array1,sizeof(int),N,fpr);
	
	
   for(int i=0;i<N;i++)
     //屏幕上输出N个数字，看对不对
       printf("%d\t",array1[i]);

   //打开的文件必须关闭，否则下次打开会有问题
   fclose(fpr);  
  
  
}
