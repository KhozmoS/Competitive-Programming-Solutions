#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;ll ans = 0;
ll ac = 0;

int f(int x)
{
    if(x&1) return 0;

    return f(x>>1)+1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    ans = 1;
    ac = 1;
    if(n==1)
    {
        cout<<0<<"\n";
        return 0;
    }
    for(int i = 4 ; i <= n+1 ; i += 2)
    {
        ans += ac;
        if(i<=n){
            ac += (ll)f(i);
            ans += ac;
        }
    }
    cout<<ans<<"\n";
}
