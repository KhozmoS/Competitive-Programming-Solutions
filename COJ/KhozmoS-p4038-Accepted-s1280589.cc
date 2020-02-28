#include<bits/stdc++.h>


using namespace std;

typedef long long ll;

const int MAX = 1e3+5;

#define PB push_back
#define db double

int N , G, P;
ll M;

struct gangsta{

    int a;
    int b;

    gangsta(int x, int y)
    {
        a = x;
        b = y;
    };



};

vector <gangsta> v;


bool ok(ll m)
{
    ll killed = 0;


    vector <ll> values;
    for(int i = 0 ; (i < G) ; i++)
        values.PB((ll)((m-v[i].a) / v[i].b));

    sort(values.begin() , values.end());
    reverse(values.begin() , values.end());

    int cnt = 0;
    for(int i = 0 ; ((i < G) && cnt<P) ; i++)
    {
        if(values[i]<=0) break;
        cnt++;
        killed += values[i];
    }

    return (killed >= N);
}
ll BS()
{
    ll in = 0;ll fn = 1000000000000;
    while(in+1<fn)
    {
        ll mt = (ll)(in+fn)/2ll;
        if(ok(mt))
            fn = mt;

        else in = mt;
    }

    return fn;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        v.clear();

        cin>>N>>G>>P;

        for(int i = 0 ; i < G ; i++)
        {
            ll x , y;
            cin>>x>>y;
            gangsta cur = gangsta(x ,y);
            v.PB(cur);
        }

        cout<<BS()<<"\n";
    }
}
