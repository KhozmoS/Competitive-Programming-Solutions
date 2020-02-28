#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string a , b;
ll t, n, sol;

map <string, ll> mapa;
map <string, ll> :: iterator ite;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> t;

    while(t--) {
        cin >> n;
        mapa.clear();
        while(n--) {

            cin >> a >> b;

            mapa[b]++;

        }
        sol = 1;
        for(ite = mapa.begin(); ite != mapa.end(); ite++)
        sol *= ite -> second + 1;

        cout << --sol << "\n";
    }
}
