#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 10005;
const ll mod = 1e9 + 7;
#define f first
#define s second
#define db double
typedef pair <db ,db> point;
multiset <db> S;
point ar[1005];
db distancia(point a , point b)
{
    return sqrt((a.f-b.f) * (a.f-b.f) + (a.s-b.s) * (a.s-b.s));
}
vector <db> d;
bool comp(db a , db b)
{
    return a < b;
}
db mini[6] = {1e12 , 1e12 , 1e12 , 1e12 , 1e12 , 1e12};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    while(cin>>n  && n)
    {
       db mini[6] = {1e12 , 1e12 , 1e12 , 1e12 , 1e12 , 1e12};
       for(int i = 1 ; i <= n ; i++)
           cin>>ar[i].f>>ar[i].s;
       for(int i = 1 ; i <= n ; i++)
            for(int j = i+1 ; j <= n ; j++)
            {
               db cur = distancia(ar[i] , ar[j]);
               db may = 0.0;int pos = -1;
               for(int k = 0 ; k < 6 ; k++)
               {
                   if(may < mini[k])
                   {
                       may = mini[k];
                       pos = k;
                   }
               }
               if(may > cur) mini[pos] = cur;
            }

       db ans = 0.0;
       for(int i = 0 ; i < 6 ; i++) {ans += mini[i];
       }
       cout<<setprecision(2)<<fixed<<ans<<"\n";
    }
}
