#include <bits/stdc++.h>

using namespace std;


const int MAX = 1e5+5;
const int MAXN = 20;

#define pb push_back

int t , n , m , s , k;

string cad;


bool F[MAXN];
int dp[(1<<18)][26];

int resp[20][26];

int main()
{
    cad.reserve(MAX);
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while( t-- ) {
        memset(F , 0 , sizeof(F));
        memset(dp , 0 , sizeof(dp));
        memset(resp , 0 , sizeof(resp));


        cin>>n>>m>>s>>k;

        for(int i = 1 ; i <= s ; i++)
        {
            char c;cin>>c;
        }
        for(int i = 1 ; i <= k ; i++)
        {
            int x;cin>>x;
            F[x] = true;
        }

        for(int i = 0 ; i < m ; i++) {
            int x , y;
            char c;

            cin>>x>>y>>c;

            resp[x][c-'a'] |= (1<<y);

        }


        for(int mask = 1 ; mask < (1<<n) ; mask++) {

            for(int j = 0 ; j < n ; j++) {
                if(mask&(1<<j)) {
                    for(int l = 0 ; l < 26 ; l++) {
                        dp[mask][l] |= resp[j][l];
                    }
                }
            }
        }


        int q;
        cin>>q;

        while(q--) {

            cin>>cad;
            int mask = 1;
            for( int i = 0 ; i < cad.size() ; i++) {
                mask = dp[mask][cad[i]-'a'];
            }
            bool ans = false;
            for(int j = 0 ; j < n ; j++) {
                if(mask&(1<<j) && F[j]) {
                   ans = true;
                }
            }
             cout<<(ans ? "Yes\n" : "No\n");
        }
    }

}
