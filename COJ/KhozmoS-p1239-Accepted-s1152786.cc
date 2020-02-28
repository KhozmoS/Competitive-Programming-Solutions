    #include <bits/stdc++.h>

    using namespace std;

    #define PB push_back
    typedef unsigned long long ll;
    const int MAX = 1e5 + 5;
    typedef pair  <int , ll > par;
    
    vector <par> adl[MAX];
    
    int lvl[MAX];
    
    ll cost[MAX]; int P[MAX][20] , n , q;
    
    void bfs(int node)
    {
        memset(P , 0 , sizeof(P));
        queue <int> Q;
        Q.push(node);
        lvl[node] = 1;
        cost[node] = 0;
        
        while(!Q.empty())
        {
            node = Q.front(); Q.pop();
            for(int i = 0 ; i < adl[node].size() ; i++)
            {
                int x = adl[node][i].first;
                ll c = adl[node][i].second;
                if(lvl[x]) continue;

                P[x][0] = node;
                lvl[x] = lvl[node] + 1;
                cost[x] = cost[node] + c;

                Q.push(x);
            }
        }

        for(int k = 1 ; (1 << k) <= n ; k++)
            for(int i = 1 ; i <= n ; i++)
                P[i][k] = P[P[i][k - 1]][k - 1];
    }

  int LCA(int a , int b)
  {
    if(lvl[a] < lvl[b]) swap(a , b);

    int l = log2(lvl[a]);

    for(int i = l ; i >= 0 ; i--)
    {
        if(lvl[a] - (1 << i) >= lvl[b])
            a = P[a][i];
    }
    if(a == b) return a;

    l = log2(lvl[a]);

    for(; l >= 0 ; l--)
        if(P[a][l] != P[b][l])
        {
           a = P[a][l];
           b = P[b][l];
        }
    return P[a][0];
}



    ll dist(int a , int b)
    {
        int c = LCA(a , b);
        return cost[a] + cost[b] - (2ll * cost[c]);
    }
    void clean()
    {
        for(int i = 1 ; i <= n ; i++)
        {
            lvl[i] = 0;
            cost[i] = 0;
            adl[i].clear();
        }
    }
    int main()
    {
        ios_base::sync_with_stdio(0);cin.tie(0);
        while(cin>>n)
        {
            if(!n) break;
            for(int i = 2 ; i <= n ; i++)
            {
                int b ;ll c;
                cin>>b>>c;
                b++;
                adl[i].PB(par(b , c));
                adl[b].PB(par(i , c));
            }
           bfs(1);
           int q;cin>>q;
            while(q--)
            {
                int a , b;cin>>a>>b;
                a++;b++;
                if(q)
                cout<<dist(a , b)<<" ";
                else cout<<dist(a , b)<<"\n";
            }
            clean();
        }
    }
