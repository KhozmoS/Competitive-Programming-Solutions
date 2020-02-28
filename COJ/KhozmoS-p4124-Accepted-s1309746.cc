#include <bits/stdc++.h>

using namespace std;

typedef pair <int , int> ii;
typedef long long ll;
const ll mod = 10000019;
const int MAX = 1e6+5;
int n,pos;


int mp[1000019];


int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
   int ans = 1;
   for(int i = 1 ; i <= n ; i++)
   {
       int x;cin>>x;
       if(!mp[x]) mp[x] = i;
       else ans = max(ans , i-mp[x]+1);
   }
   cout<<ans<<"\n";
}
