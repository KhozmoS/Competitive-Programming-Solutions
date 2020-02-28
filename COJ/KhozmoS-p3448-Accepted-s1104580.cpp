
#include <bits/stdc++.h>

using namespace std;

const int MAX = 100 + 5;
int cont, low[MAX], vdfs[MAX], ndfs;
vector<int> grafo[MAX];
set<int> sol;

void tarjan(int u, int p = -1){
    int v;
    low[u] = vdfs[u] = ndfs++;
    for(int i = 0; i < grafo[u].size(); i++){
        v = grafo[u][i];
        if(!vdfs[v]){
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if((vdfs[u] == 1 && vdfs[v] > 2) || (vdfs[u] != 1 && low[v] >= vdfs[u])){
                sol.insert(u);
            }
        }else if(v != p){
            low[u] = min(low[u], vdfs[v]);
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int T, N, M, a, b;
    cin >>T;

    for(int t = 1; t <= T; t++){
        sol.clear();
        sol.insert(1);
        ndfs = cont = 0;
        for(int i = 0; i < MAX; i++){
            grafo[i].clear();
            vdfs[i] = low[i] = 0;
        }

        cin >>N >>M;
        while(M--){
            cin >>a >>b;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }
        tarjan(1);

        set<int>::iterator itr1 = sol.begin(), itr2 = sol.end();
        itr2--;
        itr1++;

        cout <<"Case #" <<t <<": ";
        if(sol.size() == 1){
            cout <<"0\n";
        }else{
            cout <<sol.size()-1<<" ";
            while(itr2 != itr1){
                cout <<*itr1 <<" ";
                itr1++;
            }
            cout <<*itr2 <<"\n";
        }

    }

    return 0;
}