#include <bits/stdc++.h>

using namespace std;
int q , a , b;
int n , x;
char v[] = {'P' , 'E' , 'R'};
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin>>n>>x;
  int ans = 0;

  for(int i = 0 ; i < n ; i++)
  {
      int c;
      cin>>a>>b;
      if(b < a) swap(a , b);

      if(abs(a - b) > x)
      {
        cin>>b;
      }
      ans += b;
  }
  cout<<ans<<"\n";
    return 0;
}
