#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll F(ll val) {
    ll e = 1;
    while((1ll << e) <= val)e += 2;
    e -= 2;
    if(e <= 0)return 0;
    ll x = e / 2;
    return (1ll << x) + F(min((1ll << e) - 1ll, val - (1ll << e)));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, a, b;
    cin >> t;
    for(int i = 1; t--; i++) {
        cin >> a >> b;
        cout << "Case #" << i << ": ";
        cout << F(b) - F(a - 1) << "\n";
    }
}
