#include <bits/stdc++.h>

using namespace std;

bool mk[111][111];
int n , m , grid[111][111] , w[111][111] , res;
int mx[]={0,0,1,-1};
int my[]={1,-1,0,0};

void dfs(int x, int y, int h)
{
    mk[x][y]=true;
    w[x][y] = grid[x][y];
    for(int i=0;i<4;i++)
    {
        int X = x + mx[i];
        int Y = y + my[i];
        if(X >= 0 && X < n && Y >= 0 && Y < m)
            if(h <= grid[X][Y])
                if(!mk[X][Y])
                    dfs(X,Y, grid[X][Y]);
    }
}

int main()
{
    int t,kk=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        memset(w , 0 , sizeof(w));
        memset(mk , 0 , sizeof(mk));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                {
                    cin>>grid[i][j];
                    w[i][j] = INT_MAX;
                }

        for(int i = 0; i < n ; i++)
        {
            if(!mk[i][0])
                dfs(i,0,grid[i][0]);
            if(!mk[i][m-1])
                dfs(i,m-1,grid[i][m-1]);
        }
        for(int i=0;i<m;i++)
        {
            if(!mk[0][i])
                dfs(0,i,grid[0][i]);
            if(!mk[n-1][i])
                dfs(n-1,i,grid[n-1][i]);
        }

        res=0;
        while(1)
        {
            bool chk=true;

            for(int i=1;i<n-1;i++)
                for(int j=1;j<m-1;j++)
                {
                    int mn=INT_MAX;
                    if(!mk[i][j])
                    {
                        for(int k = 0 ; k < 4 ; k++)
                        {

                            int X = i + mx[k];
                            int Y = j + my[k];
                            mn = min(mn, max(grid[X][Y],w[X][Y]));
                        }

                        if(mn < w[i][j])
                        {
                            w[i][j] = mn;
                            chk = false;
                        }
                    }

                }
            if(chk)
            break;
        }

        for(int i = 1; i < n-1 ; i++)
            for(int j = 1 ; j < m-1 ; j++)
                if(w[i][j] > grid[i][j])
                    res += w[i][j] - grid[i][j];

        cout<<res<<"\n";
    }
}
