//KhozmoS

#include<bits/stdc++.h>


using namespace std;

#define PB push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int , int> II;
typedef vector <int> VI;
typedef vector <II> VII;

const int MAX = 100;
int a , b;
VI adl[MAX];
ll dp[MAX][MAX][MAX] , ar[MAX];

int main()
{
   // cout<<F("0")<<"\n";
	//ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;for(int i = 1 ; i <= n ; i++)  cin>>ar[i];

    dp[0][0][0] = 1ll;
    for(int i = 1 ;i  <=  n ; i++)
       for(int v = 0 ; v < 70 ; v++)
            for(int sz = 1 ; sz <= 50 ; sz++){
               dp[i][(v ^ ar[i])][sz] += dp[i-1][v][sz-1];
               dp[i][v][sz-1] += dp[i-1][v][sz-1];
            }

    int sexhard = 0;
    ll ans = 0;

         for(int v = 0 ; v <= 69 ; v++)
            for(int sz = 1 ; sz <= 50 ; sz++)
            {
               if(sexhard < v/sz && dp[n][v][sz]){
                  ans = dp[n][v][sz];
                  sexhard = v/sz;
               }
               else if(sexhard == v/sz && dp[n][v][sz])
               {
                  ans += dp[n][v][sz];
               }
            }
    cout<<ans<<"\n";
}
