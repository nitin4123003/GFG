#include<stdio.h>
#define N 4

int wPrefersM1OverM(int pref[][N],int w,int m,int m1)
{
    int i;
    for(i=0;i<N;i++)
    {
        if(pref[w][i]==m1)
        return 1;
        if(pref[w][i]==m)
        return 0;
    }
}

void stableMarriage(int pref[2*N][N])
{
    int i;
    int wPartner[N];
    int mFree[N];

    memset(wPartner,-1,sizeof(wPartner));
    memset(mFree,0,sizeof(mFree));

    int freeCount=N;

    while(freeCount>0)
    {
        int m;
        for(m=0;m<N;m++)
        {
            if(mFree[m]==0)
            break;
        }

        for(i=0;i<N && mFree[m]==0;i++)
        {
            int w=pref[m][i];

            if(wPartner[w-N]==-1)//Woman is free
            {
                wPartner[w-N]=m;
                mFree[m]=1;
                freeCount--;
            }
            else//if the woman is engaged then check for his preference
            {
                int m1=wPartner[w-N];

                if(wPrefersM1OverM(pref,w,m,m1)==0)
                {
                    wPartner[w-N]=m;
                    mFree[m]=1;
                    mFree[m1]=0;
                }
            }
        }
    }

    printf("The marriages are as follows\n");
    printf("Girl\tBoy\n");
    for(i=0;i<N;i++)
    printf("%d\t%d\n",i+N+1,wPartner[i]+1);
}

int main()
{
    int preferenceMat[2*N][N]={ {7, 5, 6, 4},
        {5, 4, 6, 7},
        {4, 5, 6, 7},
        {4, 5, 6, 7},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
    };
    stableMarriage(preferenceMat);

    return 0;
}
