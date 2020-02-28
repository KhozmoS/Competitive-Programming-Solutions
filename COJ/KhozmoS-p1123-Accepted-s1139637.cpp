#include<bits/stdc++.h>


using namespace std;

typedef long long ll;
const int MAX = 1005;
const ll mod = 1000000007;

int n , x;
ll dp[30000];
map <ll , bool> m;
ll pr[3] = {2 , 3 , 5};
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int cant = 1;
  int ant = cant;

  dp[1] = 1;



    for(int j = 1 ; cant <= 2000; j++){
     for(int i = 0 ; i < 3 ; i++)
       if(!m[dp[j] * pr[i]]){
        dp[++cant] = dp[j] * pr[i];
         m[dp[j] * pr[i]] = true;
       }
      sort(dp + 1 , dp + cant + 1);
  }




  int n;
  while(cin>>n && n) cout<<dp[n]<<"\n";


}

/*
11 12 22 21
1
2
i = L , long de la sub
j = n , los num del dom
k = la dif valida

i = 1
j = 1 2 3 ... n
dp[i][j] = dp[i - 1][j - k] + dp[i - 1][(j - k) + 1] + ... + dp[i - 1][j + k]
1 2
*/
// n = 5 k = 2 l = 3
// n

