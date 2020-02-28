#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1111111;
typedef pair <int , int> par;
int cont;
bool mk[MAXN];
queue<par> cola;
vector <int> adl[MAXN];
int arr[MAXN];
vector<int> nodos;
bool mk1[MAXN];

int bfs(int nod)
{
   par ini; ini.first = nod; ini.second = 0;
   cola.push(ini);

   int may = 0;
   mk[ini.first] = true;

   while(!cola.empty())
   {
     par n = cola.front();
     cola.pop();
     for(int i = 0 ; i < adl[n.first].size() ; i++)
     {
      int nn = adl[n.first][i];
      if(!mk[nn])
      {
        mk[nn] = true;
        par np;
        np.first = nn;
        //cout<<adl[n.first].size()<<"\n";
        np.second = adl[n.first].size() + n.second;
        arr[np.first] = np.second;
        if(np.second > may)
        may = np.second;
        cola.push(np);
      }
     }
   }


 return may;
}
  int n , m , x;
  vector <int> sol;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    int ver = m;
    while(m--)
    {
       int a , b;
       cin>>a>>b;
       adl[a].push_back(b);

       if(!mk1[a])
       nodos.push_back(a);
       if(!mk1[b])
       nodos.push_back(b);

       mk1[a] = true; mk1[b] = true;

    }
       cin>>x;
       if(ver == 0 && n == 1)
       {
           cout<<0<<"\n";
           cout<<x<<"\n";
           //goto END;
       }
       else{
      int may = bfs(x);
       cout<<may<<"\n";
      for(int i = 0 ; i < nodos.size() ; i++)
      {
       if(arr[nodos[i]] == may)
       sol.push_back(nodos[i]);
      }
      sort(sol.begin() , sol.end());

      for(int i = 0 ; i < sol.size() ; i++) cout<<sol[i]<<" ";


       }
      END:
      cont++;

    return 0;
}
