#include<bits/stdc++.h>


using namespace std;

typedef long long ll;
const int MAX = 1005;
const ll mod = 1000000007;

int n , x;

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  bool ans = true;
  for(int i = 1 ; i <= n ; i++){
     cin>>x;

         int c = 0;
     for(int i = 2 ; i * i <= x ; i++)
     {
         if(x % i == 0)
         {
             while(!(x % i))
               x /= i;
            c++;
         }
     }
     if(x - 1)
        c++;

     if(c < 3) ans = false;

  }
  cout<<(ans ? "YES\n" : "NO\n");
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

