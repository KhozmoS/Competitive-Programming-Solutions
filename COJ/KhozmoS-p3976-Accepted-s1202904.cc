#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005];
int ans;string a , b;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>a>>b;
    int sz = a.size();
    for(int i = 0 ; i < sz ; i++)
    {
        if(a[i] != b[i])
            swap(a[i] , a[sz-i-1]), ans++;
    }
    if(a == b) cout<<ans<<"\n";
    else cout<<"impossible\n";
}
