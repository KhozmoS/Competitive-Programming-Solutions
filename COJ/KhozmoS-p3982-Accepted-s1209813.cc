#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define PB push_back


typedef long long ll;
typedef vector <int> vi;


ll c1 , c2 , x , y;


bool ok(ll v)
{
    ll f1 = v/x;
    ll f2 = v/y;
    //cout<<f1<<" "<<f2<<"\n";
    ll tot = (v/(x*y));
    ll cnt = tot;
    //cout<<cnt<<"\n";
    f1 -= cnt;
    f2 -= cnt;
    ll ok1 = c1;
    ll ok2 = c2;
    ok1 -= f2;
    ok2 -= f1;
    if(ok1<0) ok1 = 0;
    if(ok2<0) ok2 = 0;
    if(v-f1-f2-cnt<0) return false;
    return (v-f1-f2-cnt >= (ok1+ok2));
}
ll f()
{
    ll in = 0; ll fn = 1e18;
    while(in+1ll<fn)
    {
        ll mt = (in+fn)>>1;

        if(ok(mt))
            fn = mt;
        else in = mt;
    }
    cout<<fn<<"\n";
}

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>c1>>c2>>x>>y;
   //cout<<ok(5)<<"\n";
   f();
}
