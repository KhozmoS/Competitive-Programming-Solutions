#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll n, mod=1000000007, ini, fin, l,h, sol,aux;

ll exp(ll a , ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}
int main()
{
   // cout<<exp(2 , 5);
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int t;
cin>>t;
for(int i =1; i<=t;i++){
cin>>n;
h=(n+1)/2;
l=(n+2)/2;
ini = n-h;
n%=mod;
ini%=mod;
l%=mod;
h%=mod;
sol=(n*(n+1))%mod;
sol=(sol*(n+2))%mod;
//sol= ((n*(n+1)*(n+2))%mod- (ini*(ini+1)*(ini+2))%mod)/6;
aux=(ini*(ini+1))%mod;
aux=(aux*(ini+2))%mod;
sol = (sol-aux+ mod)%mod;
sol= (sol * exp(6 , mod - 2)) % mod;
sol= (sol * l) % mod;
ll x = (((h*l) % mod) * ((l-1 + mod) % mod)) % mod;
x = (x * exp(2 , mod - 2)) % mod;
sol = (sol - x + mod) % mod;

cout<<"Case #"<<i<<": "<<sol<<"\n";
}
    return 0;
}
