#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 5;

int n, m, a, b, sol;

vector <int> :: iterator ite;
vector <int> ady[MAX], par[MAX];

int k, pos[MAX], orden[MAX];
bool mark[MAX], dp[MAX][MAX];

void ordena(int root) {
    mark[root] = true;
    for(int i = 0; i < ady[root].size(); i++) {
        int to = ady[root][i];
        if(!mark[to])
            ordena(to);
    }
    orden[k--] = root;
}

int main() {
    scanf("%d %d", &n, &m);

    while(m--) {
        scanf("%d %d", &a, &b);
        ady[a].push_back(b);
        par[b].push_back(a);
    }

    k = n;
    //ordena(1);

    dp[1][1] = true;
    for(int i = 1; i < n; i++)
        for(int j = i+1; j <= n; j++) {
            int posa = i, posb = j;
            for(ite = par[posb].begin(); ite != par[posb].end(); ite++) {
                int pad = *ite;
                if(dp[min(pad, posa)][max(pad, posa)]) {
                    dp[min(posa, posb)][max(posa, posb)] = true;
                    break;
                }
            }
        }

    int sol = 0;
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            sol += dp[i][j];

    printf("%d\n", sol);
}
