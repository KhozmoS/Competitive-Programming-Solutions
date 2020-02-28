#include<bits/stdc++.h>

using namespace std;
const int MAX = 1e5 + 5;

int C1H[MAX];
int C0H[MAX];
int C1[MAX];
int C0[MAX];
vector <int> O1;
vector <int> O;

string cola , hel;

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  O.push_back(0);
  O1.push_back(0);
  int n;
  cin>>n;

  cin>>cola>>hel;
  cola = " " + cola;
  hel = " " + hel;
  for(int i = 1 ; i <= n ; i++)
  {
   if(cola[i] == '0')
   {
    C0H[i]++;
   }
   if(hel[i] == '0')
   {
    C0[i]++;
    O.push_back(i);
   }
   if(cola[i] == '1')
    C1H[i]++;
   if(hel[i] == '1')
   {
    C1[i]++;
    O1.push_back(i);
   }
  }
  for(int i = 1 ; i <= n ; i++)
  {
    C0H[i] += C0H[i - 1];
    C1H[i] += C1H[i - 1];
    C0[i] += C0[i - 1];
    C1[i] += C1[i - 1];
  }
  int cero = 1;
  int uno = 1;
  for(int i = 1 ; i <= n ; i++)
  {
    if(cola[i] == '1')
    {
      int can = C0[O1[uno]];
      if(can == 0)
      {
         cout<<"0\n";
         uno++;
         continue;
      }
      cout<<(((can - C0H[i]) < 0) ? 0 : (can - C0H[i]))<<"\n";
      uno++;
    }
    if(cola[i] == '0')
    {
      int can = C1[O[cero]];
      if(can == 0)
      {
         cout<<"0\n";
         cero++;
         continue;
      }
      cout<<(((can - C1H[i]) < 0) ? 0 : can - C1H[i])<<"\n";
      cero++;
    }
  }
  return 0;
}
