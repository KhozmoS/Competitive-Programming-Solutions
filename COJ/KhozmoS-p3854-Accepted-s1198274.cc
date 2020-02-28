#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e4;
vector <int> adl[MAX];
bool mk[MAX];
int n , m , q;int goal;
void dfs(int node)
{
    mk[node] = true;

    for(int i = 0 ; i < adl[node].size() ; i++){

        int x = adl[node][i];
        if(mk[x]) continue;
        dfs(x);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>q;
    for(int i = 1; i <= m ; i++)
    {
        int a , b;cin>>a>>b;
        adl[a].push_back(b);
        adl[b].push_back(a);
    }
    while(q--)
    {
        int a;
        cin>>a>>goal;
        dfs(a);
        if(mk[goal])
            cout<<"Y\n";
        else cout<<"N\n";
        memset(mk , false , sizeof(mk));
    }
}
