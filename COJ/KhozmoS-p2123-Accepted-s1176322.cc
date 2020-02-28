#include <bits/stdc++.h>

using namespace std;


#define cik(i, a, b, c) for(int i =(a); i <=(b); i +=(c))
#define bi pair<int, int>
#define f first
#define s second
#define mkp make_pair

const int maxn = 5005;
#define PB push_back
const int
    df[] = {0, 0,  0, -1, 1},
    dc[] = {0, 1, -1,  0, 0};

char A[maxn][maxn];
vector <int> B;
vector <int> adl[maxn];
int Bi[55][55];
int n , m;
bool mk[maxn][maxn];
int sz;
void bfs(int x , int y)
{
    sz = 0;
    B.PB(1);
    bool f = ((x&1)==(y&1));
    Bi[x][y] = 1;
    //cout<<Bi[x][y]<<"\n";
    int cur = 2;
    queue <int> X;
    queue <int> Y;
    mk[x][y] = true;
    X.push(x);
    Y.push(y);
    while(!X.empty())
    {
        x = X.front();X.pop();
        y = Y.front();Y.pop();
        sz++;
        //cout<<Bi[x][y]<<"\n";
        for(int i = 1 ; i <= 4 ; i++)
        {
            int nx = x + df[i];
            int ny = y + dc[i];
            if(((x&1) == (y&1)) == f && A[nx][ny] != 'X'){
                int re = Bi[x][y];
                if(!Bi[nx][ny]){
                    Bi[nx][ny] = cur;
                    adl[re].PB(cur++);
                }
                else
                    adl[re].PB(Bi[nx][ny]);
               // cout<<Bi[x][y]<<" "<<Bi[nx][ny]<<"\n";
            }
            if(!mk[nx][ny] && A[nx][ny] != 'X')
            {
                if(((x&1) == (y&1)) != f){
                    B.PB(cur);
                    Bi[nx][ny] = cur;
                    cur++;
                }
                mk[nx][ny] = true;
                X.push(nx);
                Y.push(ny);
            }
        }
    }
}
bool vis[maxn];
int p[5005];
bool kunh(int node)
{
    if(vis[node]) return false;
    vis[node] = true;

    for(int i = 0 ; i < adl[node].size() ; i++)
    {
        int x = adl[node][i];
        if(p[x] == -1)
        {
            p[x] = node;
            return true;
        }
        if(kunh(p[x]))
        {
            p[x] = node;
            return true;
        }
    }
    return false;
}

void clean()
{
    memset(p , -1 , sizeof(p));
    for(int i = 1 ; i < maxn ; i++){
        A[i][0] = 'X' , A[0][i] = 'X';
        A[n+1][i] = 'X';A[i][m+1] = 'X';
    }
    memset(mk , false, sizeof(mk));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n>>m){
    clean();

    for(int i = 1; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            cin>>A[i][j];
            
    bool flag = false;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            if(!mk[i][j] && A[i][j] != 'X')
            {
                bfs(i , j);
                int ans = 0;

                for(int k = 0 ; k < B.size() ; k++)
                {
                    ans += kunh(B[k]);
                    memset(vis , false , sizeof(vis));
                }
                //cout<<B.size();
                for(int k = 0 ; k < B.size() ; k++){
                    //cout<<adl[B[k]].size()<<" "<<B[k]<<"\n";
                    adl[B[k]].clear();
                }
               // return 0;

               // cout<<ans<<"\n";
                memset(Bi , 0 , sizeof(Bi));
                if(ans*2 != sz)
                    flag = true;
                B.clear();
                memset(p , -1  , sizeof(p));
            }

        cout<<(flag ? "1\n" : "2\n");
        }


}
