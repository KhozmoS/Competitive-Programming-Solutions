#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
const int MAX = 1e6 + 5;

ll h[MAX] , h2[MAX];
ll bas = 311;
ll P[MAX];

ll calc(int a , int b)
{    //cout<<a<<" "<<b<<"\n";
    return (h[b] - (h[a-1]* P[b-a+1]) % mod + mod) % mod;
}


int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  int t;cin>>t;

  for(int cas = 1 ; t-- ;cas++){

  string A , B;
  cin>>A>>B;
  int sza = A.size();
  int szb = B.size();
  A = " " + A;
  B = " " + B;


  P[0] = 1;
  h[0] = 0;

  for(int i = 1 ; i <= sza ; i++){
        P[i] = (bas * P[i-1]) % mod;
        h[i] = (h[i - 1] * bas + (A[i] - 'a' + 1)) % mod;
  }
  h2[0] = 0;
  //cout<<szb<<"\n";
  for(int i = 1 ; i <= szb ; i++)
     h2[i] = (h2[i - 1] * bas + (B[i] - 'a' + 1)) % mod;

  int ans = 0;

  for(int i = 1 ; i <= (sza - szb + 1); i++)
      if(h2[szb] == calc(i , i + szb -1)){
         ans++;//cout<<i<<"\n";
      }
   cout<<"Case "<<cas<<": "<<ans<<"\n";
  }
}
