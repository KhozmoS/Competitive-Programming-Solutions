#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll D , M , D1 , N , D2;
    cin>>D>>M>>D1>>N>>D2;
    //D*=2ll;
    ll ans = 0;
    if(D>=D1)
    {
        cout<<"-1\n";
        return 0;
    }
    ll p = D1-D;
    
    while(D>0&&M--)
    {
        D-=p;
        ans++;
        p*=2;
    }
    
    if(D2 <= D)
    {
        cout<<"-1\n";
        return 0;
    }
    p = D2-D;
    while(D>0&&N--)
    {
        D-=p;
        ans++;
        p*=2;
    }
    if(D>0)
    {
        cout<<"-1\n";
        return 0;
    }
    cout<<ans<<"\n";
}
