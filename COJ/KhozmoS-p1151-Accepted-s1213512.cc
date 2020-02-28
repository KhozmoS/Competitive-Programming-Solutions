#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n , a , b , t;

vector <int> fact(int x)
{
    vector <int> res;
    for(int i = 2 ; i * i <= x ; i ++)
    {
        int p = i;
        if(x % p == 0)
        {
            while(x%p==0) x/=p;
            res.push_back(p);
        }
    }
    if(x-1) res.push_back(x);
    return res;
}
int F(int x)
{
    vector <int> p;
    p = fact(n);
    int sz = p.size();
    int res = 0;
    for(int mask = 1 ; mask < (1<<sz) ; mask++)
    {
        int prod = 1;
        int cnt = 0;
        for(int i = 0 ; i < sz ; i++)
            if((1<<i)&mask)
                cnt++ , prod *= p[i];

        if(cnt&1)
            res += (x/prod);
        else
            res -= (x/prod);
    }
    return x-res;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
        if(a==1&&b==1) cout<<1<<"\n";
        else if(a<=1) cout<<F(b)<<"\n";
        else
        cout<<F(b)-F(a-1)<<"\n";
    }

}
