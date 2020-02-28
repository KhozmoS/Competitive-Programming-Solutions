#include <bits/stdc++.h>

using namespace std;
#define PB push_back
int n;
map <int , vector <int> > v;
map <int , bool> mk;

void bfs(int node)
{
    mk[node] = true;
    queue <int> q;
    q.push(node);
    while(!q.empty())
    {
        node = q.front();
        q.pop();

        for(int i = 0 ; i < v[node].size() ; i++)
        {
            int x = v[node][i];
            if(mk.find(x) == mk.end())
            {
                q.push(x);
                mk[x] = true;
            }
        }
    }
}
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n;
   for(int i = 1 ; i <= n ; i++)
   {
       int x, r;
       cin>>x>>r;
       v[x-r].PB(x+r);
       v[x+r].PB(x-r);
   }
   int c = 0;
   for(map <int , vector<int> > :: iterator it = v.begin() ; it!=v.end() ; ++it)
   {
       int node = it->first;
       if(mk.find(node) == mk.end())
       {
           bfs(node);
           c++;
       }
   }
   cout<<2*n+c+1-v.size()<<"\n";
}
