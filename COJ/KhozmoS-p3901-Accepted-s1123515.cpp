#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e4 + 5;


int x , y , x2 , y2 , x3 , y3 , x4 , y4;

int w , h;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  cin>>x>>y>>x2>>y2>>x3>>y3>>x4>>y4>>w>>h;
  bool ans = false;

   int h1 = max(y3 - y , y2 - y4);
   int w1 = max(x3 - x , x2 - x4);
   //cout<<h1<<" "<<w1<<"\n";
   if(w <= w1 && h <= y2 - y)
     ans = true;
   if(h <= h1 && w <= x2 - x)
     ans = true;

   if(ans) cout<<"Yes\n";
   else cout<<"No\n";
    return 0;
}
