#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 7;

int N , K;
vector<int> adl[MAX];
queue <int> cola;
bool mk[MAX];
int G[MAX];

void bfs(int nod)
{
    mk[nod] = true;
    cola.push(nod);
    while(!cola.empty())
    {
     nod = cola.front();
     cola.pop();
     for(int i = 0 ; i < adl[nod].size() ; i++)
     {
       int nn = adl[nod][i];
       if(!mk[nn])
       {
        cola.push(nn);
        mk[nn] = true;
       }
     }
    }
}
void ordenar(int x)
{
    mk[x] = true;
    for(int i = 0 ; i < adl[x].size() ; i++)
     if(!mk[adl[x][i]])
     ordenar(adl[x][i]);

    G[K--] = x;
}
int main()
{
 ios_base::sync_with_stdio();cin.tie(0);
    int t;
     cin>>t;
     while(t--)
     {
       int M;

       cin>>N>>M;
       for(int i = 1 ; i <= N ; i++)
       {
        adl[i].clear();
        mk[i] = false;
       }
       while(M--)
       {
         int a , b; cin>>a>>b;
         adl[a].push_back(b);
       }
       K = N;
       memset(mk , false , sizeof(mk));
       for(int i = 1 ; i <= N ; i++)
        if(!mk[i])
        ordenar(i);
        int sol = 0;
       memset(mk , false , sizeof(mk));
        for(int i = 1 ; i <= N ; i++)
         if(!mk[G[i]])
        {
          bfs(G[i]);
          sol++;
        }
        cout<<sol<<"\n";
     }

    return 0;
}
