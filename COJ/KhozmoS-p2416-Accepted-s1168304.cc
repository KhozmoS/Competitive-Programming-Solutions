#include <bits/stdc++.h>

using namespace std;
#define PB push_back
typedef vector <int> VI;
typedef long long ll;

int sum(int x)
{
    int res = 0;
    while(x)
    {
        res += x%10;
        x /= 10;
    }
    return res;
}

bool ok(int x)
{
    for(int n = x ; n <= x + 64 ; n++)
    {
        if(n - sum(n) == x)
            return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       int ans = 0;
       for(int i = 1 ; i <= 9 ; i++)
          if(ok(n * 10 + i)){
              ans = i;
              break;
          }
        cout<<ans<<"\n";
    }
}
