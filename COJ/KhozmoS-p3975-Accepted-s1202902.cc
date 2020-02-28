#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    string a , b;
    cin>>b;int sz = b.size();
    a = " " + b;
    reverse(b.begin() , b.end());
    b = " " + b;
    for(int i = 1 ; i <= sz; i++)
        for(int j = 1 ; j <= sz ; j++)
            dp[i][j] = (a[i] == b[j] ? dp[i-1][j-1] + 1 : max(dp[i][j-1] , dp[i-1][j]));

    cout<<sz-dp[sz][sz]<<"\n";
}
