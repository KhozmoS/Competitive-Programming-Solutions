#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define PB push_back


typedef long long ll;
typedef vector <int> vi;

int n , m;

const int MAX = 1e6;
vi adl[MAX];

int dp[MAX];
bool mk[MAX];
bool ok[MAX];

void bfs(int node)
{
    queue <int> cola;
    dp[node] = 1;
    cola.push(node);
    mk[node] = true;
    while(!cola.empty())
    {
        node = cola.front();
        cola.pop();
        for(int i = 0 ; i < adl[node].size() ; i++)
        {
            int nw = adl[node][i];
            if(mk[nw]) continue;
          //  cout<<nw<<"\n";
            dp[nw] = 3-dp[node];
            mk[nw] = true;
            cola.push(nw);
        }
    }
}
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);

   cin>>n>>m;
   while(m--)
   {
        int a, b;
        cin>>a>>b;;
        adl[a].PB(b);
        adl[b].PB(a);
        ok[a]= true;
        ok[b]= true;
   }


   for(int i =1 ; i <= n ; i++)
   {
         if(!ok[i])
         {
            cout<<"Impossible\n";
            return 0;
         }
        if(!mk[i]) bfs(i);
   }
   cout<<"Possible\n";
   for(int i = 1 ; i <= n ; i++)
   {
        cout<<dp[i]<<"\n";
   }
}
