#include<stdio.h>

int* twoSum(int *nums,int numsSize,int target)
{
    int hash[100000];
    int *result=(int*)malloc(2*sizeof(int));
    int i;
    memset(hash,-1,sizeof(hash));

    int min=49999;
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]<min)
        min=nums[i];
    }

    if(min<0)
    {
        for(i=0;i<numsSize;i++)
            nums[i]+=abs(min);
        target+=2*abs(min);
    }

    for(i=0;i<numsSize;i++)
    {
        int temp=target-nums[i];
        if(temp>=0 && hash[temp]!=-1)
        //printf("%d %d\n",hash[target-nums[i]]+1,i+1);
        {
            result[0]=hash[target-nums[i]]+1;
            result[1]=i+1;
        }
        else
        hash[nums[i]]=i;
    }
    return result;
}

int main()
{
    int arr[]={-1,-2,-3,-4,-5};
    int *res=twoSum(arr,5,-8);
    printf("%d  %d",res[0],res[1]);
}
