#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second

int  g , m;
const int MAX = 1e4 + 5;
int mk[MAX][MAX];
bool muere(int a , int b , int c , int d , int e)
{
    int dis = ((a - c) * (a - c)) + ((b - d) * (b - d));

    return dis <= (e * e);
}
int main()
{
   cin>>g; for(int i = 0 ; i < g ; i++){
              int x , y; cin>>x>>y;
              mk[x][y]++;
    }
    cin>>m;
    int ans = g;
    while(m--)
    {
       int x , y , r;cin>>x>>y>>r;

       for(int i = max(x - r - 1 , 0) ; i <= min(x + r + 1 , MAX - 5) ; i++)
          for(int j = max(y - r - 1 , 0) ; j <= min(y + r + 1 , MAX - 5) ; j++)
             if(mk[i][j] && muere(x , y , i , j , r))
             {
                ans -= mk[i][j];
                mk[i][j] = 0;
             }
    }

    cout<<ans<<"\n";
}
