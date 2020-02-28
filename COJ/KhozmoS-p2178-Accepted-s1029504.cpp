#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 30;

ll freq[MAXN];

ll fact(ll x)
{
   ll sol = 1;
   for(ll i = 1 ; i <= x ; i++)
   sol *= i;

   return sol;
}
int c = 1111111;
int mi = c;
int t;
int main()
{
   //cout<<fact(20);
   ios_base::sync_with_stdio(0);cin.tie(0);

   int n;
   cin>>n;
   int sol = 0;

   for(int i = 0 ; i < n ; i++)
   {
    int a;
    cin>>a;
    if(a % 2 == 1 && a < mi)
    mi = a;

    sol += a;

   }
    if(!sol || (mi == c && sol % 2 == 0))
    {
        cout<<"-1\n";
        return 0;
    }
    if(sol % 2 == 1)
    {
        cout<<sol<<"\n";
        return 0;
    }

    cout<<sol - mi<<"\n";

    return 0;
}
