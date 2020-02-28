#include <bits/stdc++.h>

using namespace std;
#define PB push_back
typedef vector <int> VI;
typedef long long ll;
const int MAX = (1e3+5) * 2;
int ar[MAX];
bool mk[10000005];

void criba()
{
    for(int i = 2 ; i * i < 10000005 ; i++)
        if(!mk[i])
          for(int j = i * i ; j < 10000005 ; j += i)
            mk[j] = true;
}
int id;
VI a , b;
bool ok(int x)
{
    bool flag1 = false;
    int num = x;
    a.clear();
    b.clear();
    id = 0;
    while(num)
    {
        a.PB(num%10);
        num /= 10;
        id++;
    }
    b = a;
    reverse(b.begin() , b.end());
    flag1 = (a == b);

    return (flag1&&!mk[x]);
}
int idx;
void build()
{
    for(int i = 2 ; i <= 10000000 ; i++)
        if(ok(i)) ar[idx++] = i;
}
const ll mod = 1e9+7;
ll exp(ll base , ll expo)
{
    ll res = 1ll;
    while(expo)
    {
        if(expo&1){res = (base * res) % mod;}
        expo >>= 1ll;
        base = (base * base) % mod;
    }
    return res;
}
int dp[MAX][MAX];

int main()
{
    criba();
    build();
    ar[idx++] = 10000005; 
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    for(int i = 0 ; i < MAX ; i++)
        dp[i][1] = i;
    for(int i = 1 ; i < MAX ; i++)
         for(int j = 2 ; j <= i ; j++)
             dp[i][j] = (dp[i-1][j] + dp[i-2][j-1]) % mod;
    //cout<<dp[3][2]<<"\n";
    while(t--)
    {
        int x , y;int k;
        cin>>x>>y>>k;
        y = upper_bound(ar , ar + idx , y) - ar;
        x = lower_bound(ar , ar + idx , x) - ar;
        int n = y - x;
        //cout<<n<<"\n";
        if(k > (n/2) + (n&1) || !k){cout<<"0\n"; continue;}

        cout<<dp[n][k]<<"\n";
    }
}
