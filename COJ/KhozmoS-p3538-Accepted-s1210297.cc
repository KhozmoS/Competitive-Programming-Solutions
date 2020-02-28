#include <bits/stdc++.h>

using namespace std;

#define PB push_back
typedef long long ll;
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   ll n;
   int t;cin>>t;
   while(t--)
   {
       cin>>n;bool ok = false;
       ll i , N;
       for(i = 2 ; i <= (ll)sqrt(1000000000) ; i++)
       {
           N = n-((i*(i+1ll))/2ll);
           if(N<0)break;
           if(N%i==0)
           {
               ok = true;
               break;
           }
       }
       if(ok)
       {
           cout<<n<<" = ";
           for(ll j = 1 ; j <= i ; j++)
           {
               if(j==1)
               {
                   cout<<j+(N/i);
               }
               else
                    cout<<" + "<<j+(N/i);
           }
           cout<<"\n";
       }
       else cout<<"IMPOSSIBLE\n";
   }

}
