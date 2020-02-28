#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
const ll mod = 1e9+7;


ll exp(ll a , ll b)
{
    ll res = 1;
    while(b)
    {
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return res;
}



int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
   ll n;
    while(cin>>n)
    {
        
        cout<<exp(3,n)<<"\n";
    }
}
