#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;

int cost[MAXN];
bool mk[MAXN];
queue<int> cola;
vector<int> adl[MAXN];

int t , n , m , q , a , b;

void bfs()
{
    for(int i = 0 ; i <= n ; i++){cost[i] = -1; mk[i] = false;}
    mk[1] = true;
    cola.push(1);
    cost[1] = 1;

    while(!cola.empty())
    {
        int n = cola.front();
        cola.pop();

        for(int k = 0 ; k < adl[n].size() ; k++)
        {
            int nn = adl[n][k];



            if(!mk[nn])
            {   if(cost[nn] == -1)
                cost[nn] = cost[n] + 1;

                cola.push(nn);
                mk[nn] = true;
            }
        }
    }
     for(int i = 0 ; i <= n ; i++)
     adl[i].clear();

}

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>t;

   while(t--)
   {
       cin>>n>>m>>q;

       while(m--)
       {
           cin>>a>>b;
           adl[a].push_back(b);
       }
       bfs();
       while(q--)
       {
           int nod;
           cin>>nod;
           cout<<cost[nod]<<"\n";
       }
   }

   return 0;
}
