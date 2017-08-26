#include<stdio.h>
#define NO_OF_CHARS 256

#define min(a,b) (a>b?b:a)

int longestUniqueSubstr(char str[])
{
    int n=strlen(str);
    int *visited=(int*)malloc(NO_OF_CHARS*sizeof(int));
    int cur_len=1;
    int prev_index;
    int max_len=1;
    int i;
    memset(visited,-1,NO_OF_CHARS*sizeof(int));

    //for(i=0;i<256;i++)
    //    printf("%d ",visited[i]);
    visited[str[0]]=0;
    for(i=1;i<n;i++)
    {
        prev_index=visited[str[i]];

        if(prev_index==-1||i-cur_len>prev_index)
        cur_len++;

        else
        {
            if(cur_len>max_len)
            max_len=cur_len;
            cur_len=i-prev_index;
        }

        visited[str[i]]=i;
    }

    if(cur_len>max_len)
    max_len=cur_len;

    free(visited);

    return max_len;
}

int main()
{
    char str[] = "ABDEFGABEF";
    printf("The input string is %s \n", str);
    int len =  longestUniqueSubstr(str);
    printf("The length of the longest non-repeating character substring is %d", len);

    getchar();
    return 0;
}
