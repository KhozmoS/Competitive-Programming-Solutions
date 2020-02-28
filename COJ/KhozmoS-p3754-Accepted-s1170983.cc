#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 10005;
const ll mod = 1e9 + 7;

set <int> up, down;
set <int> :: iterator ite;

vector <int> fact[MAX];

ll sol;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, a, T;
    cin >> T;

    for(int t = 1; t <= T; t++) {
        cin >> n >> k;

//        sol = 0, up.clear(), down.clear();
        sol = 0;

        while(k--) {
            cin >> a;
            up.insert(a);
        }

        for(int i = 2; i <= n; i++)
            if(!fact[i].size())
                for(int j = i; j <= n; j += i)
                    fact[j].push_back(i);

        for(int i = 1; i <= n; i++)
            if(up.find(i) == up.end())
                down.insert(i);

        for(int i = 1; i <= n; i++) {
            int tmp = 0;
            if(up.size()) {
                if(i & 1) {
                    tmp = *--up.end();
                }
                else {
                    tmp = *up.begin();
                }
                up.erase(up.find(tmp));
            }
            else {
                if(i & 1)
                    tmp = *--down.end();
                else {
                    tmp = *down.begin();
                }
                down.erase(down.find(tmp));
            }
            for(int j = 0; j < fact[tmp].size(); j++) {
                int p = fact[tmp][j];
                if((ite = up.find(p)) != up.end()) {
                    up.erase(ite);
                    down.insert(p);
                }
                else if((ite = down.find(p)) != down.end()) {
                    down.erase(ite);
                    up.insert(p);
                }
            }
            fact[tmp].clear();
            sol = 1ll * sol * (n + 1) + tmp;
            if(sol >= mod)sol %= mod;
        }

        cout << "Case #" << t << ": ";
        cout << sol << "\n";
    }
}