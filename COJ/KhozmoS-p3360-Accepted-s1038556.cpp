#include <bits/stdc++.h>

using namespace std;
int n , m;
const int MAXN = 1111;


int ar[MAXN];
int dp[MAXN][MAXN];
int abi[MAXN];

void update(int pos)
{
    for(int i = pos ; i > 0 ; i -= i & -i)
      abi[i] += 1;
}

int sum(int x)
{
    int suma = 0;
    x++;

     for(int i = x ; i <= 220 ; i += (i & -i))
     suma += abi[i];


    return suma;
}

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);

    int n , q;
    cin>>n>>q;

     for(int i = 1 ; i <= n ; i++)
      cin>>ar[i];

     for(int i = 1 ; i < n ; i++){
       for(int j = i + 1 ; j <= n ; j++)
       {
         dp[i][j] = sum(max(ar[i] , ar[j]));
         update(ar[j]);
       }
       for(int i = 50 ; i <= 220 ; i++)
       abi[i] = 0;
     }
     while(q--)
     {
         int a,  b;
         cin>>a>>b;
         cout<<dp[a][b]<<"\n";
     }
    return 0;
}
