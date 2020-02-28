#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define f first
#define s second
#define PB push_back
const int MAX = 1e5+5;
typedef pair <int , int> par;
vector <int> v[MAX];
vector <int> roots;
int team[MAX];

par dfs(int node)
{
    int smr = 0;
    int smt = team[node];
    for(int i = 0 ; i < v[node].size() ; i++)
    {
        par x = dfs(v[node][i]);
        smr += max(x.f , x.s);
        smt += x.s;
    }
    return par(smr , smt);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;

    for(int i = 1 ; i <= n ; i++)
    {
        int x , y;
        cin>>x>>y;
        if(!x)
        {
            roots.PB(i);

        }
        else v[x].PB(i);
        team[i] = (y ? 1 : -1);
    }
    int ans = 0;

    for(int i = 0 ; i < roots.size() ;i++)
    {
        par x = dfs(roots[i]);
        ans += max(x.f , x.s);
    }
    cout<<ans<<"\n";

}
