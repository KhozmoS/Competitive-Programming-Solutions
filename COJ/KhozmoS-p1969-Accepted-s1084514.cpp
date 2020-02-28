#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second

typedef long long ll;
typedef pair <ll , ll> par;
const int MAX = 2005;
par dp[MAX];

char F(int x , int nv)
{
    int mit = (dp[nv].f / 2) - (dp[nv].s / 2);
    int ls = mit + dp[nv].s;

    if(mit < x && ls > x){
        if(mit + 1 == x)
            return 'm';

        return 'o';
    }
    if(x > ls)
       x -= ls;

    return F(x , nv - 1);
}

int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 ll ini = 3;

  for(int i = 1 ; i < MAX; i++){
    dp[i].s = ini;
    dp[i].f = (dp[i - 1].f * 2) + (ini++);
  }
  //cout<<dp[1].f<<" "<<dp[1].s<<"\n";
   //cout<<dp[4]<<"\n";
   int n , ni;
   cin>>n;
   for(int i = 1 ; i < MAX ; i++){
      if(dp[i].f >= n)
      {
          ni = i;
          break;
      }
   }
  //cout<<ni<<"\n";
   cout<<F(n , ni)<<"\n";
    return 0;
}
