#include <bits/stdc++.h>

using namespace std;
#define PB push_back

const int MAX = 2e5 + 5;
int n , k , P[MAX][20] , lvl[MAX] , dpst[MAX];

vector <int> adl[MAX];
vector <int> party[MAX];

void build(int node)
{
    queue <int> Q;
    Q.push(node);
    lvl[node] = 1;

    while(!Q.empty())
    {
        node = Q.front(); Q.pop();

        for(auto x : adl[node])
        {
            if(lvl[x]) continue;

            P[x][0] = node;
            lvl[x] = lvl[node] + 1;
            Q.push(x);
        }
    }
    for(int l = 1 ; (1 << l) <= n ; l++)
         for(int i = 1 ; i <= n ; i++)
             P[i][l] = P[P[i][l - 1]][l - 1];

}

int LCA(int a , int b)
{
    if(lvl[a] < lvl[b]) swap(a , b);

    int l = log2(lvl[a]);

    for(int i = l ; i >= 0 ; i--)
    {
        if(lvl[a] - (1 << i) >= lvl[b])
            a = P[a][i];
    }
    if(a == b) return a;

    l = log2(lvl[a]);

    for(; l >= 0 ; l--)
        if(P[a][l] != P[b][l])
        {
           a = P[a][l];
           b = P[b][l];
        }
    return P[a][0];
}

int dist(int a , int b)
{
    int c = LCA(a , b);

    return lvl[a] + lvl[b] - (2 * lvl[c]);
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
    build(root);
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
    //cout<<dist(3 , 6)<<" Waaaa\n";
    for(int j = 1 ; j <= k ; j++)
    {
        int ans = 0;
        for(int i = 0 ; i < party[j].size() ; i++)
            ans = max(ans , dist(dpst[j] , party[j][i]));
        cout<<ans<<"\n";
    }
}
