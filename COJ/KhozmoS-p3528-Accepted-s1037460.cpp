#include <bits/stdc++.h>

using namespace std;
const int MAXN = 55;
const int MOD  = 1000000007;
typedef long long ll;

int N , M , Q;
vector <int> adl[MAXN];
ll mat[MAXN][MAXN];
ll mato[MAXN][MAXN];

void mult()
{
    ll cop[MAXN][MAXN];
    for(int i = 1 ; i <= N ; i++)
    {
      ll sum = 0;
      for(int k = 1 ; k <= N ; k++){
        sum = 0;
      for(int j = 1 ; j <= N ; j++)
      {
        sum += mat[i][j] * mato[j][k];
        sum %= MOD;
      }
      cop[i][k] = sum;
      }
    }
    for(int i = 1 ; i <= N ; i++)
      for(int j = 1 ; j <= N ; j++)
        mat[i][j] = cop[i][j];
}

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   //dp[1]++;
   //ar[1]++;
   cin>>N>>M;
   for(int i = 0 ; i < M ; i ++)
   {
       int a , b;
       cin>>a>>b;

       adl[a].push_back(b);
   }
   cin>>Q;
    for(int i = 1 ; i <= N ; i++)
    for(int j = 0 ; j < adl[i].size() ; j++){
       mat[i][adl[i][j]]++;
       mato[i][adl[i][j]]++;
    }
    Q--;
    while(Q--)
      mult();

    cout<<mat[1][N]<<"\n";
    /*    for(int i = 1 ; i <= N ; i++){
          for(int j = 1 ; j <= N; j++)
            cout<<mato[i][j]<< " ";
         cout<<"\n";
        }*/
    return 0;
}
