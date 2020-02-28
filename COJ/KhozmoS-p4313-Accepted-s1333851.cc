#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3+5;
const int MAXC = 1e6+5;

const int mx[] = {0 , 1, 1, 1, 0  , -1, -1, -1};
const int my[] = {1 , 1, 0, -1, -1, -1, 0, 1};
#define f first
#define s second
typedef pair <int , int> ii;

bool mk[MAX][MAX][2] , cv[MAXC];
ii dp[MAX][MAX];
char M[MAX][MAX];
int n , m , id , DP[MAXC];

bool isValid(int nx , int ny , int i) {
    return (nx >= 0 && nx <= n+1 && ny >= 0 && ny <= m+1 && !mk[nx][ny][i] && M[nx][ny] != '*');
}

int bfs1(int x , int y , int id) {
    queue <int> qx;
    queue <int> qy;
    qx.push(x);
    qy.push(y);
    mk[x][y][0] = true;
    int res = 0;
    while(!qx.empty()) {
        x = qx.front();
        y = qy.front();
        qx.pop();
        qy.pop();
        res += M[x][y] == '#';
        dp[x][y].f = id;
//        cout<<n<<" "<<m<<" "<<id<<" "<<res<<"\n";
        for(int i = 0  ; i < 8 ; i++) {
            int nx = x+mx[i];
            int ny = y+my[i];
            if(isValid(nx,ny,0))
            {
                mk[nx][ny][0] = true;
                qx.push(nx);
                qy.push(ny);
            }
        }
    }
    return res;
}

void bfs2(int x , int y , int cnt) {
    queue <int> qx;
    queue <int> qy;
    qx.push(x);
    qy.push(y);
    mk[x][y][1] = true;

    while(!qx.empty()) {
        x = qx.front();
        y = qy.front();
        qx.pop();
        qy.pop();
        dp[x][y] = ii(id , cnt);

        for(int i = 0  ; i < 8 ; i++) {
            int nx = x+mx[i];
            int ny = y+my[i];
            if(isValid(nx,ny,1))
            {
                mk[nx][ny][1] = true;
                qx.push(nx);
                qy.push(ny);
            }
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);



    while(cin>>n>>m){
        id = 1;
        DP[1] = 0;
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= m; j++) {
                cin>>M[i][j];
                dp[i][j] = ii(0,0);
                M[0][j] = '.';
                dp[0][j] = ii(0,0);
                M[n+1][j] = '.';
                dp[n+1][j] = ii(0,0);
                M[i][0] = '.';
                dp[i][0] = ii(0,0);
                M[i][m+1] = '.';
                dp[i][m+1] = ii(0,0);
                mk[i][j][0] = mk[i][j][1] = false;
                mk[0][j][0] = mk[0][j][1] = false;
                mk[n+1][j][0] = mk[n+1][j][1] = false;
                mk[i][0][0] = mk[i][0][1] = false;
                mk[i][m+1][0] = mk[i][m+1][1] = false;

            }

        int ans = 0;
        for(int i = 0 ; i <= n+1 ; i++)
            for(int j = 0 ; j <= m+1; j++) {

                if(!mk[i][j][0] && M[i][j] != '*') {
//                    if(i==4&&j==2) {
//                        cout<<M[i][j]<<" "<<"Carlos\n";
//                    }
                    DP[id] = bfs1(i,j,id);
    //                cout<<cnt<<"\n";
                    id++;
                    DP[id] = 0;
                }
            }
        dp[0][0].f = DP[1];
        ans = dp[0][0].f;
//        for(int i = 1 ; i < id ; i++)
//            cout<<i<<" "<<DP[i]<<" "<<"asdasd\n";
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= m ; j++) {
                if(M[i][j]=='*') {
                    int tmp = 0;
                    for(int k = 0  ; k < 8 ; k++) {
                        int nx = i+mx[k];
                        int ny = j+my[k];

                        int idx = dp[nx][ny].f;
                        dp[nx][ny].s = DP[idx];

                        int c = dp[nx][ny].s;
                        if(!cv[idx]) {
//                            cout<<c<<" "<<i<<" "<<j<<"aa\n";
                            tmp += c;
                            cv[idx] = true;
                        }
                    }
                    if(cv[1]) {
                        ans = max(ans , tmp);
                    }
                    for(int k = 0  ; k < 8 ; k++) {
                        int nx = i+mx[k];
                        int ny = j+my[k];
                        int idx = dp[nx][ny].f;
                        cv[idx] = false;
                    }
                }
            }
         cout<<ans<<"\n";
    }
}
