#include <bits/stdc++.h>

using namespace std;


typedef  long long ll;



#define u first.first
#define d first.second
#define x second.first
#define y second.second
#define f first
#define s second

const int mx[] = {0 , 1 , 0 , -1};
const int my[] = {1 , 0 , -1 , 0};

typedef pair <int , int> ii;
typedef pair < ii , ii > item;

int M[700][700];
ii dp[700][700];

void dijstra ( int a , int b ) {


    set <item> S;
    S.insert(item(ii(0,0) , ii(a,b)));
    for(int i = 0 ; i < 700 ; i++)
        for(int j = 0 ; j < 700 ; j++)
            dp[i][j] = ii(INT_MAX,INT_MAX);
    dp[a][b] = ii(0,0);

    while(S.size()) {
        item node = *S.begin();
//        cout<<node.x<<" "<<node.y<<"\n";
        S.erase(node);
        if(node.u==dp[node.x][node.y].f)
            for(int i = 0 ; i < 4 ; i++) {
                int nx = node.x + mx[i];
                int ny = node.y + my[i];

                int dif = M[nx][ny] - M[node.x][node.y];

                if( M[nx][ny] != -1 && dp[nx][ny].f > (node.u + max(0,dif)) && (dif <= 2 && dif >= -4)) {
                    item nw;
                    nw.u = node.u + max(0,dif);
                    nw.d = node.d + max(0,dif*-1);
                    nw.x = nx;
                    nw.y = ny;
                    S.insert(nw);
                    dp[nx][ny].f = nw.u;
                    dp[nx][ny].s = nw.d;
                }
            }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--) {
        int n , m;
        cin>>n>>m;
        memset(M , -1 , sizeof(M));
        for(int i = 1 ; i <= n ; i++)
            for(int j =1  ; j <= m ; j++)
                cin>>M[i][j];
        dijstra(n,1);

        if(dp[1][m].f == INT_MAX) {
            cout<<"IMPOSSIBLE\n";
        } else {
            cout<<dp[1][m].f<<" "<<dp[1][m].s<<"\n";
        }
    }
}
