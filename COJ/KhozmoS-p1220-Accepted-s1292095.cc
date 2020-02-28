#include <bits/stdc++.h>

using namespace std;

#define pi pair<int, int>
#define vi vector<int>
#define vp vector<pi>
#define pb push_back

vi grafo[2005];
bool vis[2005];
int cont;

void DFS(int n)
{
    vis[n] = 1;
    cont++;
    for (int i = 0; i < grafo[n].size(); i++)
        if (!vis[grafo[n][i]])
            DFS(grafo[n][i]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, v, w , p;

    while (1)
    {
        cin >> n >> m;
        if (!n && !m) return 0;

        while (m--)
        {
            cin >> v >> w >> p;

            if (2 == p)
            {
                grafo[v].pb(w);
                grafo[w].pb(v);
            }
            else grafo[v].pb(w);

        }

        int cont2 = 0;
        for (int i = 1; i <= n; i++)
        {
            cont = 0;
            DFS(i);
            memset(vis, false, sizeof(vis));
            if (cont == n)
                cont2++;
            else break;
        }

        for (int i = 1; i <= n; i++)
            grafo[i].clear();

        if (cont2 == n)
            cout << "1\n";
        else cout << "0\n";

    }


}
