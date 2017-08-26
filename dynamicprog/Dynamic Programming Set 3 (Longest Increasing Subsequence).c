#include<stdio.h>

int lis(int arr[],int n)
{
    int i,j;
    int *_lis=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    _lis[i]=1;

    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && _lis[i]<_lis[j]+1)
            _lis[i]=_lis[j]+1;
        }
    }

    int max=0;
    for(i=0;i<n;i++)
    {
        //printf("%d %d\n",i+1,_lis[i]);
        if(max<_lis[i])
        max=_lis[i];
    }

    return max;
}

int main()
{
  int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Length of LIS is %d\n", lis( arr, n ) );

  getchar();
  return 0;
}
