#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e5;
int n , q;
typedef long long ll;
ll ac[MAX];

void update(int p , ll v)
{
    for(; p < MAX ; p += (p & -p))
        ac[p] += v;
}
ll query(int p)
{
    ll res = 0;
    for(; p > 0 ; p -= (p&-p))
        res += ac[p];
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q;
    for(int i = 1 ; i <= n ; i++) {ll x;cin>>x;
        update(i , x);
    };
    while(q--)
    {
        int typ , a , b;
        cin>>typ>>a>>b;
        if(typ == 1){
            update(a , (ll)b);
            cout<<1<<" "<<query(a)-query(a-1)<<"\n";
        }
        else if(typ&1)
            cout<<"Error\n";
        else{
            if(a > b) swap(a,b);
            cout<<typ<<" "<<query(b)-query(a-1)<<"\n";
        }
    }
}
