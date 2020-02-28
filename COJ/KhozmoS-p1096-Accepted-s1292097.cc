#include <bits/stdc++.h>

using namespace std;

#define pi pair<int, int>
#define vi vector<int>
#define vp vector<pi>
#define pb push_back
#define sti set<int>

const int MAX = 200005;

vi grafo[MAX];
bool vis[MAX];
int cont;

void DFS(int n)
{
    vis[n] = 1;
    for (int i = 0; i < grafo[n].size(); i++)
        if (!vis[grafo[n][i]])
            DFS(grafo[n][i]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m,l , v, w , t;

        cin>>t;
        while(t--){
        memset(vis , 0 , sizeof vis);
        for(int i = 0; i < MAX ; i++) grafo[i].clear();

        cin >> n >> m >> l;
        while (m--)
        {
            cin >> v >> w;
            grafo[v].pb(w);
        }

        while(l--) cin>>v , DFS(v);


        int ans = 0;
        cout << accumulate(vis , vis+MAX , ans) << "\n";
        cont = 0;

        }


}
