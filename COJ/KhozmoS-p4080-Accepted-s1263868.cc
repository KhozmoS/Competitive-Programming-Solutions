#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e6+1;
int ab[MAX];
typedef long long ll;
int t;
ll C , T;

ll f(ll x)
{
    return (x*(x+1))/2ll;
}
bool ok(ll x)
{
   if(log10(x) + log10(T) > log10(C)) return true;
   return (((x*T)+f(T-1)) >= C);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //cout<<log10(100);
    cin>>t;
    while(t--)
    {
        cin>>C>>T;
        ll fn = 10000000000000000;
        ll in = 0;

        while(in+1<fn)
        {
            ll mt = (in+fn)>>1;

            if(ok(mt))
            {
                fn = mt;
            }
            else in = mt;
        }
        cout<<fn<<"\n";
    }


}