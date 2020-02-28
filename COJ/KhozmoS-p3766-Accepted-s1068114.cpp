#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 1005;
const int mod =  1000000007;
ll F[MAXN] , g[MAXN];



int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   F[1] = 1; g[2] = 1;
   F[2] = 2;
    for(int i = 3 ; i < MAXN ; i++)
    {
       g[i] = (F[i - 2] + g[i - 1]) % mod;
       F[i] = (F[i - 1] + F[i - 2] + (2 * g[i - 1])) % mod;
    }
    int t;
    cin>>t;
    while(t--)
    {
      int n;
      cin>>n;
      cout<<F[n]<<"\n";
    }

    return 0;
}
