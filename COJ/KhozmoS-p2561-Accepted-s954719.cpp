#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1111111;
int k , n;
string cad;
int ta[MAXN] , tb[MAXN];
bool sol(int x)
{
  int p1 = 1; int p2 = x;
  while(p2 <= n)
  {
      int ca = ta[p2] - ta[p1 - 1];

      if(k - ca >= 0)
      {
         int rest = k - ca;
         if(rest <= n - x)
         return true;
      }
      p1++; p2++;

  }
  return false;
}
bool sol1(int x)
{
  int p1 = 1; int p2 = x;
  while(p2 <= n)
  {
      int cb = tb[p2] - tb[p1 - 1];
      //int ca = x - cb;
      if(k - cb >= 0)
      {
         int rest = k - cb;
         if(rest <= n - x)
         return true;
      }
      p1++; p2++;

  }
  return false;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;

    cin>>t;

    while(t--)
    {
     //int k
     cin>>k>>cad;
     n = cad.size();
     for(int i = 0 ; i < n ; i++)
     {
         //ta[i + 1] = 0;
         if(cad[i] == '>')
         ta[i + 1] = (ta[i] + 1);
         else
         ta[i + 1] = (ta[i]);

         if(cad[i] == '<')
         tb[i + 1] = tb[i] + 1;
         else
         tb[i + 1] = tb[i];
     }
     // cout<<sol(7)<<" "<<ta[7]<<" "<<n<<"\n";

      int ini = 1; int fin = n;
      while(fin - ini >= 5)
      {
          int mit = (fin + ini) / 2;
          if(sol(mit))
          ini = mit;
          else
          fin = mit;
      }
      int r1 = -1;
      while(fin)
      {
          if(sol(fin))
          {
              r1 = fin;
              break;
          }
          fin--;
      }
      ini = 1; fin = n;
      while(fin - ini >= 5)
      {
          int mit = (fin + ini) / 2;
          if(sol1(mit))
          ini = mit;
          else
          fin = mit;
       }
      int r2 = -1;
      while(fin)
      {
          if(sol1(fin))
          {
              r2 = fin;
              break;
          }
          fin--;
      }

      cout<<max(r1 , r2)<<"\n";

      for(int i = 0 ; i <= n ; i++)
      ta[i] = tb[i] = 0;
    }


    return 0;
}
