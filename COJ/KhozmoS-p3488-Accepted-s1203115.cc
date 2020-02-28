#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 17;
const int oo = 1e9 + 50;

int sol1, sol2;
int N, M, K, c, aux, pos, mask, dp[1 << 17];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fill(dp, dp + (1 << 17), oo);

    cin >> N >> K;
    for(int i = 0; i < N; i++)
        cin >> dp[1 << i];
    cin >> M;

    while(M--) {
        cin >> c >> aux;
        mask = 0;
        while(aux--) {
            cin >> pos;
            mask |= 1 << --pos;
        }
        dp[mask] = min(dp[mask], c);
    }

    for(mask = 1; mask < (1 << N); mask++)
        for(int i = mask; i > 0; i = (i - 1) & mask)
            dp[mask] = min(dp[mask], dp[mask ^ i] + dp[i]);

    sol1 = 0, sol2 = 0;
    for(mask = 1; mask < (1 << N); mask++) {
        if(dp[mask] <= K) {
            aux = __builtin_popcount(mask);
            if(aux > sol1)
                sol1 = aux, sol2 = dp[mask];
            else if(aux == sol1)
                sol2 = min(sol2, dp[mask]);
        }
    }

    cout << sol1 << " " << sol2 << "\n";
}