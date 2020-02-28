#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1005;

typedef pair <int , int> par;
typedef pair <par , int> trio;

int n;
int P , S , E;

int abi[MAXN][MAXN];
int ta[MAXN][MAXN];
int mk[MAXN][MAXN];

vector<trio> queries;

void update(int p , int pos , int val)
{

    for(int i = pos ; i < MAXN ; i += (i & -i))
    abi[p][i] += val;

}

int sum(int x , int y)
{
    int suma = 0;
    for(int i = y ; i > 0 ; i -= (i & -i))
     suma += (abi[x][i]);

    return suma;
}

void tabla()
{

  for(int i = 1 ; i < MAXN ; i++)
  for(int j = 1 ; j < MAXN ; j++)
  {
    ta[i][j] = sum(i , j) + ta[i - 1][j];
  }

}

int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);

   cin>>n;

   for(int i = 0 ; i < n ; i++)
   {
      char c;
      cin>>c>>P>>S>>E;

      if(S > E)
        swap(S , E);

      if(c == 'V')
      {
          trio p;
          p.first.first = P;
          p.first.second = S;
          p.second = E;
          queries.push_back(p);
      }
      else
      {
         update(P , S , 1);
         update(P , E + 1 , -1);
      }
   }

   tabla();

    int solu = 0;
    for(int i = 0 ; i < queries.size() ; i++)
    {
        //queries[i].first.first
        solu += (ta[queries[i].second][queries[i].first.first] - ta[queries[i].first.second - 1][queries[i].first.first]);

    }

      /*  for(int i = 0 ; i < 10 ; i++){
        for(int j = 0 ; j < 10 ; j++)
          cout<<ta[i][j]<<" ";

          cout<<"\n";
          }
*/
    cout<<solu<<"\n";

    return 0;
}
