#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n , m , y;
vector <ll> ans;

ll exp(ll a , ll b)
{
    ll res = 1;

    while(b > 0)
    {
        if(b & 1) res = (res * a) % m;

        a = (a * a) % m;
        b >>= 1;
    }

    return res;
}
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);

   while(cin>>n>>m>>y && n)
   {
       for(ll x = 1 ; x < m ; x++)
          if(exp(x , n) == y)
             ans.push_back(x);
       if(!(ans.size())) {cout<<"-1\n";continue;}

       for(int i = 0 ; i < ans.size() ; i++)
          cout<<ans[i]<<(i == ans.size() - 1 ? "\n" : " ");
       ans.clear();
   }
    return 0;
}
