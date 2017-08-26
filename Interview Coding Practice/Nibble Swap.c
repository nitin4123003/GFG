#include<stdio.h>
#include<stdlib.h>
int main()
{
    char a='Z';
    printf("%c\n",a);
    a=a<<4|a>>4;
    printf("%c",a);
    getch();
}
    
