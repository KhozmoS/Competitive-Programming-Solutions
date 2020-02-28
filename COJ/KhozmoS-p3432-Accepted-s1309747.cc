#include <bits/stdc++.h>

using namespace std;

typedef pair <int , int> ii;
typedef long long ll;
const ll mod = 10000019;
const int MAX = 1e6+5;
int n,pos;


int mp[1000019];

bool isp(int x)
{
    if(x==2) return true;
    if(x%2==0) return false;
    for(int i = 3 ; i * i <= x ; i += 2)
        if(x%i==0) return false;
    return true;
}
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   int n;
   while(cin>>n && n)
   {
       ll ans = 0;
       for(int i = 2 ; i <= n ; i++)
            if(isp(i)) ans += i;
       cout<<ans<<"\n";
   }
}
