#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
map <int , bool> m;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(ll i = 2 ; i <= sqrt(1e9) ; i++)
    {
      ll pot = i * i;
      for(int j = 1 ; j <= 35 && pot <= 1e9; j++)
      {
       m[pot] = true;
       pot *= i;
      }
    }int t; cin>>t;

    while(t--)
    {
      int n; cin>>n;
      int ans = 0;
      for(int i = 1 ; i * i <= n ; i++)
      {
        if(n % i == 0)
        {
         if(m[n / i] && i * i != n){
         ans++;
        // cout<<n / i<<"\n";
         }
         if(m[i]){
         ans++;
        // cout<<i<<"\n";
         }
        }
      }
      cout<<ans<<"\n";
    }
}
