#include<bits/stdc++.h>
#define MAXN 105
typedef long long LL;
using namespace std;
typedef pair <LL , LL> par;
int n , t , p;
 queue <LL> cola;
 bool mk[MAXN];
 int cost[MAXN];
vector <par> adl[MAXN] ;
 LL dijk()
 {
     for(int i = 2 ; i <= n ; i++)cost[i] = 1000000000;
     cola.push(1);
     while(!cola.empty())
     {
       LL n = cola.front();
       //mk[n] = true;
       cola.pop();
       for(int i = 0 ; i < adl[n].size() ; i++)
       {
        par nn = adl[n][i];
        if(cost[nn.first] > (nn.second + cost[n]))
        cost[nn.first] = nn.second + cost[n];
        cola.push(nn.first);
       }
     }
     return cost[n];
 }
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>t;
   for(int i = 1 ; i < n ; i++)
    {
      cin>>p;
      par pu;
      pu.first = i + 1;
      pu.second = p;
      adl[i].push_back(pu);
      //adl[i].second.push_back(p);
    }
    for(int i = 0 ; i < t ; i++)
    {
      LL a , b;
      cin>>a>>b;
      par pu;
      pu.first = b;
      pu.second = 1;
      adl[a].push_back(pu);
    }
    cout<<dijk()<<"\n";
    //for(int i = 0 ; i <= n ; i++)
    //cout<<cost[i]<<"\n";
    return 0;
}
