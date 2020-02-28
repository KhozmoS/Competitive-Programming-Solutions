#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e5+5;
int ar[MAX];
typedef unsigned long long ll;

ll calc_block(ll n)
{
    ll x;

    x = ((n - 1) * n * (n + 1)) / 3 / 2;
    return n + 4 * x;
}
ll n;

ll bin()
{
    ll in = 1; ll fn = 1e9;

    while(in + 1 < fn)
    {
       ll mt = (in + fn) >> 1;

       if(calc_block(mt) > n || calc_block(mt) <= 0)
           fn = mt;
       else
           in = mt;
    }

    return in;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;

    cout<<bin()<<"\n";


    return 0;
}
