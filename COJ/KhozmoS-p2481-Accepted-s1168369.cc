#include <bits/stdc++.h>

using namespace std;
#define PB push_back
typedef vector <int> VI;
typedef long long ll;

ll dp[20][200];

ll ans_min , a , b;

ll exp(ll b , ll e)
{
    if(e == 0) return 1ll;
    if(e == 1) return b;

    ll mt = exp(b , e>>1);

    return (e&1 ? mt * mt * b : mt*mt);
}
ll F(int c , int res , ll num)
{
    if(res < 0) return 0;
    ll mini = num * exp(10 , 15 - c);
    ll maxi = mini + exp(10 , 15 - c) - 1;
    if(mini > b || maxi < a) return 0;

    if(c == 15)
    {
        if(res != 0) return 0;
        if(!ans_min) ans_min = num;
        return 1ll;
    }
    bool ok = (mini >= a && maxi <= b);
    
    if(dp[c][res] != -1 && ok) return dp[c][res];

    ll r = 0;
    for(int i = 0 ; i <= 9 ; i++)
        r += F(c+1 , res - i , num*10ll + (ll)i);

    return (ok ? dp[c][res] = r : r);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dp , -1 , sizeof(dp));
    int s;
    cin>>a>>b>>s;
    cout<<F(0 , s , 0)<<"\n";
    cout<<ans_min<<"\n";
}
