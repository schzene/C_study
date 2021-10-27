#include<stdio.h>
#define n 100
int main()
{
    char str[n];
    int i=0,word=0,num=0;
    puts("please input a sentence");
    gets(str);
    while(str[i]!='\0')
    {
        if(str[i]==' ')
            word=0;
        else if(word==0)
        {
            word=1;
            num++;
        }
        i++;
    }
    printf("there are %d words in the line\n",num);
    return 0;
}
