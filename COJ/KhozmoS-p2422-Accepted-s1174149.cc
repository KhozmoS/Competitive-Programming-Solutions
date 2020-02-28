#include<bits/stdc++.h>


using namespace std;
#define PB push_back
typedef unsigned long long ll;
const ll mod = 1000000000;

ll exp(ll a , ll b)
{
    if(b == 0) return 1ll;
    if(b == 1) return a%mod;

    ll p = exp(a , b / 2);
    if(b&1) return (p*p %mod)*a % mod;
    return p*p % mod;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll a , b;
        cin>>a>>b;
        cout<<exp(a, b)<<"\n";
    }
}
