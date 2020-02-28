#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e6;
const int maxn = 1e5 + 5;
int in[MAX] , fn[MAX], ST[MAX] , tim[MAX], root , n , q , c , ans;
vector <int> adl[maxn];
map <int , bool> m;
void dfs(int x)
{
    in[x] = ++c;
    for(auto i : adl[x])
        dfs(i);
    fn[x] = ++c;
}
void update(int node , int x , int y , int a , int b , int v)
{
    if(x > b || y < a) return;

    if(x >= a && y <= b)
    {
        ST[node] = v;
        tim[node] = q+1;

        return;
    }
    if(ST[node])
    {
        if(tim[node * 2] > tim[node] || !tim[node * 2]){
          ST[node * 2] = ST[node];
          tim[node * 2] = tim[node];
        }
        if(tim[node * 2 + 1] > tim[node] || !tim[node * 2 + 1]){
          ST[node * 2 + 1] = ST[node];
          tim[node * 2 + 1] = tim[node];
        }
    }
    int mt = (x + y) >> 1;
    update(node * 2 , x , mt , a , b , v);
    update(node * 2 + 1, mt + 1 , y , a , b , v);
}
void query(int node , int x, int y , int a , int b)
{
    //cout<<tim[1]<<"\n";
    if(x > b || y < a) return;

    if(x >= a && y <= b)
    {
       //cout<<time[node]<<"\n";
       if(ST[node] && m.find(ST[node]) == m.end()){
         //  cout<<ST[node]<<"\n";
           ans++;
           m[ST[node]] = true;
       }
       return;
    }
    if(ST[node])
    {
        if(tim[node * 2] > tim[node] || !tim[node * 2]){
          ST[node * 2] = ST[node];
          tim[node * 2] = tim[node];
        }
        if(tim[node * 2 + 1] > tim[node] || !tim[node * 2 + 1]){
          ST[node * 2 + 1] = ST[node];
          tim[node * 2 + 1] = tim[node];
        }
    }
    int mt = (x + y) >> 1;
    query(node * 2 , x , mt , a , b);
    query(node * 2 + 1, mt + 1 , y , a , b);

}
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q;

    for(int i = 1 ; i <= n ; i++)
    {
        int x;
        cin>>x;
        if(!x)
            root = i;
        else
            adl[x].push_back(i);
    }
    dfs(root);

    while(q--)
    {
       // cout<<q<<"\n";
        int X , C;
        cin>>X>>C;
       // cout<<in[X]<<" "<<fn[X]<<"\n";
        update(1 , 1 , c , in[X] , fn[X] , C);
    }

     for(int i = 1 ; i <= n ; i++){
        query(1 , 1 , c , in[i] , fn[i]);
     }

    cout<<ans<<"\n";
}
