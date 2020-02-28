#include <bits/stdc++.h>

using namespace std;
#define ff first.first
#define fs first.second
#define s second

typedef long long ll;
typedef pair <ll , ll> par;
typedef pair <par , ll> trio;
const int MAX = 305;

trio node[MAX];
double dis(ll x , ll y , ll a , ll b)
{
   ll sqa = (x - a) * (x - a);
   ll sqb = (y - b) * (y - b);

   return (double)(sqrt(sqa + sqb));

}
double dp[MAX][MAX];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    ll cx , cy , lx, ly;
    cin>>n>>cx>>cy>>lx>>ly;
    node[0] = trio(par(cx , cy) , 0ll);
    node[1] = trio(par(lx , ly) , 0ll);

    for(int i = 0 ; i < n ; i++)
    {
        ll x , y , f;
        cin>>x>>y>>f;
        node[i + 2] = trio(par(x , y) , f);
    }
    n += 2;
    double inf = 1e10;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
               dp[i][j] = inf;

    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
         {
           double d = dis(node[i].ff , node[i].fs , node[j].ff , node[j].fs);
            //cout<<i<<" "<<j<<" "<<d<<"\n";
           if(i != j){
            dp[i][j] = min(d , abs(d - node[i].s));
           }

         }

   for(int k = 0 ; k < n ; k++)
      for(int i = 0 ; i < n ; i++)
         for(int j = 0 ; j < n ; j++){
            if(i != j)
            dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j]);
         }
            cout<<setprecision(2)<<fixed<<dp[0][1]<<"\n";

    return 0;
}
