#include <bits/stdc++.h>

using namespace std;
#define PB push_back
const int MAX = 1e6+1;
int ST[MAX*4];

int n ,q;
void build(int node , int x, int y)
{
    if(x==y)
    {
        cin>>ST[node];
        return;
    }
    int mt = (x+y)>>1;
    build(node*2 , x , mt);
    build(node*2+1 , mt+1, y);

    ST[node] = max(ST[node*2] , ST[node*2+1]);
}
int ans;
void query(int node , int x , int y , int a, int b , int v)
{
    if(b < x || a > y) return;

    if(ST[node] >= v && x==y){
        ans = min(ans , x);
        return;
    }
    if(x==y) return;
    if(a<=x && b >= y)
    {
        if(ST[node] >= v)
        {
            if(ST[node*2] >= v)
            {
                int mt = (x+y)>>1;
                query(node*2 , x , mt , a , b , v);
            }
            else
            {
                int mt = (x+y)>>1;
                query(node*2+1 , mt+1 , y ,a  , b , v);
            }
        }
        return;
    }

    int mt = (x+y)>>1;

    query(node*2 , x , mt , a , b , v);
    query(node*2+1 , mt+1, y , a , b , v);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    build(1 , 1 , n);

    cin>>q;
    while(q--)
    {
        int v , a , b;
        cin>>v>>a>>b;
        ans = INT_MAX;
        query(1 , 1 , n , a , b , v);
        if(ans == INT_MAX) cout<<"-1\n";
        else cout<<ans<<"\n";
    }
}