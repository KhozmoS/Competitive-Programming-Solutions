#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second
typedef pair<int, int> par;
typedef vector<int> vec;

const int MAX = 1000;
const int INF = 1000000000;
int C[MAX];


vector<par> adl[MAX];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int V, E, Q , D , t , a , b , x;
    cin>>t;
    while(t--){
        cin>>V;

        for(int i = 0; i < V; i++)
            cin>>C[i];

        cin>>E;

        for(int i = 0; i < E; i++){
            cin>>a>>b;
            a--, b--;
            D = (C[b] - C[a]);
            D = D * D * D;
            adl[a].push_back(par(b, D));
        }
     int dis[V];
     fill(dis , dis + V , INF);
     dis[0] = 0;

      for (int i = 0; i < V - 1; i++)
       for (int u = 0; u < V; u++)
         for (int j = 0; j < adl[u].size(); j++){
          par v = adl[u][j];
          dis[v.f] = min(dis[v.f], dis[u] + v.s);
         }
         for(int k = 0; k < V; k++)
           for(int j = 0; j < adl[k].size(); j++)
             par v = adl[k][j];
         cin>>Q;
        
        while(Q--){
            cin>>x;
            x--;
            if(dis[x] == INF || dis[x] < 3)
                cout<<"?\n";
            else
                cout<<dis[x]<<"\n";
        }
        //LIMPIAR
        for(int i = 0; i < V; i++)
            adl[i].clear();
    }

    return 0;
}
