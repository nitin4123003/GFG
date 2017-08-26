#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define ROW 5 
#define COL 5

int isSafe(int M[][COL],int row,int col,bool visited[][COL])
{
    return ((row>=0 && row<ROW)&&
            (col>=0 && col<COL)&&
            (M[row][col] && !visited[row][col]));
}

void DFS(int M[][COL],int row,int col,bool visited[][COL])
{
    static int rowBod[]={-1,-1,-1,0,0,1,1,1};
    static int colBod[]={-1,0,1,-1,1,-1,0,1};
    
    int k;
    visited[row][col]=true;
    
    for(k=0;k<8;k++)
    {
        if(isSafe(M,row+rowBod[k],col+colBod[k],visited))
        DFS(M,row+rowBod[k],col+colBod[k],visited);
    }
}

int countIsl(int M[][COL])
{
    bool visited[ROW][COL];
    memset(visited,0,sizeof(visited));
    
    int i,j,count=0;
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            if(M[i][j] && !visited[i][j])
            {
                DFS(M,i,j,visited);
                ++count;
            }
        }
    }
    return count;
}

int main()
{
    int M[][COL]={{1,1,0,1,0},
                {0,1,0,0,1},
                {1,0,0,1,1},
                {0,1,0,0,0},
                {1,0,1,0,1}};
    
    printf("Islands=%d",countIsl(M));
    getch();
}
