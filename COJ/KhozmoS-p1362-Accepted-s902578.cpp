#include<bits/stdc++.h>

using namespace  std;
int a , b , c;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>a>>b>>c)
    {
        if(a == 0 && b == 0 && c == 0)
          break;
        if(c % __gcd(a , b) == 0)
          cout<<"YES\n";
        else
          cout<<"NO\n";

    }
   // cout<<":AD";
    return 0;
}
