#include <bits/stdc++.h>

using namespace std;
const int maxn = 13;
#define len size()
bool dp[(1 << maxn)][5005];
string ar[maxn];

int main()
{

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;cin>>n;
    int sz = 0;
    for(int i = 0 ; i < maxn ; i++)
        ar[i].reserve(25);

    for(int i = 0 ; i < n ; i++){
        cin>>ar[i];
    }
    int ans = 0;

    string txt;
    cin>>txt;
    int lengt = txt.len;
    txt = " "+ txt;
    for(int k = 1 ; k <= lengt ; k++)
    {
        dp[0][k-1] = true;

        for(int i = 0 ; i < n ; i++){
            if(ar[i].len > k || ar[i] != txt.substr(k - ar[i].len + 1 , ar[i].len));
            else
            for(int mask = 0 ; mask < (1 << n) ; mask++)
                if(!(mask & (1<<i)))
                   dp[mask | (1<<i)][k] |= dp[mask][k - ar[i].len];
        }
    }
    for(int i = 1 ; i <= lengt ; i++)
        if(dp[(1<<n)-1][i]) ans++;

    cout<<ans<<"\n";
}