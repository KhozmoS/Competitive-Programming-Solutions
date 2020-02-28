#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;
const int mod = 1000000007;

long long F[MAXN];
void prec()
{
 F[0] = 3; F[1] = 11;

  for(int i = 2 ; i < MAXN ; i++)
   F[i] =(((2 * F[i - 1]) % mod) + ((3 * F[i - 2]) % mod)) % mod;

}

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   prec();
    int t;
    cin>>t;
    while(t--)
    {
      int N;
      cin>>N;
      cout<<F[N]<<"\n";
    }

    return 0;
}
