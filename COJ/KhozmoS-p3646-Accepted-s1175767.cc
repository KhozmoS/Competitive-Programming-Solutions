#include<bits/stdc++.h>


using namespace std;
const int MAX = 5*1e5 + 5;

#define PB push_back
typedef vector <int> vi;

vi adl[MAX];
int lvl[MAX] , cad[MAX] , p[MAX] , start[MAX] , sz[MAX] , heavy[MAX] , len_cad[MAX] , pos[MAX];
int A[MAX];

int root, in , fn, valor;
bool mk[MAX];
vector <vector <int> > ST , lz;
vector <int> vacio;
int cnt = 1;

void clean()
{
    for(int i = 0 ; i< MAX ; i++)
    {
        adl[i].clear();
    }
    cnt = 1;
    ST.clear();
    memset(mk , false , sizeof(mk));
    memset(heavy , 0 , sizeof(heavy));
    memset(lvl , 0 , sizeof(lvl));
    memset(cad , 0 , sizeof(cad));
    memset(p , 0 , sizeof(p));
    memset(start , 0 , sizeof(start));
    memset(sz , 0 , sizeof(sz));
    memset(len_cad , 0 , sizeof(len_cad));
    memset(pos , 0 , sizeof(pos));

}

//HEAVY LIGHT
void dfs(int node , int pr)
{
    p[node] = pr;
    lvl[node] = 1;
    sz[node] = 1;
    if(p[node] != -1)
        lvl[node] += lvl[pr];

    for(int i = 0; i < adl[node].size(); i++)
    {
        int x = adl[node][i];
        if(x == pr) continue;

        dfs(x , node);
        sz[node] = max(sz[x]+1 , sz[node]);
        if(sz[heavy[node]] < sz[x])
            heavy[node] = x;
    }
}

void HLD(int node)
{
    mk[node] = true;

    len_cad[cnt]++;
    pos[node] = len_cad[cnt];
    cad[node] = cnt;

    if(!heavy[node]) return;

    HLD(heavy[node]);

    for(int i = 0; i < adl[node].size(); i++)
    {
        int x = adl[node][i];
        if(x != heavy[node] && x != p[node]){
            cnt++;
            start[cnt] = x;
            HLD(x);
        }
    }

    return;
}
///////////////////////////////////////////////

//SEGMENT TREE

int query(int idx , int node , int ini , int fin)
{
    if(fin < in || fn < ini){
        return -1;
    }

    if(in <= ini && fin <= fn){
        return ST[idx][node];
    }

    int mit = (ini + fin) >> 1;
    int n1 = (node << 1);
    int n2 = n1 + 1;

    int q1 = query(idx, n1, ini, mit);
    int q2 = query(idx, n2, mit + 1, fin);

    if(q1 == -1) return q2;
    if(q2 == -1) return q1;

    return __gcd(q1, q2);
}

void update(int idx , int node , int ini , int fin){

    if(fin < in || fn < ini){
        return;
    }
    if(in <= ini && fin <= fn){
        ST[idx][node] = valor;
        return;
    }

    int mit = (ini + fin) >> 1;
    int n1 = (node << 1);
    int n2 = n1 + 1;

    update(idx, n1, ini, mit);
    update(idx, n2, mit + 1, fin);

    ST[idx][node] = __gcd(ST[idx][n1], ST[idx][n2]);

    return;
}

void build(int idx , int node , int ini , int fin)
{
    if(ini == fin)
    {
        ST[idx].PB(0);
        lz[idx].PB(0);
        return;
    }
    int mit = (ini + fin) >> 1;

    build(idx , node * 2 , ini , mit);
    build(idx , node * 2 + 1 , mit + 1 , fin);
    ST[idx].PB(0);
    lz[idx].PB(0);
    return;
}

////////////////////////////////////////////

int solve_q(int a , int b)
{
    int res = -1;
    while(cad[a] != cad[b])
    {
        if(lvl[start[cad[a]]] < lvl[start[cad[b]]]) swap(a , b);

        int c = start[cad[a]];
        in = pos[c];
        fn = pos[a];
        if(res == -1)
            res = query(cad[a] , 1 , 1 , len_cad[cad[a]]);
        else
            res = __gcd(res , query(cad[a] , 1 , 1 , len_cad[cad[a]]));
        a = p[c];
    }

    if(lvl[a] > lvl[b]) swap(a , b);
    in = pos[a];
    fn = pos[b];
    if(res == -1)
        res = query(cad[a] , 1 , 1 , len_cad[cad[a]]);
    else
        res = __gcd(res , query(cad[a] , 1 , 1 , len_cad[cad[a]]));

    return res;
}

void solve_u(int a , int b)
{
    valor = b;
    in = pos[a];
    fn = in;
    update(cad[a] , 1 , 1 , len_cad[cad[a]]);
    return;
}

void init()
{
    ST.PB(vacio);
    lz.PB(vacio);
    start[1] = root;
    for(int i = 1; i <= cnt; i++){
        ST.PB(vacio);
        lz.PB(vacio);

        for(int j = 0; j <= len_cad[i] * 4; j++){
            ST[i].PB(0);
            lz[i].PB(0);
        }

        //build(i, 1, 1, len_cad[i]);
    }
    return;
}
int main()
{

 // freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
//
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n , q;
    while(cin>>n){
    clean();
    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }

    for(int i = 1 ; i < n ; i++)
    {
        int a , b;
        cin>>a>>b;
        a++; b++;
        adl[a].PB(b);
        adl[b].PB(a);

        root = a;
    }

    dfs(root, -1);
    HLD(root);
    init();

    for(int i = 1; i <= n; i++){
        solve_u(i , A[i]);
    }
    cin >> q;

    while(q--)
    {
        char ch;int a, b;
        cin>>ch>>a>>b;
        if(ch == '2'){
            a++;
            solve_u(a , b);
        }
        else{
            a++; b++;
            cout << solve_q(a , b) << "\n";
        }
    }
    }
    return 0;
}
