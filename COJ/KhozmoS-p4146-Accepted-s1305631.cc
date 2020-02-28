#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define sz(c) (c).size()
#define db double
#define all(c) (c).begin(),(c).end()

typedef long long ll;
typedef pair <int , int >ii;
typedef pair <ii , int> iii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef vector <vii> vvii;

const ll mod = 1e9+7;
const int MAX = 1e6+5;

vi v[MAX*2];
int ans , n;
int dp[MAX*2];
bool mk[MAX*2];
int pr[MAX*2];

void dfs(int node)
{
    stack <int> cola;
    cola.push(node);
    pr[node] = -1;
    int p;
    while(!cola.empty()){

    node = cola.top();
    mk[node] = true;
    int cnt = 0;
    for(int i = 0 ; i < v[node].size() ; i++)
    {
         int nw = v[node][i];
         if(mk[nw])
            continue;
         cnt++;
         cola.push(nw);
         pr[nw] = node;
    }
    if(cnt) continue;
    cola.pop();
    int fst = 0;
    int snd = 0;
    for(int i = 0 ; i < v[node].size() ; i++)
    {
        int nw = v[node][i];
        int tmp = dp[nw];
        if(fst==0)
            fst = tmp;
        else if(snd==0)
            snd = tmp;
        else{
            snd = max(snd , tmp);
        }
        if(snd>fst)
            swap(snd,fst);
    }
    p = pr[node];
    if((int)sz(v[node])-1 || p==-1){
        if(p!=-1){
            ans = max(ans , fst+snd+(sz(v[node])>2 ? (int)sz(v[node])-2:0));
            ans = max(ans , fst+(sz(v[node])>1 ? (int)sz(v[node])-1:0));
        }
        else{
           // cout<<fst<<" "<<v[node].size()<<" "<<p<<"\n";
            ans = max(ans , fst+snd+((sz(v[node])>1) ? (int)sz(v[node])-2 : 0));
            ans = max(ans , fst+((sz(v[node])>0) ? (int)sz(v[node])-1 : 0));
        }
    }
    if(p==-1)
        ans = max(ans , fst);

    fst = max(fst , fst+((int)sz(v[node])-1-(p!=-1)));
    fst = max(fst , ((int)sz(v[node])-(p!=-1)));
    //cout<<node<<" "<<fst<<" "<<ans<<"\n";
    dp[node] = fst;

   // cout<<node<<" "<<dp[node]<<"\n";
    }

}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i = 1 ; i <= n-1 ; i++){
        int a , b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(1);
    cout<<ans<<"\n";
}
