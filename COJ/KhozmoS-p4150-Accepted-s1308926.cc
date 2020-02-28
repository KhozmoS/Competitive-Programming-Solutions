#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

typedef long long ll;
int N,fin;
ll par,imp,sol,T[maxn],A[maxn],Dp;



int main()
{
  #ifdef acm
  freopen("a.in","r",stdin);
  #endif // acm
  ios_base::sync_with_stdio(0);
  cin.tie();

  cin >> N;

  for(int i=1;i<=N;i++)
    cin >> A[i] , ((i&1)?imp+=A[i]:par+=A[i])  , T[i]=T[i-1]+A[i];
  if(N&1)
    cout << imp << " " << par;
  else{
    imp=par=0;
    for(int i=N/2;i>=1;i--)
      {
          int ini=i, fin=N-i+1;
          if(ini&1){ imp+=A[ini],par+=A[fin];}
          else {par+=A[ini],imp+=A[fin];}

          if(ini+1==fin)
            Dp = A[ini]+A[fin];
          else{
            Dp=max( max(imp,par) , imp+par - Dp);
          }
      }

    ll sol = Dp;
    cout << sol << " " << T[N]-sol;
  }

}
