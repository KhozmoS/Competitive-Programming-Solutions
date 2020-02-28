#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;


ll a , b , p;

ll F(ll x)
{
    ll res = 0;
    while(x)
        x /= p,
        res += x;

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin>>a>>b>>p)
         cout<<oct<<F(b)-F(a-1)<<"\n";
}
