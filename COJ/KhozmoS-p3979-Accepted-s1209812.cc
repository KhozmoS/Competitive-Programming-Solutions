#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define PB push_back


typedef long long ll;
typedef vector <int> vi;

const int MAX = 1e6;

const ll mod = 1e9+7;
int ar[MAX];
int m , n;


int dp[1005][1005];

bool f(int p , int res)
{
    if(p == n)
    {
        //cout<<p<<" "<<n<<"\n";
        if(res==0) return true;
        return false;
    }

    if(dp[p][res] != -1) return dp[p][res];

    dp[p][res] = f(p+1 , (res+ar[p])%m);
    if(p) dp[p][res] |= f(p+1 , (res-ar[p]+m)%m);

    return dp[p][res];
}

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dp , -1 , sizeof(dp));
    cin>>n>>m;
    for(int i = 0 ; i < n ; i++) cin>>ar[i];

    cout<<(f(0 , 0) ? "valid\n" : "invalid\n");
}
