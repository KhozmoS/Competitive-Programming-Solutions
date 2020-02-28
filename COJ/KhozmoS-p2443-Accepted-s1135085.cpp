#include <bits/stdc++.h>

using namespace std;


typedef pair <int , int> par;

bool is_p(int x)
{
    if(x == 2) return true;
    if(!(x % 2)) return false;

    for(int i =  3 ; i * i <= x ; i += 2)
        if(!(x % i)) return false;

    return true;
}

int main()
{
  int n , k;

  cin>>n>>k;
  bool flag = true;
  int may = 0; int ans = 0;
  for(int player = 1 ; n-- ; player++)
  {
      int cont = 0;
      for(int i = 0 ; i < k ; i++)
      {
          int x; cin>>x;
          if(is_p(x))
            cont++;
      }
      if(cont > may)
      {
          may = cont;
          ans = player;
          flag = true;
      }
      else if(cont == may) flag = false;
  }
  if(!flag) cout<<"No winner\n";

  else cout<<"Object "<<ans<<" wins with "<<may<<" rare characteristics\n";
  return 0;
}
