#include <bits/stdc++.h>

using namespace std;

// 2 1 4 3    5
const int MAX = 1e6 + 5;
typedef unsigned long long ll;
const ll mod = 1000000007;
ll dp[MAX];
ll exp(ll a , ll b)
{

    ll res = 1;

    while(b)
    {
        if(b & 1ll)
            res = (res * a) % mod;
        b >>= 1ll;
        a = (a * a) % mod;
    }
    return res;
}
ll fact[MAX];

void factorial()
{
  fact[0] = 1ll;
  for(ll i = 1 ; i < MAX ; i++)
      fact[i] = (i * fact[i - 1]) % mod;
}

int main()
{
    factorial();
    ios_base::sync_with_stdio(0);cin.tie(0);
    dp[2] = 1ll;
    dp[0] = 1ll;
    for(ll i = 3 ; i < MAX ; i++)
    {
        dp[i] = (i - 1) * dp[i - 1];
        dp[i] %= mod;
        dp[i] += (i - 1) * dp[i - 2];
        dp[i] %= mod;
    }
    int  n , k;cin>>n>>k;


                          //(n! / (n-k)! * k!)
    cout<<(dp[n - k] * ((fact[n] * exp((fact[n - k] * fact[k])% mod , mod-2)) % mod))% mod<<"\n";



}
