#include <bits/stdc++.h>

using namespace std;
vector <int> pri;
const int MAXN = 35000;
bool comp[MAXN];

void criba()
{
    for(int i = 4 ; i <= MAXN ; i += 2)
    comp[i] = true;

    for(int i = 3 ; i * i <= MAXN ; i += 2)
    {
        if(!comp[i]){
        for(int j = i * i ; j <= MAXN ; j += i)
        comp[j] = true;
        }
    }
    pri.push_back(2);
    for(int i = 3 ; i <= MAXN ; i += 2)
    {
        if(!comp[i])
        pri.push_back(i);
    }
   // cout<<comp[3]<<"\n";
}
  bool is_prime(int x)
  {
      if(x == 0 || x == 1) return false;

      if(x == 2) return true;

      if(x % 2 == 0) return false;

      for(int i = 1 ; pri[i] * pri[i] <= x ; i ++)
      if(x % pri[i] == 0) return false;

      return true;
  }
  int n , m;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //cin>>N>>Q;
    criba();
   // for(int i = 0 ; i < 10 ; i ++) cout<<pri[i]<<" ";

    int t; cin>>t;

    while(t--)
    {
    cin>>n>>m;
    for(int i = n ; i <= m ; i++)
    if(is_prime(i))
    cout<<i<<"\n";

    cout<<"\n";
    }

    return 0;
}
