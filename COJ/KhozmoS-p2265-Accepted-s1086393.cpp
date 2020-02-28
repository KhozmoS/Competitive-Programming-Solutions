#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second
typedef long long ll;
ll  n , po;
ll ar[25];

bool F(int pos , ll sum)
{
    if(sum == po) return true;

    if(pos == n) return false;

    return F(pos + 1 , sum + ar[pos]) || F(pos + 1 , sum);
}
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>po;

    for(int i = 0 ; i < n ; i++) cin>>ar[i];

    cout<<(F(0 , 0) ? "YES\n" : "NO\n");
    return 0;
}
