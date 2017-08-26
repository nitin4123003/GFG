#include<stdio.h>
int main()
{
    int array[]={12,34,45,9,8,90,3};
    int n=sizeof(array)/sizeof(array[0]);
    printf("n=%d\n",n);
    int i=0;
    int j=n-1;
    //for(i=0;i<n;i++)
    //printf("%d ",array[i]);
    int flag1, flag2;
    while(i<j)
    {
        flag1=0;
        flag2=0;
        if(array[i]%2!=0)
        flag1=1;
        else
        i++;
        if(array[j]%2==0)
        flag2=1;
        else
        j--;
        if(flag1 && flag2)
        {
            int temp=array[i];
            array[i]=array[j];
            array[j]=temp;
        }
    }
    for(i=0;i<n;i++)
    printf("%d  ",array[i]);
}
