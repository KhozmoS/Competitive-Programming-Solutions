
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;
const ll MAX = 55;

int t, n, k;

int solve(int n, int k) {
    int res = 0;
    for(int i = 0; i < n; i++)
        res = (res + k) % (i + 1);
    return res + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> k;
        cout << solve(n, k) << "\n";
    }
}
