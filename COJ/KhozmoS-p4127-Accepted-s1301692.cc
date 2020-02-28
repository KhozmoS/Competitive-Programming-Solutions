#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
map <ll , int> mp;
ll lvl[100] , n , k , q;
int ans;

void build()
{
    lvl[1] = 1;
    ll tmp = 1;
    for(int i = 2 ; lvl[i-1]<=n ; i++)
    {
        lvl[i] = lvl[i-1] + tmp;
        tmp *= k;
    }
}
void solve(ll x , int st)
{
    int l;
    for(l = 1 ; lvl[l] <= x ; ++l);
    --l;
    int dist = 0;
    while(lvl[l])
    {
        if(mp.find(x) != mp.end() && st && !ans){
            //cout<<x<<" "<<mp[x]<<"\n";
            ans = dist + mp[x];
        }
        mp[x] = dist;
        x = lvl[l-1] + (x-lvl[l])/k;
        dist++;
        --l;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k>>q;
    build();
    while(q--)
    {
        ll a , b;
        cin>>a>>b;
        ans = 0;
        mp.clear();
        solve(a , 0);
        solve(b , 1);
        cout<<ans<<"\n";
    }
}
