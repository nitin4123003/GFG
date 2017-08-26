#include<stdio.h>
#include<limits.h>
struct Heapnode
{
    int val;
    int r;
    int c;
};

void swap(struct Heapnode *a,struct Heapnode *b)
{
    struct Heapnode temp=*a;
    *a=*b;
    *b=temp;
}

void minHeapify(struct Heapnode hArr[],int i,int heapSize)
{
    int l=i<<1+1;
    int r=i<<1+2;

    int smallest=i;

    if(l<heapSize && hArr[l].val<hArr[i].val)
    smallest=l;

    if(r<heapSize && hArr[r].val<hArr[smallest].val)
    smallest=r;

    if(smallest!=i)
    {
        swap(&hArr[i],&hArr[smallest]);
        minHeapify(hArr,smallest,heapSize);
    }
}

void buildHeap(struct Heapnode hArr[],int n)
{
    int i=(n-1)/2;

    while(i>=0)
    {
        minHeapify(hArr,i,n);
        i--;
    }
}

int kthSmallest(int matrix[4][4],int n,int k)
{
    if(k==0 || k>n*n)
    return INT_MAX;

    int i;
    //struct Heapnode *hArr=(struct Heapnode*)malloc(n*sizeof(struct Heapnode));
    struct Heapnode hArr[n];
    for(i=0;i<n;i++)
        hArr[i] = (struct Heapnode){matrix[0][i],0,i};
    printf("%d\n\n",hArr[0].val);
    buildHeap(hArr,n);

    struct Heapnode hr;
    for(i=0;i<k;i++)
    {
        hr=hArr[0];

        int nextVal=(hr.r<(n-1))?matrix[(hr.r) + 1][hr.c]:INT_MAX;

        hArr[0]=(struct Heapnode){nextVal,(hr.r)+1,hr.c};
        minHeapify(hArr,0,n);
    }

    return hr.val;
}

int main()
{
  int mat[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {25, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
  printf("7th smallest element is %d\n",kthSmallest(mat, 4, 7));
  return 0;
}
