#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000005;
int n , m , R , E , cn , cm , ans , last;

vector <int> adl[MAX];
queue <int> cola;
int cost[MAX];
bool mk[MAX];
int bfs(int node)
{
    cn = 1; cm = 0;
    cost[node] = 1;
    int res = 1;
    cola.push(node);
    mk[node] = true;
    while(!cola.empty())
    {
        int nnode = cola.front();
        cola.pop();

        for(int i = 0 ; i < adl[nnode].size() ; i++)
        {
            int node = adl[nnode][i];
            if(!mk[node])
            {
                cost[node] = cost[nnode] + 1;
                res = max(res , cost[node]);
                mk[node] = true;
                cn++;
                cola.push(node);
                last = node;
            }
        }
    }
    return res;
}
int cont[MAX] , t;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while(t--){

      cin>>n;
      for(int i = 1; i < n ; i++)
      {
          int a , b;
          cin>>a>>b;

          adl[a].push_back(b);
          adl[b].push_back(a);
      }

      for(int i = 0 ; i <= n ; i++){ mk[i] = false; cost[i] = 0;}
      ans = bfs(1);
      for(int i = 0 ; i <= n ; i++){ mk[i] = false; cost[i] = 0;}
      ans = bfs(last);
      for(int i = 0 ; i <= n ; i++){ adl[i].clear();}
      cout<<ans<<"\n";
    }
    return 0;
}
