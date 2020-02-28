#include <bits/stdc++.h>

using namespace std;
const int MAXN = 10005;


int p[MAXN];

  int find(int x)
  {
    if(p[x] == x)
     return x;

    return p[x] = find(p[x]);
  }
bool mk[MAXN];
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
  int t;
   cin>>t;
   while(t--){
    int n , m;
    cin>>n>>m;
      for(int i = 1 ; i <= n ; i++) p[i] = i;

      for(int i = 1 ; i <= m ; i++)
      {
          int a , b;
          cin>>a>>b;
          int x = find(a);
          int y = find(b);
          if(x != y)
          {
           p[x] = y;
          }
      }

      for(int i = 1 ; i <= n ; i++)
      int e = find(i);

      memset(mk , false , sizeof(mk));
      int sol = 0;

      for(int i = 1 ; i <= n ; i++ )
      {
         //cout<<i<<"=>"<<p[i]<<"\n";

         if(!mk[p[i]])
         {
          // cout<<p[i]<<" ";
           sol++;
           mk[p[i]] = true;
         }
      }
//      cout<<"\n";
  //     cout<<sol<<"\n";
      cout<<((sol * (sol - 1)) / 2)<<"\n";
   }
    return 0;
}
