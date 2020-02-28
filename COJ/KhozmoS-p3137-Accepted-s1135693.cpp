
#include <bits/stdc++.h>

using namespace std;


int a , b , c;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t ;

    cin>>t;

    while(t--)
    {
      cin>>a>>b>>c;

      if(a + b == c) cout<<"YES\n";

      else if(a - b == c) cout<<"YES\n";

      else if(a * b == c) cout<<"YES\n";

      else if(!b) cout<<"NO\n";

      else if(a / b == c || a % b == c) cout<<"YES\n";

      else cout<<"NO\n";

    }

    return 0;
}
 




