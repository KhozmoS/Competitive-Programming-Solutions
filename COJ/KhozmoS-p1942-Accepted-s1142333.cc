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


int lca(int a, int b){

    if(lvl[a] < lvl[b]) swap(a , b);
    int mlog = log2(lvl[a]);

    for(int i = mlog ; i >= 0 ; i--)
        if(lvl[a] - (1 << i) >= lvl[b])
          a = table[i][a];

    if(a == b)
        return a;


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
