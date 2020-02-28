#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
string cad;
const ll mod = 1e9+7;

ll exp(ll a , int b)
{
    ll res = 1;
    while(b)
    {
        if(b % 2ll == 1ll)
        {
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        b /= 2ll;
    }
    return res;
}
ll sm(ll x)
{
    return (x*(x+1)%mod*exp(2,mod-2))%mod;
}

void bin(ll x)
{
    x%=mod;
    //  mcout<<x<<"\n";
    string ans = "";
    while(x)
    {
        ans = char(x%2ll+48ll)+ans;
        x/=2ll;
    }
    cout<<ans<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--)
    {
        cin>>cad;
        ll n1 = 0;
        for(int i = 0 ; i < cad.size() ; i++)
        {
            n1 = (n1 * 10 % mod + (cad[i]-48) + mod)%mod;
        }
        ll n2 = 0;
        for(int i = cad.size()-1 ; i > -1 ; i--)
        {
            n2 = (n2 * 10 % mod + cad[i]-48 + mod)%mod;
        }

        bin(((sm(n1)-sm((n2-1+mod)%mod) + mod)%mod));
    }

}
