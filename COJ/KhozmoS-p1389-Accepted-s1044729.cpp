#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100005;

string cad;

bool is_pal(string x)
{
    string y = x;
    reverse(y.begin() , y.end());

    if(x == y)
        return true;

    return false;
}
string sol;
int main()
{

 ios_base::sync_with_stdio(0);cin.tie(0);

   cin>>cad;

      for(int i = 0 ; i < cad.size() ; i++)
      {
       for(int j = i ; j < cad.size() ; j++)
       {
           string a = cad.substr(i , (j - i) + 1);
           if(is_pal(a))
           if(a.size() > sol.size())
            sol = a;
       }
      }
 cout<<sol<<"\n";
    return 0;
}
