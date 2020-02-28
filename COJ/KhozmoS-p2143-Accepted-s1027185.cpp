#include <bits/stdc++.h>

using namespace std;
const int MAXN = 10005;

int N , M , solucion;

int cost[MAXN] , val[MAXN] , sol[MAXN];
bool mk[MAXN];

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
   cin>>N>>M;

    for(int i = 1 ; i <= N ; i++)
    cin>>cost[i]>>val[i];


   int solu = -1;  mk[0] = true;

   for(int i = 1 ; i <= N ; i++)
   for(int j = M - cost[i] ; j >= 0 ; j--)
   {
       if(mk[j])
       {
        mk[j + cost[i]] = true;
        sol[j + cost[i]] = max(sol[j + cost[i]] , sol[j] + val[i]);

        solu = max(solu , sol[j + cost[i]]);
       }
   }
   solucion += solu;
   solu = 0;
   memset(mk , false , sizeof(mk));
   memset(sol , 0 , sizeof(sol));
}
cout<<solucion<<"\n";
    return 0;
}
