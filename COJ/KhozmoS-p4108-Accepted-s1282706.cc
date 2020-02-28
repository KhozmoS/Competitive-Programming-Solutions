#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define PB push_back
#define db double
const int MAX = 1e6+5;

typedef long long ll;
typedef pair <int , int> par;
typedef pair <par , int> trio;

set <par> S;
vector <int> v[105];
par ar[MAX];

int n , m;

int G[105];
int P[105];
int cur;
bool mk[105];
void dfs(int node)
{
    mk[node] = true;
    for(int i = 0 ; i < v[node].size() ; i++)
    {
        int nw = v[node][i];

        if(!mk[nw]){
            P[nw]++;
            G[cur]++;
            dfs(nw);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i = 1 ; i <= m ; i++)
    {
        int a , b;cin>>a>>b;
        v[a].PB(b);
    }
    for(int i = 1; i <= n ; i++)
    {
        memset(mk , 0 , sizeof(mk));
        cur = i;
        dfs(i);
    }

    vector <par> pos;

    for(int i = 1 ; i <= n ; i++)
    {
        //cout<<G[i]<<" "<<P[i]<<" "<<i<<"\n";
        if(G[i]+P[i]==(n-1))
           pos.PB(par(n-G[i] , i));
    }
    sort(pos.begin() , pos.end());
    reverse(pos.begin() , pos.end());

    for(int i = 0 ; i < pos.size() ; i++)
        cout<<pos[i].f<<" "<<pos[i].s<<"\n";
}
