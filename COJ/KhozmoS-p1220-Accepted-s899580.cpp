//APRENDIENDO BFS
#include <bits/stdc++.h>
#define MAXN 2007
using namespace std;
vector <int> adl[MAXN];
queue<int>cola;
int n , m , a , b , w;
int bfs(int nodo)
{

    bool mk[MAXN];
    for(int i = 0 ; i <= n ; i++)mk[i] = 0;
    int cont = 0;
   cola.push(nodo);
   mk[nodo] = true;
    while(!cola.empty())
    {
       int nod = cola.front();
       cola.pop();
       cont++;
       for(int i = 0 ; i < adl[nod].size() ; i++)
       {
           int nn = adl[nod][i];
          // cout<<nn<<"\n";
           if(!mk[nn]){
            mk[nn] = true;
            cola.push(nn);
           }
       }
    }
    return cont;
}
bool sol()
{
    bool flag = true;
    for(int i = 1 ; i <= n ; i++)
    {
        if(bfs(i) != n)flag = false;
    }
    return flag;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int cont;
    while(cin>>n>>m,n && m){
     for(int i = 0 ; i < m ; i++)
     {
         cin>>a>>b>>w;
         if(w == 1)
           adl[a].push_back(b);
         else{
           adl[a].push_back(b);
           adl[b].push_back(a);
         }
     }
     /*for(int i = 1 ; i <= n ; i++)
     {
          cont = bfs(i);
     }*/
     cout<<sol()<<"\n";
     for(int i = 1 ; i <= n ; i++)adl[i].clear();
    }
    return 0;
}
