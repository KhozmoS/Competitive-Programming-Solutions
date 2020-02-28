#include <bits/stdc++.h>
#define MAXN 10005

using namespace std;
int t , n , m , l , z;
vector <int> adl[MAXN];
bool mk[MAXN];
queue <int> cola;
 int bfs (int nodo)
 {
     int cont = 0;
     if(!mk[nodo]){
     mk[nodo] = true;
     cola.push(nodo);
     }
      while(!cola.empty())
      {
          int n = cola.front();
          cola.pop();
          cont++;
         for(int i = 0 ; i < adl[n].size() ; i++)
         {
             int nn = adl[n][i];
              if(!mk[nn])
              {
                mk[nn] = true;
                cola.push(nn);
              }
         }
      }
      return cont;
 }
 int sol;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>t;
     while(t--)
     {
         cin>>n>>m>>l;
         for(int i = 0 ; i < m ; i++)
         {
             int a , b;
             cin>>a>>b;
             adl[a].push_back(b);
         }
         while(l--)
         {
           cin>>z;
           int sum = bfs(z);
               sol += sum;
         }
         cout<<sol<<"\n";
         //LIMPIAR
         for(int i = 0 ; i <= n ; i++)mk[i] = 0;
         for(int i = 0 ; i <= n ; i++)adl[i].clear();
         sol = 0;
      }
    return 0;
}
