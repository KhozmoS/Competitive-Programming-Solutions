#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
const ll mod = 1000000007;


ll exp(ll a , ll b)
{
    if(b==0) return 1ll;
    if(b==1) return a;

    ll mt = exp(a , b/2);
    mt = ((mt%mod)*(mt%mod))%mod;
    if(b%2==0) return mt;

    return mt*(a%mod) %mod;
}


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;

    while(t--)
    {
        ll n , k;
        cin>>n>>k;

        k=((k%mod)+(1%mod))%mod;

        cout<<exp(k%mod,(n%(mod-1)))<<"\n";
    }
}
