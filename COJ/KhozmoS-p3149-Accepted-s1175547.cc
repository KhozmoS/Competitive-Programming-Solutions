#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e6;
#define inv(a) exp(a , mod-2)

typedef long long ll;
const ll mod = 1000000007;

ll F[MAX];

ll exp(ll a , ll b)
{
    if(b == 0) return 1;
    if(b == 1) return a;

    ll p = exp(a , b/2);
    if(b&1) return (p*p%mod)*a%mod;
    return p*p%mod;
}
ll cnt(ll x , ll p)
{
    ll res = 0;
    while(x)
    {
        x /= p;
        res += x;
    }
    return res;
}

ll p[MAX]; int id;

bool mk[MAX];
void criba()
{
    for(int i = 2 ; i < MAX ; i++)
        if(!mk[i]){ p[++id] = i;
            for(int j = i+i ; j < MAX ; j += i)
                mk[j] = true;
        }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    F[0] = 1ll;
    for(ll i = 1 ; i < MAX ; i++) F[i] = (i*F[i-1]) % mod;
    criba();

    int t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        ll ans = 1;
        for(int i = 1 ; p[i] <= n ; i++)
        {
                ll e = cnt(n , p[i]);
                ll cur = (exp(p[i] , e+1) - 1 + mod) % mod;
                cur = (cur * inv(p[i]-1)) % mod;
                ans = (ans * cur) % mod;
        }
        ans = (ans - F[n] + mod) % mod;
        cout<<ans<<"\n";
    }
}
