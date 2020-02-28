#include <bits/stdc++.h>

using namespace std;

#define c first
#define a second.first
#define f first
#define b second.second
#define PB push_back

const int MAX = 1e5 + 5;
typedef pair <long long , int> par;
typedef pair <int , par> trio;
typedef long long ll;
int p[MAX] , n , m , s , e ;
ll mod[MAX];
int ans;
bool ms[MAX];
vector <trio> arist;
vector <par> T[MAX];
vector <par> adl[MAX];
int find(int x)
{
    if(x == p[x]) return x;
    return p[x] = find(p[x]);
}
void dijstra()
{
    int q = 0;
    for(int i = 0 ; i < MAX ; i++) mod[i] = 1e18;
    priority_queue <par , vector <par> , greater <par> > Q;
    mod[s] = 0;
    Q.push(par(0 , s));
    while(!Q.empty())
    {
        int x = Q.top().second;
        ll y = Q.top().first;
        Q.pop();
        if( x == e) return;
        for(int i = 0 ; i < adl[x].size() ; i++)
        {
       //  q++;     
      //    if(q > 10000000) return;

          ll mo;
          if(adl[x][i].first < ans * 2)
          mo = (ll)(ans * 2) - adl[x][i].first;
          else mo = 0;
          int xx = adl[x][i].second;
          if((long long)mo + y >= mod[xx]) continue;
          //ms[xx] = true;

          mod[xx] = mo + y;
          Q.push(par(mod[xx] , xx));
        }
    }
}
bool mk[MAX];
int cost[MAX];
int BFS()
{
    for(int i = 0 ; i < MAX ; i++) cost[i] = MAX;
    queue <par> Q;

    Q.push(par(s , 0));
    mk[s] = true;

    while(!Q.empty())
    {
        par node = Q.front(); Q.pop();
        int xx = node.first;
        int yy = node.second;
        for(int i = 0 ; i < T[xx].size() ; i++)
        {
            int x = T[xx][i].first;
            int y = T[xx][i].second;
           // cout<<y<<"\n";
            if(mk[x]) continue;

            cost[x] = min(cost[xx] , y);
            Q.push(par(x , y));
            mk[x] = true;
        }
    }
    return cost[e];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    cin>>s>>e;
    for(int i = 0 ; i < m ; i++)
    {
        int x , y , z;
        cin>>x>>y>>z;
        adl[x].PB(par(z , y));
        adl[y].PB(par(z , x));
        trio w;
        w.c = z;
        w.a = x;
        w.b = y;
        arist.PB(w);
    }
    ans = MAX;
    for(int i = 1 ; i <= n ; i++) p[i] = i;
    sort(arist.begin() , arist.end());
    reverse(arist.begin() , arist.end());
    for(int i = 0 ; i < arist.size() ; i++)
    {
        int x = find(arist[i].a);
        int y = find(arist[i].b);
        int w = arist[i].a;
        int r = arist[i].b;
        if(x != y)
        {
            T[w].PB(par(r,arist[i].c ));
            T[r].PB(par(w,arist[i].c ));
            p[x] = y;
            //ans = min(ans , arist[i].c);
        }
    }
    ans = BFS();
    cout<<ans<<" ";
    dijstra();

    cout<<mod[e]<<"\n";
}
