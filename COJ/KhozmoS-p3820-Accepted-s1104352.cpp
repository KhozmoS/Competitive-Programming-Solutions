#include <bits/stdc++.h>

using namespace std;

int dp[100005];
int mon[105];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int T, N, M, a;

    cin >>T;
    while(T--){
        fill(dp, dp+100005, INT_MAX);
        cin >>N >>M;
        for(int i = 0; i < M; i++){
            cin >>a;
            mon[i] = a;
        }
        dp[0] = 1;
        for(int j = 0; j < M; j++){
            for(int i = 0; i <= N; i++){
                if(i - mon[j] < 0) continue;
                if(dp[i - mon[j]] == INT_MAX) continue;
                dp[i] = min(dp[i], dp[i - mon[j]] + 1);
            }
        }
        cout <<dp[N]-1 <<"\n";
    }

    return 0;
}
