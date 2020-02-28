#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9+7;
ll b , n , c;

ll exp(ll a , ll e)
{
    ll res = 1;
    while(e)
    {
        if(e&1) res = (res*a)%mod;
        e /= 2ll;
        a = (a*a) % mod;
    }
    return res;
}

ll formule()
{
    return ((exp(b,n) - 1 + mod) % mod * exp(b-1 , mod-2)) % mod;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>b>>n>>c;
    cout<<formule()*c%mod<<"\n";
}
