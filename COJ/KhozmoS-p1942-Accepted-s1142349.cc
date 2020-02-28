#include <bits/stdc++.h>

using namespace std;
const int MAX = (1 << 18);
int P[MAX][20] , lvl[MAX] , N , Q , R , S;
vector <int> adl[MAX];
queue <int> cola;

void build(int node)
{
    memset(P , -1 , sizeof(P));
    lvl[node] = 1;

    cola.push(node);

    while(!cola.empty())
    {
        int n = cola.front();
        cola.pop();

        for(int i = 0 ; i < adl[n].size() ; i++)
        {
            int x = adl[n][i];
            if(!lvl[x])
            {
                P[x][0] = n;
                lvl[x] = lvl[n] + 1;
                cola.push(x);
            }
        }
    }

    for(int k = 1 ; (1 << k) <= N ; k++)
        for(int i = 0 ; i <= N ; i++)
        {
           int med = P[i][k - 1];
           if(med != -1)
               P[i][k] = P[med][k - 1];
        }
}

int LCA(int a , int b)
{
    if(lvl[a] < lvl[b]) swap(a , b);

    int mlog = log2(lvl[a]);
    for(int i = mlog ; i >= 0 ; i--)
        if(lvl[a] - (1 << i) >= lvl[b])
           a = P[a][i];

    if(a == b) return a;

    for(int i = log2(lvl[a]) ; i >= 0 ; i--)
        if(P[a][i] != P[b][i])
        {
           a = P[a][i];
           b = P[b][i];
        }

    return P[a][0];
}
void clean()
{
    for(int i = 0 ; i < MAX ; i++)
        adl[i].clear();
    memset(lvl , 0 , sizeof(lvl));
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int imp = 0;
    while(true)
    {
        cin>>N>>R>>S>>Q;
        if(!N && !R && !S && !Q) return 0;
        
        cout<<"\n";
        for(int i = 0; i < R ; i++)
        {
            int a;
            cin>>a;
            adl[0].push_back(a);
        }
        for(int i = 0 ; i < S ; i++){
            int a , b;cin>>a>>b;
            adl[a].push_back(b);
        }
        build(0);
        while(Q--)
        {
            int a , b;cin>>a>>b;

            int ans = LCA(a , b);
            if(!ans) cout<<"-1"<<"\n";

            else if(ans == a || ans == b) cout<<"0\n";

            else cout<<ans<<"\n";
        }
        clean();
    }

}
