#include<bits/stdc++.h>


using namespace std;
const int MAX = 5*1e5 + 5;

#define PB push_back
typedef vector <int> vi;

vi adl[MAX];
int lvl[MAX] , cad[MAX] , p[MAX] , start[MAX] , sz[MAX] , heavy[MAX] , len_cad[MAX] , pos[MAX];
int root, in , fn;
bool mk[MAX];
vector <vector <int> > ST , lz;
vector <int> vacio;


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
int cnt = 1;

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
void lazy(int idx, int node, int ini, int fin){
    if(ini == fin){
        lz[idx][node] = 0;
        return;
    }

    int n1 = node << 1;
    int n2 = n1 + 1;
    int mit = (ini+fin) >> 1;
    lz[idx][n1] = !lz[idx][n1];
    lz[idx][n2] = !lz[idx][n2];

    ST[idx][n1] = mit - ini + 1 - ST[idx][n1];
    ST[idx][n2] = fin - mit - ST[idx][n2];

    lz[idx][node] = 0;
    return;
}


int query(int idx , int node , int ini , int fin)
{
    if(lz[idx][node]){
        lazy(idx, node, ini, fin);
    }

    if(fin < in || fn < ini){
        return 0;
    }

    if(in <= ini && fin <= fn){
        return ST[idx][node];
    }

    int mit = (ini + fin) >> 1;
    int n1 = (node << 1);
    int n2 = n1 + 1;

    int q1 = query(idx, n1, ini, mit);
    int q2 = query(idx, n2, mit + 1, fin);
    return q1+q2;
}

void update(int idx , int node , int ini , int fin){
    if(lz[idx][node]){
        lazy(idx, node, ini, fin);
    }

    if(fin < in || fn < ini){
        return;
    }
    if(in <= ini && fin <= fn){
        ST[idx][node] = fin - ini + 1 - ST[idx][node];
        lz[idx][node] = 1;
        return;
    }

    int mit = (ini + fin) >> 1;
    int n1 = (node << 1);
    int n2 = n1 + 1;

    update(idx, n1, ini, mit);
    update(idx, n2, mit + 1, fin);

    ST[idx][node] = ST[idx][n1] + ST[idx][n2];

    return;
}

void build(int idx , int node , int ini , int fin)
{
    if(ini == fin)
    {
        ST[idx][node] = 1;
        lz[idx][node] = 0;

        return;
    }
    int mit = (ini + fin) >> 1;

    build(idx , node * 2 , ini , mit);
    build(idx , node * 2 + 1 , mit + 1 , fin);
    ST[idx][node] = ST[idx][node*2] + ST[idx][node*2+1];
    return;
}

////////////////////////////////////////////

int solve_q(int a , int b)
{
    int res = 0;
    while(cad[a] != cad[b])
    {
        if(lvl[start[cad[a]]] < lvl[start[cad[b]]]) swap(a , b);

        int c = start[cad[a]];
        in = pos[c];
        fn = pos[a];
        res = res + query(cad[a] , 1 , 1 , len_cad[cad[a]]);
        a = p[c];
    }

    if(lvl[a] > lvl[b]) swap(a , b);
    in = pos[a];
    fn = pos[b];
    res = res + query(cad[a] , 1 , 1 , len_cad[cad[a]]);
    return res;
}

void solve_u(int a , int b)
{
    while(cad[a] != cad[b])
    {
        if(lvl[start[cad[a]]] < lvl[start[cad[b]]]) swap(a , b);

        int c = start[cad[a]];
        in = pos[c];
        fn = pos[a];
        update(cad[a] , 1 , 1 , len_cad[cad[a]]);
        a = p[c];
    }

    if(lvl[a] > lvl[b]) swap(a , b);
    in = pos[a];
    fn = pos[b];
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

        build(i, 1, 1, len_cad[i]);
    }
    return;
}

int main()
{
    //freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
//
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n , q;
    cin>>n;

    for(int i = 1 ; i < n ; i++)
    {
        int a , b;
        cin>>a>>b;
        adl[a].PB(b);
        adl[b].PB(a);

        root = a;
    }

    dfs(root, -1);
    HLD(root);
    init();
    cin>>q;
    while(q--)
    {
        char ch;int a, b;
        cin>>ch>>a>>b;
        if(ch == '1')
            solve_u(a , b);

        else
            cout << solve_q(a , b) << "\n";
    }
    return 0;
}
