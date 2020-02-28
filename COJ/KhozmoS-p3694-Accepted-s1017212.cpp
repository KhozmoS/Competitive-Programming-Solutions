#include <bits/stdc++.h>

using namespace std;
const int MAXN = 111111;
typedef long long LL;

int cubos[MAXN];

void generar()
{
  for(int i = 1 ; i <= 1005 ; i++)
  cubos[i] = i * i * i;

}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t , n;
  generar();
    while(cin>>n && n != 0)
    {
        int sol = 0;
      for(int i = 1 ; i <= MAXN ; i++)
      {
          if(cubos[i] > n)
          break;

          if(n % cubos[i] == 0)
          sol++;
      }
      cout<<sol<<"\n";
    }
    return 0;
}
