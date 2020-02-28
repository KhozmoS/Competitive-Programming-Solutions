#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define db double
#define sz(c) (c).size()
#define all(c) (c).begin(),(c).end()

typedef long long ll;
typedef pair < int , int > ii;
typedef pair < ii , int > iii;
typedef vector < int > vi;
typedef vector < ii > vii;
typedef vector < vi > vvi;
typedef vector < vii > vvii;

const ll mod = 1e9+7;
const int MAX = 1e6+5;

ll dp[MAX];
ll a[MAX];



int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    dp[1] = 1;

    for( int n = 1 ; n < MAX ; n++ ) {

        a[n] = 1 + a[n - a[a[n-1]]];
        dp[n] = dp[n-1] + a[n];

    }

    int t;
    cin>>t;
    while( t-- ) {
        int n;
        cin>>n;
        cout<<dp[n]<<"\n";
    }
}
