#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5+5;


const int mx[] = {0 , 1, 1, 1, 0  , -1, -1, -1};
const int my[] = {1 , 1, 0, -1, -1, -1, 0, 1};
#define f first
#define s second
typedef pair <int , int> ii;


ii ar[MAX];
int dp[MAX];

void update(int x , int v) {
    for(;x < MAX ; x += (x&-x))
        dp[x] = max(dp[x],v);
}

int query(int x) {
    int res = 0;
    for(;x > 0 ; x -= (x&-x))
        res = max(dp[x],res);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;

    while(t--) {

        memset(dp , 0,sizeof(dp));

        int n;
        cin>>n;
        for(int i = 1 ; i <= n ; i++) {
            cin>>ar[i].f>>ar[i].s;
        }
        sort(ar+1 , ar+1+n);
        int ans = 0;

        for(int i = 1 ; i <= n ; i++) {
            int q = query( ar[i].s );
            ans = max( q+1,ans );
            update( ar[i].s,q+1 );
//            cout<<ar[i].s<<" "<<q<<"\n";
        }

        cout<<n-ans<<"\n";
    }

}
