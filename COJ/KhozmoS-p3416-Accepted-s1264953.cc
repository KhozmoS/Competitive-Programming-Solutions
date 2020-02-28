#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll mod = 1000000007;

ll exp(ll a , ll b)
{
    ll res = 1LL;
    while(b)
    {
        if(b&1)
            res = (res * a) % mod;
        b>>=1LL;
        a = (a*a) % mod;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll n , a , b;
    while(cin>>n>>a>>b){
    if(!a && !b)
        cout<<1<<"\n";
    else if(!a)
        cout<<((exp(n , b) % mod)-n  + mod) % mod<<"\n";
    else if(!b)
        cout<<((exp(n , a) % mod)-n + mod) % mod<<"\n";
    
    else
    cout<<((exp(n , a) * exp(n , b) % mod) - (n*n%mod) + mod) % mod<<"\n";
    }
}
