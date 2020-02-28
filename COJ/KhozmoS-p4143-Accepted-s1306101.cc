#include <bits/stdc++.h>

using namespace std;

const int mod = 1e6;
int dp[2][40][40][40][5][5];


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int A , B , C , D;
    cin>>A>>B>>C>>D;
    dp[0][0][0][0][0][0] = 1;
    int cur = 1;

    for(int a = 0 ; a <= A ; a++)
    {
       cur^=1;
       //system("pause");
       memset(dp[cur ^ 1] , 0 , sizeof(dp[cur^1]));

       for(int b = 0 ; b <= B ; b++)
            for(int c = 0 ; c <= C ; c++)
                for(int d = 0 ; d <= D ; d++)
                    for(int x = 0 ; x <= 4 ; x++)
                        for(int y = 0 ; y <= 4 ; y++)
                        {
                            if(((x>2||y>2) && (x==2||y==2||x==4||y==4)) || (!x || !y))
                                dp[cur^1][b][c][d][y][1] = (dp[cur^1][b][c][d][y][1] + dp[cur][b][c][d][x][y]) % mod;
                            if(((x>2||y>2) && (x==1||y==1||x==3||y==3)) || (!x || !y))
                                dp[cur][b+1][c][d][y][2] = (dp[cur][b+1][c][d][y][2] + dp[cur][b][c][d][x][y]) % mod;
                            if(((x<=2||y<=2) && (x==2||y==2||x==4||y==4)) || (!x || !y))
                                dp[cur][b][c+1][d][y][3] = (dp[cur][b][c+1][d][y][3] + dp[cur][b][c][d][x][y]) % mod;
                            if(((x<=2||y<=2) && (x==1||y==1||x==3||y==3)) || (!x || !y))
                                dp[cur][b][c][d+1][y][4] = (dp[cur][b][c][d+1][y][4] + dp[cur][b][c][d][x][y]) % mod;
                        }

    }
    int ans = 0;
    for(int x = 0 ; x <= 4 ; x++)
        for(int y = 0 ; y <= 4 ; y++)
            ans = (ans + dp[A&1][B][C][D][x][y])%mod;
    cout<<ans<<"\n";

}
