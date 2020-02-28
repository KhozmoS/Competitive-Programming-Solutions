#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define db double
#define sz(c) (c).size()
#define all(c) (c).begin(),(c).end()

typedef long long ll;
typedef pair <int , int> ii;
typedef pair <ii , int> iii;
typedef vector <int> vi;
typedef vector < vi > vvi;
typedef vector < ii > vii;
typedef vector < vii > vvii;

const int mod = 1e9+7;
const int MAX = 1e6+5;

vi v[105];
int n;
bool mk[105];

void dfs(int node){
    mk[node] = true;
    for(int i = 0 ; i < v[node].size() ; i++)
    {
        int nw = v[node][i];
        if(!mk[nw])
        {
            dfs(nw);
        }
    }
}
bool ok()
{
    for(int i = 1 ; i <= n ; i++){
        if(!mk[i]) return false;
    }
    return mk[1];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i = 1 ; i < n ; i++)
    {
        int a ,b ;cin>>a>>b;
        v[b].pb(a);
    }
    for(int i = 1 ; i <= n ; i++)
    {
        memset(mk , false , sizeof(mk));
        dfs(i);
        if(ok())
        {
            cout<<i<<"\n";
            return 0;
        }
    }
    cout<<"-1\n";
}
