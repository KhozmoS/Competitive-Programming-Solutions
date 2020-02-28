#include <bits/stdc++.h>

using namespace std;


#define f first
#define s second
#define pb push_back
#define db long double
#define sz(c) (c).size()
#define all(c) (c).begin(),(c).end()

typedef long long ll;
typedef pair <int , int > ii;
typedef pair <ii , int > iii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef vector <vii> vvii;

const ll mod = 1e9+7;
const int MAX = 1e6+5;
const int mx[] = {0,1,1,1,0,-1,-1,-1};
const int my[] = {1,1,0,-1,-1,-1,0,1};


ll dp[505];

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--){
      memset(dp , 0 , sizeof(dp));
      ll c , v , l , k;
      cin>>c>>v>>l>>k;
      dp[0] = 1;
      bool ok = false;
      for(int i = 1 ; i <= l ; i++) {
        dp[i] = (dp[i] + (v*dp[i-1]%mod));
        if(dp[i] >= k) ok = true;
        dp[i] %= mod;
        dp[i+1] = (dp[i-1] * (c*v%mod));
        if(i+1<=l && dp[i+1]>=k) ok = true;

        dp[i+1]%=mod;
      }
      cout<<dp[l]<<" "<<(ok?"Accepted":"Rejected")<<"\n";

    }
}
