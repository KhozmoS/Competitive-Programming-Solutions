#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

const ll MAX = 22;
//const ll mod = 1e17 + 23;

set <ll> Hash;
ll N, a, sol, cop[MAX + 5][MAX + 5], pos[1 << MAX], dp[5 + (1 << MAX)], val[MAX + 5];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    N++;
    for(ll i = 0; i < N; i++)
        cin >> val[i];
    for(ll i = 0; i < N; i++)
        for(ll j = 0; j < N; j++)
            cop[i][j] = (__gcd(val[i], val[j]) == 1) && (i != j);
    for(ll i = 0; i < N; i++)
        pos[1 << i] = i;
    dp[0] = 1;
    for(ll i = 1; i < (1 << N); i++) {
        ll mask = i ^ (i & -i);
        ll num = pos[i & -i];
        bool ok = true;
        while(mask != 0 && ok) {
            ok &= dp[mask];
            ll tmp = pos[mask & -mask];
            if(!cop[num][tmp])
                ok = false;
            mask ^= mask & -mask;
        }
        dp[i] = ok;
    }
    for(ll i = 3; i < (1 << N); i += 2) {
        if(dp[i]) {
            ll prod = 1;
            for(ll j = 0; j < N; j++)
                if(i & (1 << j)) {
                    prod = (prod * val[j]);
                }
            Hash.insert(prod);
        }
    }
    cout << Hash.size() << "\n";
}