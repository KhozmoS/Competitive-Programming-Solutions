#include <bits/stdc++.h>

using namespace std;
#define PB push_back
typedef vector <int> VI;
typedef long long ll;
int n , sz;
VI pr;
const int mod = 1000000007;
ll F()
{
    ll res = 0;
    for(int mask = 1 ; mask < 1<<sz ; mask++)
    {
       int c = 0;
       int prod = 1;
       ll sum = 0;
       for(int i = 0 ; i < sz ; i++)
       {
           if(mask & (1<<i))
           {
               c++;
             //  ll m = (n / pr[i]) - (n%pr[i] == 0);
             //  sum += (((m * (m+1ll) / 2ll)%mod) * (pr[i]%mod)) % mod;
               prod *= pr[i];
           }
       }
       ll m = (n / prod) - (n % prod == 0);
       sum += (((m * (m+1ll) / 2ll)) * (prod));

       if(c&1) res += sum;
       else res -= sum;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>n)
    {
       int x = n;
       for(int i = 2 ; i * i <= x ; i++)
       {
           if(x % i == 0) pr.PB(i);
           while(x % i == 0) x /= i;
       }
       if(x-1) pr.PB(x);
   // for(int i = 0 ; i < pr.size() ; i++)cout<<pr[i]<<" ";
   // cout<<endl;
       sz = pr.size();
       cout<<F()%mod<<"\n";
       pr.clear();
    }
}
