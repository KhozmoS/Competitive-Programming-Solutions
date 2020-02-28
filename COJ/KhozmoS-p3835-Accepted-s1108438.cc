#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 5;

int t, n, m, q, a, b, v[MAX], d[MAX][MAX];

int c(int x) {
    return x * x * x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                d[i][j] = 1e9;
        cin >> m;
        while(m--) {
            cin >> a >> b;
            d[a][b] = c(v[b] - v[a]);
        }for(int i = 1 ; i <= n ; i++)
      for(int j = 1 ; j <= n ; j++)
         //if(dp[j][i] != inf)
           for(int k = 1 ; k <= n ; k++)
           //   if(d[i][k] != inf){
                 d[j][k] = min(d[j][k] , d[j][i] + d[i][k]);
               //  if(dp[j][i] + dp[i][k]<d[j][k]){
                 //   parent[j][k]=i;
             //    }

        cin >> q;
        while(q--) {
            cin >> a;
            if(d[1][a] == 1e9 || d[1][a] < 3)
                cout << "?\n";
            else
                cout << d[1][a] << "\n";
        }
    }
}
