#include <bits/stdc++.h>

using namespace std;

#define PB push_back

vector <int> v[111111];
bool red[111111];
bool mk[111111] , m[111111];
int n , r;
int freq[111111] , d[111111];

int D(int node)
{
    mk[node] = true;
    m[node] = true;
    queue <int> q;
    q.push(node);
    int last = node;
    while(!q.empty())
    {
        int cur = q.front();q.pop();
        for(int i = 0 ; i < v[cur].size() ; i++)
        {
            int nw = v[cur][i];
            if(red[nw] && !mk[nw])
            {
                mk[nw] = true;
                m[nw] = true;
                q.push(nw);
                last = nw;
            }
        }
    }
    
    d[last] = 1;
    q.push(last);
    mk[last] = false;
    while(!q.empty())
    {
        int cur = q.front();q.pop();
        for(int i = 0 ; i < v[cur].size() ; i++)
        {
            int nw = v[cur][i];
            if(red[nw] && mk[nw])
            {
                mk[nw] = false;
                q.push(nw);
                last = nw;
                d[nw] = d[cur] + 1;
            }
        }
    }
    return d[last];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>r;
    while(r--)
    {
        int x;
        cin>>x;
        red[x] = true;
    }
    int root;
    for(int i = 1 ; i < n ; i++)
    {
        int a , b;
        cin>>a>>b;
        v[a].PB(b);
        v[b].PB(a);
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        if(red[i] && !m[i])
            ans = max(ans , D(i));
    }
    cout<<ans<<"\n";
}
