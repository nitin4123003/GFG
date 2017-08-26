#include<stdio.h>

int isPal(char str[])
{
    int flag=1;
    int i=0;
    int j=strlen(str)-1;
    while(i<j)
    {
        if(str[i]!=str[j])
        {
            flag=0;
            break;
        }
        i++;
        j--;
    }
    return flag;
}

int palindrome(char str[])
{
    int count=0;
    while(!(isPal(str)))
    {
        int num=atoi(str);
        char rev_str[10];
        strcpy(rev_str,str);
        int num2=atoi(strrev(rev_str));
        printf("num1=%d num2=%d",num,num2);
        num=num+num2;
        itoa(num,str,10);
        count++;
    }
    return count;
}

int main()
{
    int num;
    scanf("%d",&num);
    char str[10];
    itoa(num,str,10);
    printf("count=%d",palindrome(str));
    //printf("\n%s\n",str);
    //printf("count=%d",isPal(str));
}
