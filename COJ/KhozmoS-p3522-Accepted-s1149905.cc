#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX = 1e5 + 5;

const int maxn = 1e6;

ll n , a , ab[maxn];

void update(int pos)
{
    for(int i = pos ; i < maxn ; i += (i & -i))
        ab[i] += 1ll;
}
ll query(int pos)
{
    ll res = 0;
    for(int i = pos ; i > 0 ; i ^= (i & -i))
        res += ab[i];

    return res;
}
ll DS(int x)
{
    if(x == 1) return 0;
    ll res = 1;
    for(int i = 2 ; i * i < x ; i++)
        res += (!(x%i) ? i + (x / i) : 0);
    int sqr = (int)sqrt(x);

    return (res + (ll)(sqr * sqr == x ? sqr : 0));
}
ll ar[MAX];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>n;
    ar[0] = MAX;
    for(int i = 1 ; i <= n ; i++){
        cin>>a;
        int ds = DS(a);
        if(ds == a)
            ar[i] = 0;
        else
        ar[i] = (DS(a) >= a ? 1 : -1);
        ar[i] += ar[i - 1];
    }

    ll ans = 0;
    for(int i = n ; i >= 0 ; i--)
    {
       ans += query(maxn - 100) - query(ar[i] - 1);

       update(ar[i]);

    }
    cout<<ans<<"\n";
}
