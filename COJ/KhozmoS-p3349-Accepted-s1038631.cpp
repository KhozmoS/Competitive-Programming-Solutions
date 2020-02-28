#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
const int MAXN = 1005;

typedef long long ll;

ll exp(ll a, ll b) {
    ll ans = 1;
    while(b > 0) {
        if(b & 1ll)
            ans = (ans * a) % MOD;
        b >>= 1ll;
        a = (a * a) % MOD;
    }
    return ans;
}

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
    //PASCAL();//

    //cout<<Comb[3][2];
     int t;
     cin>>t;
     while(t--)
     {
       ll n; cin>>n;
        cout<<(exp(2 , n) - 1 + MOD) % MOD<<"\n";
     }


    return 0;
}
