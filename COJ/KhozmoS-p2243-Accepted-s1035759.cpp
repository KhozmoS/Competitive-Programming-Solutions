 #include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;

    while(cin >> n && n) {
        n = n * (n * n + 1) / 2ll;
        cout << n << "\n";
    }

    return 0;
}