#include <bits/stdc++.h>

using namespace std;

const int MAX = 30005;
typedef pair <int , int> par;


par ar[MAX];
int dp[MAX];
int me[MAX];

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  memset(me , -1 , sizeof(me));
  int n;
  cin>>n;
     par p;
     int may = -1;
  for(int i = 0 ; i < n ; i++)
  {
    cin>>p.first>>p.second;

    if(me[p.first] != -1)
      me[p.first] = min(me[p.first] , p.second);
    else
      me[p.first] =  p.second;

      may = max(may , p.first);
  }
  vector <par> juegos;
  juegos.push_back(make_pair(0 , -1));
 // cout<<juegos[0].second<<"\n";
  for(int i = 0 ; i <= may ; i++)
    if(me[i] != -1){
     juegos.push_back(make_pair(i , me[i]));
    }
  //  cout<<juegos[1].first<<" "<<juegos[1].second<<"\n";
   sort(juegos.begin() , juegos.end());

   int sol = 0;
  //for(int i = 1 ; i < juegos.size() ; i++)
  //  cout<<juegos[i].first<<" "<<juegos[i].second<<"\n";

  for(int i = 1 ; i < juegos.size() ; i++)
    for(int j = i - 1 ; j >= 0 ; j--)
      if(juegos[j].second < juegos[i].first){
        dp[i] = dp[j] + 1;
        sol = max(sol , dp[i]);
        break;
      }

   cout<<sol<<"\n";

  return 0;
}
