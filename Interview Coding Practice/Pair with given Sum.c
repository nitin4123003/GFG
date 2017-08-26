#include<stdio.h>
#include<conio.h>

int comp(const void *a,const void *b)
{
    return (*(int*)a-*(int*)b);
}

int findPair(int a[],int b[],int sum)
{
    int i=0,j=3,flag=0;
    while((a[i]+b[j])!=sum)
    {
        if((a[i]+b[j])>sum)
        j--;
        else if((a[i]+b[j])<sum)
        i++;
        if(i>3||j<0)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    printf("Sum formed from indices %d and %d\n",i+1,j+1);
    else
    printf("Not found\n");
}
int main()
{
    int a[]={13,1,25,18,};
    int b[]={17,5,23,15};
    int i;
    qsort(a,4,sizeof(a[0]),comp);
    qsort(b,4,sizeof(b[0]),comp);
    /*for(i=0;i<4;i++)
    printf("%d\n",a[i]);*/
    int sum=40;
    findPair(a,b,sum);
    getch();
}
