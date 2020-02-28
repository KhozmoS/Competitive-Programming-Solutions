#include <bits/stdc++.h>

using namespace std;

const int MAX =  505;
const int mod =  1000000007;
typedef long long ll;
ll p[MAX][MAX];

void PASCAL()
{
 for(int i = 0 ; i < MAX ; i++)
    for(int j = 0 ; j <= i ; j++)
     p[i][j] = 1;

  for(int i = 1 ; i < MAX ; i++)
    for(int j = 1 ; j <= i ; j++)
     p[i][j] = (p[i - 1][j - 1] + p[i - 1][j]) % mod;
}

int main()
{
 ios_base::sync_with_stdio();cin.tie(0);
    PASCAL();
     int t;
     cin>>t;
     while(t--)
     {
         int n , k;cin>>n>>k;

         cout<<p[n + k - 1][k - 1]<<"\n";
     }

    return 0;
}
