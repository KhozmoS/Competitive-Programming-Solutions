#include <bits/stdc++.h>

using namespace std;


int main()
{
ios_base::sync_with_stdio(0);cin.tie(0);
  int t;
  cin>>t;
    while(t--)
    {
        int a, b , c;
        cin>>a;
        char x;
        cin>>x;
        cin>>b;
        char eq;
        cin>>eq;
        cin>>c;
        if(x == '+')
        {
            if(a + b == c)
            cout<<"Yes\n";
            else cout<<"No\n";
        }
        else if(x == '-')
        {
            if(a - b == c)
            cout<<"Yes\n";
            else cout<<"No\n";
        }
        else if(x == '*')
        {
            if(a * b == c)
            cout<<"Yes\n";
            else cout<<"No\n";
        }
       else if(x == '/')
        {
            if(b != 0 && a / b == c)
            cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
    return 0;
}
