/*#include <bits/stdc++.h>


using namespace std;

#define PB push_back

const int MAX = 1e5 + 3;

vector <int> T[MAX];
vector <int> adl[MAX];
int sz[MAX] , n , nh , m , dp[MAX];
bool mk[MAX];
void addEdge(int a , int b)
{
    adl[a].PB(b);
    adl[b].PB(a);
}
//Centroid decomposition code
void dfs(int node , int p)
{
    sz[node] = 1; nh++;
    for(auto x : adl[node])
    {
        if(mk[x] || x == p) continue;

        dfs(x , node);
        sz[node] += sz[x];
    }
}

int centroid(int node)
{
    for(auto x : adl[node])
    {
        if(mk[x] || sz[x] > sz[node]) continue;

        if(sz[x] > (nh >> 1)) return centroid(x);
    }

    return node;
}
void create(int node)
{
    mk[node] = true;

    for(auto x : adl[node])
    {
        if(mk[x]) continue;
        nh = 0;
        dfs(x , -1);
        int k = centroid(x);

        T[k].PB(node);

        create(k);
    }

}
//LCA code
int P[MAX][20] , lvl[MAX];
void build_LCA(int node)
{
    queue <int> Q;
    Q.push(node);
    lvl[node] = 1;

    while(!Q.empty())
    {
        node = Q.front();Q.pop();

        for(auto x : adl[node])
        {
            if(lvl[x]) continue;

            Q.push(x);
            P[x][0] = node;
            lvl[x] = lvl[node] + 1;
        }
    }
    for(int k = 1 ; (1 << k) <= n ; k++)
        for(int i = 1 ; i <= n ; i++)
           P[i][k] = P[P[i][k - 1]][k - 1];
}
int LCA(int a , int b)
{
    if(lvl[a] < lvl[b]) swap(a , b);

    int l = log2(lvl[a]);

    for(;l >= 0 ; l--)
    {
        if(lvl[a] - (1 << l) >= lvl[b])
            a = P[a][l];
    }
    if(a == b) return a;

    l = log2(lvl[a]);
    for(; l >= 0; l--)
    {
        if(P[a][l] != P[b][l])
        {
            a = P[a][l];
            b = P[b][l];
        }
    }
    return P[a][0];
}
int dist(int a , int b)
{
    int c = LCA(a , b);

    return lvl[a] + lvl[b] - (lvl[c] << 1);
}
//PROBLEM THINGS
void update(int node)
{
    queue <int> Q;Q.push(node);
    dp[node] = 0;
    while(true)
    {
        node = Q.front(); Q.pop();
        if(!T[node].size()) return;
        int x = T[node][0];
        dp[x] = min(dp[x] , dist(node , x) + dp[node]);
        Q.push(x);
    }
}
int query(int node)
{
    int in = node;
    queue <int> Q;Q.push(node);
    int res = dp[node];
    while(true)
    {
        node = Q.front(); Q.pop();
        if(!T[node].size()) return res;
        int x = T[node][0];
        res = min(res , dist(in, x) + dp[x]);
        Q.push(x);
    }
}
int main()
{
   for(int i = 0 ; i < MAX ; i++) dp[i] = MAX;
   ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>m;

   for(int i = 1 ; i < n ; i++)
   {
       int a , b;cin>>a>>b;

       addEdge(a , b);
   }
   dfs(1 , -1);
   int k = centroid(1);
   create(k);
   build_LCA(1);
   update(1);
   while(m--)
   {
       int ty , a;
       cin>>ty>>a;
       if(!(ty - 1))
       {
           update(a);
           continue;
       }

       cout<<query(a)<<"\n";
   }
}
*/
//KhozmoS


#include <bits/stdc++.h>

using namespace std;
#define PB push_back

const int MAX = 2e5 + 5;
int n , k , P[MAX][20] , lvl[MAX] , dpst[MAX];

vector <int> adl[MAX];
vector <int> party[MAX];

void build_LCA(int node)
{
    queue <int> Q;
    Q.push(node);
    lvl[node] = 1;

    while(!Q.empty())
    {
        node = Q.front();Q.pop();

        for(auto x : adl[node])
        {
            if(lvl[x]) continue;

            Q.push(x);
            P[x][0] = node;
            lvl[x] = lvl[node] + 1;
        }
    }
    for(int k = 1 ; (1 << k) <= n ; k++)
        for(int i = 1 ; i <= n ; i++)
           P[i][k] = P[P[i][k - 1]][k - 1];
}
int LCA(int a , int b)
{
    if(lvl[a] < lvl[b]) swap(a , b);

    int l = log2(lvl[a]);

    for(;l >= 0 ; l--)
    {
        if(lvl[a] - (1 << l) >= lvl[b])
            a = P[a][l];
    }
    if(a == b) return a;

    l = log2(lvl[a]);
    for(; l >= 0; l--)
    {
        if(P[a][l] != P[b][l])
        {
            a = P[a][l];
            b = P[b][l];
        }
    }
    return P[a][0];
}
int dist(int a , int b)
{
    int c = LCA(a , b);

    return lvl[a] + lvl[b] - (lvl[c] << 1);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>n>>k;
    int root;
    for(int i = 1 ; i <= n ; i++)
    {
        int a , b; cin>>a>>b;
        if(!b) root = i;
        else
        adl[b].PB(i);

        party[a].PB(i);
    }
    build_LCA(root);
    for(int j = 1 ; j <= k ; j++)
    {
        int mx = 0 , node = 0;
        for(int i = 0 ; i < party[j].size() ; i++)
        {
            int lv = lvl[party[j][i]];
            if(lv > mx){
                mx = lv;
                node = party[j][i];
            }
        }
        dpst[j] = node;
    }
    for(int j = 1 ; j <= k ; j++)
    {
        int ans = 0;
        for(int i = 0 ; i < party[j].size() ; i++)
            ans = max(ans , dist(dpst[j] , party[j][i]));
        cout<<ans<<"\n";
    }
}
