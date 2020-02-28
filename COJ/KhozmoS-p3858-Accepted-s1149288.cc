#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

struct par {
    int x, y;
    par() {}
    par(int a, int b) : x(a), y(b) {}
    bool operator < (const par &a) const {
        return x == a.x ? y < a.y : x < a.x;
    }
} punto[MAX];

vector <int> lista[MAX];
set <int> lista2[MAX];

int n, a, b;
int tiempo, SCC;
int num[MAX], low[MAX], scc[MAX], v[MAX], dp[MAX];
stack <int> s;

void dfs(int root) {
    s.push(root);
    low[root] = num[root] = ++tiempo;

    for(int i = 0; i < lista[root].size(); i++) {
        int to = lista[root][i];
        if(!low[to]) {
            dfs(to);
            low[root] = min(low[root], low[to]);
        } else if(!scc[to])
            low[root] = min(low[root], num[to]);
    }

    if(num[root] == low[root]) {
        SCC++;
        while(!scc[root]) {
            scc[s.top()] = SCC;
            v[SCC]++;
            s.pop();
        }
    }
}

vector <par> x, y;

int F(int node) {
    int aux = dp[node];
    if(aux != -1)return aux;
    aux = v[node];
    for(int to : lista2[node])
        aux = max(aux, F(to) + aux);
    return aux;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a >> b;
        punto[i] = par(a, b);
        x.push_back(par(a, i));
        y.push_back(par(b, i));
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    for(int i = 1; i <= n; i++) {
        a = punto[i].x;
        b = punto[i].y;
        auto ite1 = upper_bound(x.begin(), x.end(), par(a, i));
        auto ite2 = upper_bound(y.begin(), y.end(), par(b, i));
        if(ite1 != x.end())
            lista[ite1 -> y].push_back(i);
        if(ite2 != y.end() && ite2 -> y != ite1 -> y)
            lista[ite2 -> y].push_back(i);
    }

    for(int i = 1; i <= n; i++)
        if(!scc[i])dfs(i);

    for(int i = 1; i <= n; i++)
        for(int to : lista[i])
            if(scc[i] != scc[to])
                lista2[scc[i]].insert(scc[to]);

    memset(dp, -1, sizeof(dp));

    for(int i = 1; i <= n; i++) {
        if(dp[scc[i]] == -1)
            dp[scc[i]] = F(scc[i]);
        cout << dp[scc[i]] - 1 << "\n";
    }
}