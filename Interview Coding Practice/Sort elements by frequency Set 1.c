#include<stdio.h>
#include<stdlib.h>

struct hash
{
    int index;
    int value;
};

int comp(const void *a ,const void *b)
{
    if(((struct hash*)a)->value > ((struct hash*)b)->value) return -1;
    if(((struct hash*)a)->value == ((struct hash*)b)->value) return 0;
    if(((struct hash*)a)->value < ((struct hash*)b)->value) return 1;
}

int findMax(int array[],int n)
{
    int i;
    int max_element=-1;
    for(i=0;i<n;i++)
    {
        if(max_element<array[i])
            max_element=array[i];
    }
    return max_element;
}

int main()
{
    int array[]= { 2, 5, 2, 8, 5, 6, 8, 8 };
    int n=sizeof(array)/sizeof(int);
    int hash_size=findMax(array,n)+1;
    int i,j;
    struct hash *h=(struct hash *)malloc(hash_size*sizeof(struct hash));
    memset(h,0,hash_size*sizeof(struct hash));
    for(i=0;i<n;i++)
    {
        h[array[i]].index=array[i];
        h[array[i]].value++;
    }

    qsort(h,hash_size,sizeof(struct hash),comp);
    //for(i=0;i<hash_size;i++)
    //    printf("%d %d\n",h[i].index,h[i].value);
    for(i=0;i<hash_size;i++)
    {
        for(j=0;j<h[i].value;j++)
             printf("%d ",h[i].index);
    }
    return 0;
}
