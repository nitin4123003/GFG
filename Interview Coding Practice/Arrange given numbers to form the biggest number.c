#include<stdio.h>

int myCompare(char str1[],char str2[])
{
    char temp1[10];
    strcpy(temp1,str1);
    //char temp2[]=str2;
    strcat(str1,str2);
    //strcat(str2,temp1);

    printf("%s\n%s\n\n",str1,str2);
    int dec=strcmp(str1,str2);
    printf("%d",dec);
    return dec;

}

void printLargest(char arr[][4])
{
    qsort(arr,4,sizeof(char),myCompare);
}

int main()
{
    char arr[][4]={"54","546","548","60"};
    myCompare("54","546");
    //printLargest(arr);
}
