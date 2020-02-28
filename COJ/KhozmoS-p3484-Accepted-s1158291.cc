#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second
#define PB push_back
const int MAX = 1e5 + 5;

vector <int> RMQ[MAX][20];
vector <int> combination(vector <int> a , vector <int> b)
{
    vector <int> res;
    vector <int> aux;
    res.clear();
    aux.clear();
    set <int> S;
    S.clear();

    for(int i = 0 ; i < a.size() ; i++){
         aux.push_back(a[i]);
         S.insert(a[i]);
    }
    for(int i = 0 ; i < b.size() ; i++){
         if(S.find(b[i]) == S.end())
         aux.push_back(b[i]);
    }

    sort(aux.begin() , aux.end());

    for(int i = 0 ; i < min((int)aux.size() , 100) ; i++)
        res.push_back(aux[i]);

    return res;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n , m , q;

  cin>>n>>m>>q;

  for(int i = 1 ; i <= m ; i++)
  {
      int pep;cin>>pep;
      vector <int> p;
      for(int j = 0 ; j < pep ; j++)
      {
          int x;cin>>x;
          p.push_back(x);

      }
      sort(p.begin() , p.end());

      for(int j = 0 ; j < min(100 , (int)p.size()) ; j++)
          RMQ[i][0].push_back(p[j]);

      p.clear();
  }

  for(int i = 1; (1 << i) <= m; i++)
        for(int j = 1; j <= m - (1 << i) + 1; j++)
          RMQ[j][i] = combination(RMQ[j][i - 1], RMQ[j + (1 << (i - 1))][i - 1]);

  while(q--)
  {
      int a , b;cin>>a>>b;

      if(a > b)swap(a , b);
      int l = log2(b - a + 1);
      vector <int> ans = combination(RMQ[a][l], RMQ[b - (1 << l) + 1][l]);
      for(int i = 0 ; i < min((int)ans.size() , 10) ; i++) cout<<ans[i]<<(i == min((int)(ans.size() - 1) , 9) ? "\n" : " ");
      if(!ans.size())cout<<"\n";
  }
}
