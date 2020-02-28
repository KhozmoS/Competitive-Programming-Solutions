#include<bits/stdc++.h>


using namespace std;
const int MAX = 1000005;
typedef long long ll;

bool mku[MAX];
bool mkd[MAX];

vector <char> c1;
vector <char> c2;
string a , b;
int n , m;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>a>>a>>n;
  int cont = 0;
  for(int i = 0 ; i < n ; i++)
  {
      char x; cin>>x; c1.push_back(x);
      if(!mku[x]) cont++;
      mku[x] = true;
  }
  int ci = 0;
  int cdd = 0;
  int cdu = 0;
  cin>>b>>b>>m;
  for(int i = 0 ; i < m ; i++)
  {
      char x ; cin>>x;
      if(!mku[x]) cdd++;
      if(!mkd[x] && !mku[x]) cont++;
      mkd[x] = true;
      if(mkd[x] && mku[x]) ci++;
  }
  for(int i = 0 ; i < n ; i++)
    if(!mkd[c1[i]]) cdu++;

  cout<<a<<" U "<<b<<": {";
  int cant = 0;
  for(int i = 0 ; i < MAX ; i++)
  {
      if(mkd[i] || mku[i])
      {
        cant++;
        if(cant == cont)
          cout<<char(i);
        else
          cout<<char(i)<<",";
      }
  }
  cout<<"}\n";
    cant = 0;
    cout<<a<<" I "<<b<<": {";
  for(int i = 0 ; i < MAX ; i++)
  {
      if(mkd[i] && mku[i])
      {
        cant++;
        if(cant == ci)
          cout<<char(i);
        else
          cout<<char(i)<<",";
      }
  }
  cout<<"}\n";
  cant = 0;
    cout<<a<<" D "<<b<<": {";
  for(int i = 0 ; i < MAX ; i++)
  {
      if(mku[i] && !mkd[i])
      {
        cant++;
        if(cant == cdu)
          cout<<char(i);
        else
          cout<<char(i)<<",";
      }
  }
  cout<<"}\n";
  cant = 0;
    cout<<b<<" D "<<a<<": {";
  for(int i = 0 ; i < MAX ; i++)
  {
      if(!mku[i] && mkd[i])
      {
        cant++;
        if(cant == cdd)
          cout<<char(i);
        else
          cout<<char(i)<<",";
      }
  }
  cout<<"}\n";
  return 0;
}
