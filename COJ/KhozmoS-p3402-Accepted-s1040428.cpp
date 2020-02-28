#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5005;

typedef pair <int , int> par;
int lis[MAXN];
vector <par> ta[MAXN];
par comp[MAXN];
int posc[MAXN];
int n , m , b;


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>n>>m>>b;

    for(int i = 1 ; i <= n ; i++)
        cin>>lis[i];

    for(int i = 1 ; i < m ; i++)
    {
        int y , p , q; cin>>y>>p>>q;

        par s; s.first = p; s.second = q;
        ta[y].push_back(s);
    }
    for(int i = 1 ; i <= n ; i++)
    {
        sort(ta[lis[i]].begin() , ta[lis[i]].end());
        comp[lis[i]] = ta[lis[i]][0];
        b -= comp[lis[i]].first;
    }
  //  int sol;
    if(b < 0){
     cout<<"No task.\n";
     return 0;
    }
      while(true)
      {
        int men = 111111111;
        int id;
        for(int i = 1 ; i <= n ; i++)
        if(comp[lis[i]].second < men)
        {
            men = comp[lis[i]].second;
            id = lis[i];
        }
        bool flag = false;
        for(int i = posc[id] ; i < ta[id].size() ; i++)
        {
            if(ta[id][i].second > comp[id].second)
            {
              if((b + comp[id].first) - ta[id][i].first >= 0)
              {
                  b = (b + comp[id].first) - ta[id][i].first;
                  comp[id] = ta[id][i];
                  posc[id] = i;
                  flag = true;
              }
            }
          if(flag) break;
        }
        if(!flag)
          break;
      }
      int men = 111111111;
       for(int i = 1 ; i <= n ; i++)
        if(comp[lis[i]].second < men)
        {
            men = comp[lis[i]].second;
        }
     cout<<men<<"\n";
    return 0;
}
