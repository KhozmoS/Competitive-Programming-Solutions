#include <bits/stdc++.h>

using namespace std;

const int MAX = 1 << 18;

vector<int> grafo[MAX];

int N, M, D;
int table[18][MAX];
int lvl[MAX];

void built(int u){
    queue<int> cola;
    memset(table, -1, sizeof table);
    cola.push(u);
    lvl[u] = 1;

    while(!cola.empty()){
        u = cola.front(); cola.pop();
        for(int i = 0; i < grafo[u].size(); i++){
            int v = grafo[u][i];
            if(!lvl[v]){
                cola.push(v);
                table[0][v] = u; //el padre de v es u
                lvl[v] = lvl[u] + 1;
            }
        }
    }
    //construccion de la tabla
    for(int k = 1; (1 << k) <= N; k++){
        for(int i = 0; i <= N; i++){
            int mid = table[k-1][i];
            if(mid != -1){
                table[k][i] = table[k-1][mid];
            }
        }
    }
}

int walk(int a, int k){
    for(int i = 0; (1 << i) <= N; i++){
        if( ((1 << i) & k) ){
            a = table[i][a];
        }
    }
    return a;
}

int lca(int a, int b){
    if(lvl[a] > lvl[b]){
        a = walk(a, lvl[a] - lvl[b]);
    }
    if(lvl[a] < lvl[b]){
        b = walk(b, lvl[b] - lvl[a]);
    }
    if(a == b){
        return a;
    }

    for(int i = log2(lvl[a]); i >= 0; i--){
        if(table[i][a] != table[i][b]){
            a = table[i][a];
            b = table[i][b];
        }
    }
    return table[0][a];
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int R, S, Q, a, b, r;

    while(true){
        cin >>N >>R >>S >>Q;
        if(!N && !R && !S && !Q) break;
        cout <<"\n";

        memset(lvl, 0, sizeof lvl);
        memset(table, 0, sizeof table);

        for(int i = 0; i <= N; i++) grafo[i].clear();

        while(R--){
            cin >>a;
            grafo[0].push_back(a);
        }

        while(S--){
            cin >>a >>b;
            grafo[a].push_back(b);
        }

        built(0);

        while(Q--){
            cin >>a >>b;
            r = lca(a, b);
            if(r == a || r == b){
                cout <<"0\n";
            }else if(r == 0){
                cout <<"-1\n";
            }else{
                cout <<r <<"\n";
            }
        }
    }
}