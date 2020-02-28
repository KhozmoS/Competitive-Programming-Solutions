#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n , m;

int main()
{
   int t;cin>>t;
   while(t--)
   {
       
       cin>>n>>m;
       if(n > m) swap(n , m);
       if(__gcd(n , m) != n)
       {
           cout<<"-1\n";
           continue;
       }
       cout<<n<<" "<<m<<"\n";
   }
}
