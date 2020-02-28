#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

ll t, n, p, dp[1000005];

ll exp(ll b, ll e) {
    ll ret = 1;
    while(e > 0) {
        if(e & 1ll)
            ret = (ret * b) % mod;
        b = (b * b) % mod;
        e >>= 1ll;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--) {
        cin >> n;
        n++;
        ll s2 = (n * (n + 1ll) / 2ll) % mod;
        ll s4 = (s2 * s2) % mod;
        ll s3 = ((n * (n + 1)) % mod * (2ll * n + 1)) % mod;
        s3 = (s3 * exp(6ll, mod - 2)) % mod;
        ll sol = (s4 - 2 * s3 + s2) % mod;
        if(sol < 0)sol += mod;
        cout << sol << "\n";
    }
}