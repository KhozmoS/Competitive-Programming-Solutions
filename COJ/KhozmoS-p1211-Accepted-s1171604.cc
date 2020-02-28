#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define db double
#define x first
#define y second

typedef vector <ll> VI;
const db pi = acos(-1);
const db sen = sin(60 * pi/180);
const int MAX = 1e3 + 5;
VI T[MAX];
typedef pair <ll , ll > point;
point ar[MAX];
ll dist(ll x1 , ll y1 , ll x2 , ll y2)
{
    ll sqx = (x1-x2) * (x1-x2);
    ll sqy = (y1-y2) * (y1-y2);
    return sqx + sqy;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    while(cin>>n && n){

    for(int i = 1 ; i <= n ; i++){
        cin>>ar[i].x>>ar[i].y;
        T[i].clear();
    }
    sort(ar+1 , ar + n+1);
    ll ans = 0;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++) if(i != j)
           T[i].push_back(dist(ar[i].x , ar[i].y , ar[j].x , ar[j].y));
        sort(T[i].begin() , T[i].end());
    }
    for(int i = 1 ; i <= n ; i++)
    {
        ll sz = 1;
        for(int j = 1 ; j < T[i].size() ; j++)
        {
            if(T[i][j] != T[i][j-1])
            {
                ans += sz * (sz-1) / 2ll;
                sz = 1ll;
            }
            else sz++;
        }
        ans += sz * (sz-1) / 2ll;
    }
     cout<<ans<<"\n";
    }
}
