#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX = 14;
const ll mod = 1e9 + 7;

char cad[MAX][25], s[5005];
bool dp[5005][1 << MAX];
int n, l, sol, len[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> cad[i] + 1;
        len[i] = strlen(cad[i] + 1);
    }

    cin >> s + 1;
    l = strlen(s + 1);

    for(int i = 1; i <= l; i++) {
        dp[i - 1][0] = true;
        for(int k = 0; k < n; k++) {
            if(len[k] > i)continue;
            bool ok = true;
            for(int j = 1; ok && j <= len[k]; j++)
                if(cad[k][j] != s[i - len[k] + j])
                    ok = false;
            if(!ok)continue;
            for(int mask = 0; mask < (1 << n); mask++)
                if(!(mask & (1 << k)))
                    dp[i][mask | (1 << k)] |= dp[i - len[k]][mask];
        }
    }

    for(int i = 1; i <= l; i++)
        sol += dp[i][(1 << n) - 1];

    cout << sol << "\n";
}