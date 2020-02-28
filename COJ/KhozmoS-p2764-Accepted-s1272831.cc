#include <bits/stdc++.h>

using namespace std;


#define f first
#define s second
#define PB push_back
typedef pair <int , int> par;
typedef pair <int , par> circle;


bool cmp(circle x , circle y)
{
    if(x.f==y.f)
    {
        if(x.s.s > y.s.s) return true;

        return false;
    }
    return x.f < y.f;
}
int n;
vector <circle> v;
stack <circle> st;

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n;
   for(int i = 1; i <= n ; i++)
   {
       int x , r;
       cin>>x>>r;
       circle nw;
       nw.f = x-r;
       nw.s.f = x+r;
       nw.s.s = 2*r;
       v.PB(nw);
   }
   sort(v.begin() , v.end() , cmp);
   int ans = n+1;
   for(int i = 0 ; i < v.size() ; i++)
   {
       while(!st.empty() && st.top().s.f <= v[i].f) st.pop();
       //cout<<v[i].f<<"\n";
       if(!st.empty())
       {
           st.top().s.s -= v[i].s.s;
           //cout<<st.top().s.s<<"\n";

           if(!st.top().s.s) ans++;
       }
       st.push(v[i]);
   }
   cout<<ans<<"\n";
}
