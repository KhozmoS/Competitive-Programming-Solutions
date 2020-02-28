#include <bits/stdc++.h>
#define mid (ini+fin)/2
using namespace std;

const int MAX = 1e5 + 5;

vector<int> grafo[MAX];
int p, color[MAX], ini[MAX], fin[MAX];
int tree[4*MAX][3], aux[MAX];
bool prop[4*MAX];

void dfs(int n) {
    p++;
    ini[n] = p;
    for(int i = 0; i < grafo[n].size(); i++){
        dfs( grafo[n][i] );
    }
    fin[n] = p;
}

void built(int n, int ini, int fin){
    if(ini == fin){
        tree[n][color[ini]-1] = 1;
    }else{
        built(n*2, ini, mid);
        built(n*2+1, mid+1, fin);
        tree[n][0] = tree[n*2][0] + tree[n*2+1][0];
        tree[n][1] = tree[n*2][1] + tree[n*2+1][1];
    }
}

void lazy(int n){
    prop[n] = !prop[n];
    swap(tree[n][0], tree[n][1]);
}

void update(int n, int ini, int fin, int a, int b){
    if(ini > b ||  fin < a){
        return;
    }
    if(ini >= a && fin <= b){
        lazy(n);
        return;
    }
    if(prop[n]){
        lazy(n*2);
        lazy(n*2+1);
        prop[n] = false;
    }
    update(n*2, ini, mid, a, b);
    update(n*2+1, mid+1, fin, a, b);
    tree[n][0] = tree[n*2][0] + tree[n*2+1][0];
    tree[n][1] = tree[n*2][1] + tree[n*2+1][1];
}

int query(int n, int ini, int fin, int a, int b){
    if(ini > fin) return 0;
    if(ini > b ||  fin < a){
        return 0;
    }
    if(ini >= a && fin <= b){
        return tree[n][0];
    }
    if(prop[n]){
        lazy(n*2);
        lazy(n*2+1);
        prop[n] = false;
    }
    return query(n*2, ini, mid, a, b) + query(n*2+1, mid+1, fin, a, b);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N, Q, a, b, raiz;

    cin >>N;

    for(int i = 1; i <= N; i++){
        cin >>a >>b;
        if(a == 0){
            raiz = i;
            aux[raiz] = b;
        }
        grafo[a].push_back(i);
        aux[i] = b;
    }

    dfs(raiz);

    /*for(int i = 1; i <= N; i++){
        cout <<ini[i] <<" ";
    }*/

    for(int i = 1; i <= N; i++){
        color[ini[i]] = aux[i];
    }

    built(1, 1, N);
    cin >>Q;

    while(Q--){
        cin >>a >>b;
        if(a == 1){
            update(1, 1, N, ini[b], fin[b]);
        }else{
            cout <<query(1, 1, N, ini[b]+1, fin[b]) <<"\n";
        }
    }
    return 0;
}
