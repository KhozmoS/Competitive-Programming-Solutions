#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;
typedef long long ll;

ll v[101];
int t , sz;
ll  n;

void F(ll val) {
    if(val == 0)return;
    if(!(val % 2ll)) {
        F(val / 2ll);
        for(int i = 0; i < sz; i++)
            v[i] *= 2ll;
    }
    else {
        ll pot = 1;
        while(pot <= val) pot *= 3ll;
        pot /= 3;
        F(val - pot);
        v[sz++] = pot;
    }
}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>t;
    while(t--) {
        cin>>n;

        sz = 0;

        F(n);
        cout<<sz<<"\n";
        sort(v, v + sz);

        for(int i = 0; i < sz; i++)
            cout<<v[i]<<(i == (sz-1)?"\n":" ");
    }
}
