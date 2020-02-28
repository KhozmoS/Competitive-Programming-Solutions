#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
typedef pair <int , int> ii;
typedef pair <ii , int> iii;

int mx[] = {1 , 0 , -1 , 0};
int my[] = {0 , 1 , 0 , -1};
bool mk[105][105][4];
char M[105][105];
int dp[105][105][4];
int sx , sy , gx , gy;
bool ok;
void bfs(int x , int y , int face)
{
    int ans = 0;
    queue <iii> q;
    q.push(iii(ii(x,y),face));
    mk[x][y][face] = true;

    while(!q.empty())
    {
        iii tmp = q.front();q.pop();
        x = tmp.f.f;
        y = tmp.f.s;
        face = tmp.s;
        if(x==gx&&y==gy)
        {
            cout<<dp[x][y][face]<<"\n";
            ok = true;
            return;
        }
        for(int i = -1 ; i < 2 ; i++)
        {
            if(!i)
            {
                int nx = x+mx[face];
                int ny = y+my[face];
                if(M[nx][ny] != '#' && !mk[nx][ny][face])
                {
                    q.push(iii(ii(nx,ny),face));
                    dp[nx][ny][face] = dp[x][y][face] + 1;
                    mk[nx][ny][face] = true;
                }
            }
            else{
                int nface = (face+i+4)%4;
                if(!mk[x][y][nface])
                {
                    q.push(iii(ii(x,y),nface));
                    dp[x][y][nface] = dp[x][y][face] + 1;
                    mk[x][y][nface] = true;
                }
            }
        }
    }
}
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   int n , m;cin>>n>>m;
   cin>>sx>>sy>>gx>>gy;
   for(int i = 0 ; i < 105 ; i++)
        for(int j = 0 ; j < 105 ; j++)
            M[i][j] = '#';
   for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            cin>>M[i][j];
   bfs(sx,sy,0);
   if(!ok)
       cout<<"impossible\n";

}
