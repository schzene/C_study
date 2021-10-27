#include<stdio.h>
#include<math.h>
float F(float x,float x1,float x2)
{
    float f,f1,f2;
    do
    {   
        f1=2*x1*x1*x1-4*x1*x1+3*x1-6.0;
        f2=2*x2*x2*x2-4*x2*x2+3*x2-6.0;
    }
    while(f1*f2>0); //确保输入的x1,x2使得f1,f2符号相反
    do
    {
        x=(x1+x2)/2; //求x1,x2的中点
        f=2*x*x*x-4*x*x+3*x-6.0;
        if(f1*f>0) //当f与f1符号相同时
            {x1=x;f1=f;}
        else if(f2*f>0) //当f与f2符号相同时
            {x2=x;f2=f;}
    }
    while(fabs(f)>1e-6); //判断条件fabs(f)>1e-6的意思是f的值非常0
    return x;
}
int main(void)
{
    float x,x1,x2;
    float F(float x,float x1,float x2);
    x1=-10;x2=10;
    printf("x=%f\n",F(x,x1,x2));
    return 0;
}
/*
//what i do
//用二分法求2x^3-4x^2+3x-6在区间[-10,10]的根
#include<stdio.h>
#include<math.h>
int main(void)
{
    float f,f1,f2,x,x1,x2;
    x1=-10;x2=10;f=1;
    f1=2*x1*x1*x1-4*x1*x1+3*x1-6;
    f2=2*x2*x2*x2-4*x2*x2+3*x2-6;
    while(fabs(f)>1e-6)
    {
        x=(x1+x2)/2;
        f=2*x*x*x-4*x*x+3*x-6;
        if(f1*f>0)
            {x1=x;f1=f;}
        else if(f2*f>0)
            {x2=x;f2=f;}
    }
    printf("x = %f",x);
    return 0;
}
*/
