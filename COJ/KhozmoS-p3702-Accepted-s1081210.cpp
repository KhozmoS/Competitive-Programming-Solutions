#include <bits/stdc++.h>
#define mid (ini+fin)/2

using namespace std;
const int MAX = 1e5 + 5;

string tree[3*MAX];
string prop[3*MAX];

string op(string a, string b){
    if(a[0] == '-') return b;
    if(b[0] == '-') return a;
    string sol = "";
    sol.reserve(12);
    int i = 0;
    while(a[i] == b[i] && i < min(a.length(), b.length())){
        sol += a[i];
        i++;
    }
    return sol;
}

void built(int n, int ini, int fin){
    if(ini == fin){
        cin >>tree[n];
    }else{
        built(n*2, ini, mid);
        built(n*2+1, mid+1, fin);
        tree[n] = op(tree[n*2], tree[n*2+1]);
    }
}

void lazy(int n, string v){
    prop[n] = v;
    tree[n] = v;
}

string query(int n, int ini, int fin, int a, int b){
    if(ini > b || fin < a){
        return "-";
    }
    if(ini >= a && fin <= b){
        return tree[n];
    }
    if(prop[n] != ""){
        lazy(n*2, prop[n]);
        lazy(n*2+1, prop[n]);
        prop[n] = "";
    }
    return op(query(n*2+1, mid+1, fin, a, b), query(n*2, ini, mid, a, b));
}

void update(int n, int ini, int fin, int a, int b, string v){
    if(ini > b || fin < a){
        return;
    }
    if(ini >= a && fin <= b){
        lazy(n, v);
        return;
    }
    if(prop[n] != ""){
        lazy(n*2, prop[n]);
        lazy(n*2+1, prop[n]);
        prop[n] = "";
    }
    update(n*2, ini, mid, a, b, v);
    update(n*2+1, mid+1, fin, a, b, v);
    tree[n] = op(tree[n*2], tree[n*2+1]);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N, Q, t, a, b, cont;
    string v, r;

    for(int i = 0; i < 3*MAX; i++){
        tree[i].reserve(12);
        prop[i].reserve(12);
    }

    cin >>N >>Q;

    built(1, 1, N);

    while(Q--){
        cont = 0;
        cin >>t >>a >>b;
        r = "";
        if(t == 1){
            r = query(1, 1, N, a, b);
            cout <<r.length() <<"\n";
        }else{
            cin >>v;
            update(1, 1, N, a, b, v);
        }
    }

    return 0;
}
