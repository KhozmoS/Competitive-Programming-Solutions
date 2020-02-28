#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int F(ll x)
{
    if(x == 0) return 0;
    if(x == 1) return 1;
    if(x == 2 || x == 3) return 2;
    if(x == 4 || x == 5) return 3;

    return F(x/12ll);
}
int t , n;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int xr = 0;
        ll x;
        while(n--)
        {
            cin>>x;
            xr ^= F(x);
        }
        if(xr) cout<<"Henry\n";
        else cout<<"Derek\n";
    }
}
