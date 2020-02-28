#include <bits/stdc++.h>

using namespace std;
string cad , S;
map<string , int > m;
map<string , int > :: iterator it;
int  k , ta;
bool flag;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>k;
    cin>>cad;
    //cad = "pedro el tremendo";
    //cout<<cad.substr(4,)

      ta = cad.size();
      int t = ta;
      int i = 0;
      while(t){
       i = 0;
       m.clear();
      while(i + t <= ta)
      {
       S = cad.substr(i , t);
       m[S]++;
       //cout<<S<<"\n";
       S = "";
       i++;
      }
      for(it = m.begin(); it != m.end() ; it++)
      {
          if((*it).second == k){
          cout<<(*it).first.size()<<"\n";
          flag = true;
          break;
          }
      }
      if(flag)
      break;
      if(t == 1)
      cout<<"-1\n";
      t--;
    }

    return 0;
}
