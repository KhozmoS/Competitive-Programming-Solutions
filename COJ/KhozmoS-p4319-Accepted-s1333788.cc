#include <bits/stdc++.h>

using namespace std;


#define f first
#define s second
#define pb push_back
#define db double
#define sz(c) (c).size()
#define all(c) (c).begin(),(c).end()

typedef long long ll;
typedef pair <int , int > ii;
typedef pair <ii , int > iii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef vector <vii> vvii;

const ll mod = 1e9+5;
const int MAX = 1e6+5;

int mx;int mn = 1e9+5;
int dp[MAX];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4 ; i < MAX ; i ++)
    {
        dp[i] = dp[i-1 ] + 3;
    }
    int n;cin>>n;
    while(n--) {
        int x;cin>>x;
        cout<<dp[x]<<"\n";
    }

}
