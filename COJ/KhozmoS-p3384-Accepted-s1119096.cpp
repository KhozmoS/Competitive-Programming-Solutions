#include <bits/stdc++.h>

using namespace std;

const int MAX = 1005;
int n , m , R , E , cn , cm , ans;

vector <int> adl[MAX];
queue <int> cola;
bool mk[MAX] , mmk[MAX][MAX];
void bfs(int node)
{
    cn = 1; cm = 0;
    cola.push(node);
    mk[node] = true;
    while(!cola.empty())
    {
        int nnode = cola.front();
        cola.pop();

        for(int i = 0 ; i < adl[nnode].size() ; i++)
        {
            int node = adl[nnode][i];
            if(!mmk[nnode][node] && !mmk[node][nnode]){
                cm++;
                mmk[nnode][node] = true;
                mmk[node][nnode] = true;
            }
            if(!mk[node])
            {
                mk[node] = true;
                cn++;
                cola.push(node);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>R>>E;
      while(m--)
      {
          int a , b;
          cin>>a>>b;

          adl[a].push_back(b);
          adl[b].push_back(a);
      }

      for(int i = 1 ; i <= n ; i++)
      {
          if(!mk[i])
          {
            //  cout<<i<<"\n";
              bfs(i);
           //   cout<<cn<<" "<<cm<<"\n";
              ans += min(cn * E , ((cn * (cn - 1) / 2) - cm) * R);
          }
      }
      cout<<ans<<"\n";
    return 0;
}
