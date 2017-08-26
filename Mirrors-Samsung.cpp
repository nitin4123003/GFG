#include<iostream>
using namespace std;

int main()
{
    /*/47 \'\\'*/
    char mat[4][4]={{'.','.','\\','.'},
                    {'/','\\','.','.'},
                    {'.','/','.','.'},
                    {'\\','.','/','.'}};

    int m=4,n=4;
    int i,j;
    /*for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            cin>>mat[i][j];
    }
    /*for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            cout<<mat[i][j];
    }*/
    int up=0,left=0,right=1,down=0;
    int x=0,y=0;
    int count=0;
    while(x<m && y<n && x>=0 && y>=0)
    {
        if(mat[x][y]=='/'||mat[x][y]=='\\')
        {
            count++;
            if(mat[x][y]=='/' && (left||down))
            {
                left=!left;
                down=!down;
            }
            if(mat[x][y]=='/' && (up||right))
            {
                up=!up;
                right=!right;
            }
            if(mat[x][y]=='\\' && (left||up))
            {
                left=!left;
                up=!up;
            }
            if(mat[x][y]=='\\' && (down||right))
            {
                down=!down;
                right=!right;
            }
        }
        //cout<<left<<" "<<right<<" "<<up<<" "<<down<<endl;
        if(up)
        x--;
        if(down)
        x++;
        if(left)
        y--;
        if(right)
        y++;
        //cout<<x<<" "<<y<<endl;
    }
    cout<<count<<endl;
}
