#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int , int > par;


vector<par> diag;
int ta;
bool mk[105][105];

ll sol(ll n)
{
    ll ret = 0;

  for(int i = 1 ; i < n ; i++)
  for(int j = i + 1 ; j <= n ; j++)
  {
    if(!mk[i][j])
    {
     for(int k = 0 ; k < ta ; k++)
      if(diag[k].first < i && diag[k].second > i && diag[k].second < j)
                ret++;

      mk[i][j] = true;
      mk[j][i] = true;
      par p; p.first = i; p.second = j;
      diag.push_back(p);
      ta++;
    }
  }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);


    ll n;

    cin>>n;



    cout<<sol(n)<<"\n";

    return 0;
}
