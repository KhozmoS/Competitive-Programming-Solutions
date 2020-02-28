#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL N , L , R;

//K L     K R

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
   cin>>t;
     while(t--)
     {
         cin>>N>>L>>R;
         LL k = N / L;
         if(N <= R * k)
           cout<<"Yes\n";
         else cout<<"No\n";
     }
    return 0;
}
