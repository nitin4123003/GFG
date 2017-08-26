#include<stdio.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

struct maxHeap
{
    int *arr;
    int size;
};

void maxHeapify(struct maxHeap* heap,int index)
{
    int largest=index;
    int left=(index<<1)+1;
    int right=(index+1)<<1;

    if(left<heap->size && heap->arr[left]>heap->arr[largest])
        largest=left;

    if(right<heap->size && heap->arr[right]>heap->arr[largest])
        largest=right;

    if(largest!=index)
    {
        swap(&heap->arr[largest],&heap->arr[index]);
        maxHeapify(heap,largest);
    }
}

struct maxHeap* createAndBuildHeap(int arr[],int size)
{
    struct maxHeap* heap=(struct maxHeap*)malloc(sizeof(struct maxHeap));
    heap->arr=arr;
    heap->size=size;

    int i;
    for(i=(heap->size-2)/2;i>=0;i--)
        maxHeapify(heap,i);
    return heap;
}

void heapSort(int arr[],int size)
{
    struct maxHeap* heap=createAndBuildHeap(arr,size);

    while(heap->size>1)
    {
        swap(&heap->arr[0],&heap->arr[heap->size-1]);
        --(heap->size);
        maxHeapify(heap,0);
    }

}

void printArray(int* arr, int size)
{
    int i;
    for (i = 0; i < size; ++i)
        printf("%d ", arr[i]);
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, size);

    heapSort(arr, size);

    printf("\nSorted array is \n");
    printArray(arr, size);
    return 0;
}
