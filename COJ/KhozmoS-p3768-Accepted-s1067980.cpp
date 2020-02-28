//KhozmoS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 0;
typedef pair <int , int> par;
typedef pair <par , int> trio;
typedef map <string , int> mapa;
const int MAXN = 100005;
vector <int> v;
queue <int> cola;
ll ar[MAXN];int N;

ll T[MAXN];
int k;
ll ver(int cant , int pos)
{
  return T[pos] - T[pos - cant];
}
int bin(int pos)
{
 int ini = 1; int fin = pos;

  while(fin - ini > 3)
  {
    int mit = (fin + ini) / 2;
     if(ver(mit , pos) >= k)
      fin = mit;
      else
      ini = mit;
  }
   int r = MAXN;
   for(int i = fin ; i >= ini ; i--)
    if(ver(i , pos) == k)
    r = min(r , i);

    return r;
}
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>N>>k;

     for(int i = 1 ; i <= N ; i++)
      cin>>ar[i];

      T[1] = ar[1];

     for(int i = 2 ; i < N ; i++)
      T[i] = ar[i] + T[i - 1];

      int sol = MAXN;

     for(int i = 1 ; i <= N ; i++)
     {
       sol = min(sol , bin(i));
     }
    if(sol == MAXN)
    cout<<"-1\n";
    else
    cout<<sol<<"\n";
    return 0;
}
/*6 4
1
3
2
16 4
1
3
2
1
3
1
3
1*/
