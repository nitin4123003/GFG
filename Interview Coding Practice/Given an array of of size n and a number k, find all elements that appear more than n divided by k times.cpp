#include<iostream>
using namespace std;
#include<stdlib.h>
struct eleCount
{
    int element;
    int count;
};

void moreThanNdK(int arr[],int n,int k)
{
    int i,l,j;
    struct eleCount *temp=(struct eleCount*)malloc((k-1)*sizeof(struct eleCount));
    for(int i=0;i<k-1;i++)
    temp[i].count=0;

    for(i=0;i<n;i++)
    {
        int j;

        for(j=0;j<k-1;j++)
        {
            if(temp[j].element==arr[i])
            {
                temp[j].count+=1;
                break;
            }
        }

        if(j==k-1)
        {
            for(l=0;l<k-1;l++)
            {
                if(temp[l].count==0)//If a position is empty
                {
                    temp[l].element=arr[i];
                    temp[l].count=1;
                    break;
                }
            }

            //If no empty position
            if(l==k-1)
            {
                for(l=0;l<k-1;l++)
                temp[l].count--;
            }
        }
    }

    for(i=0;i<k-1;i++)
    {
        int ac=0;
        for(j=0;j<n;j++)
        {
            if(temp[i].element==arr[j])
            ac++;
        }
        if(ac>n/k)
        cout<<"Number= "<<temp[i].element<<" Count= "<<ac<<endl;
    }
}
int main()
{
    cout << "First Test\n";
    int arr1[] = {4, 5, 6, 7, 8, 4, 4};
    int size = sizeof(arr1)/sizeof(arr1[0]);
    int k = 3;
    moreThanNdK(arr1, size, k);

    cout << "\nSecond Test\n";
    int arr2[] = {4, 2, 2, 7};
    size = sizeof(arr2)/sizeof(arr2[0]);
    k = 3;
    moreThanNdK(arr2, size, k);

    cout << "\nThird Test\n";
    int arr3[] = {2, 7, 2};
    size = sizeof(arr3)/sizeof(arr3[0]);
    k = 2;
    moreThanNdK(arr3, size, k);

    cout << "\nFourth Test\n";
    int arr4[] = {2, 3, 3, 2};
    size = sizeof(arr4)/sizeof(arr4[0]);
    k = 3;
    moreThanNdK(arr4, size, k);

    return 0;
}
