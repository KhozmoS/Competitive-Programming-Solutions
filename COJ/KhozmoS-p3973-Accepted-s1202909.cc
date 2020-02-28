#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005];
int ans;string a , b;
map <string , int> mp;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>a;int sz = a.size();
    for(int i = 0 ; i < sz ; i++){
        b = "";
        for(int j = i ; j < sz ; j++)
        {
            b += a[j];
            mp[b]++;
        }
    }
    for(map <string , int> :: iterator it = mp.begin() ; it != mp.end() ; it++)
    {
        if(it->second > 1)
            ans = max((int)(it->first).size() , ans);
    }
    cout<<ans<<"\n";
}
