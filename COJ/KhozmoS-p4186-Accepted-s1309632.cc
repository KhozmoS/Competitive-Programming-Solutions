#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define sz(c) (c).size()
#define db double
#define all(c) (c).begin(),(c).end()
#define present(x,c) ((c).find(x)!=(c).end())

typedef long long ll;
typedef pair <int , int >ii;
typedef pair <ii , int> iii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef vector <vii> vvii;

const ll mod = 1e9+7;
const int MAX = 1e6+7;

int dp[1000];

ll f(ll x , ll deep , ll border)
{
    if(x<=2) return 0;
    ll nwb;
    if(x&1)
    {
        nwb = (deep+border)*2ll;
    }
    else nwb = (border*2ll);
    return deep*((ll)x/2-1)+f(x/2,deep*4ll,nwb)+(x&1?border:0);
}
int main()
{

    ll x;cin>>x;
    cout<<f(x,1,1)<<"\n";
}
