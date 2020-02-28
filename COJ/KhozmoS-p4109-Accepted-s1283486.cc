#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define PB push_back

typedef pair <int , int> par;
const int MAX = 1e6+5;


int FT[MAX];

void update(int x , int v)
{
    for(;x>0 ; x-=(x&-x)) FT[x] = max(FT[x],v);
}

int query(int x)
{
    int res = 0;
    for(;x<MAX;x+=(x&-x)) res = max(res,FT[x]);
    return res;
}
bool cmp(par a , par b)
{
    if(a.f==b.f) return a.s>b.s;
    return a.f<b.f;
}
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   int t;
   cin>>t;
   while(t--)
   {
       int n;cin>>n;
       vector <par> v(n);
       for(int i = 0 ; i < n ; i++) cin>>v[i].s>>v[i].f;

       sort(v.begin() , v.end() , cmp);
       //for(int i = 0 ; i < n ; i++) cout<<v[i].f<<" "<<v[i].s<<"\n";
       int ans = 0;
       for(int i = 0 ; i < n ; i++)
       {
           int q = query(v[i].s);
           ans = max(ans , q+1);
           update(v[i].s , q+1);
       }

       cout<<ans<<"\n";
       memset(FT,0,sizeof(FT));
   }

}
