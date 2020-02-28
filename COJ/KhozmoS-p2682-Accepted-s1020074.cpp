#include <bits/stdc++.h>

using namespace std;

int t;
string a , b;



int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
     cin>>t;

      bool flag = true;
      cin>>a>>b;
      if(t % 2 == 1){
      for(int i = 0 ; i < a.size() ; i++)
      if(a[i] == b[i]){
      flag = false;
      break;
      }
      }
      else {
      for(int i = 0 ; i < a.size() ; i++)
      if(a[i] != b[i]){
      flag = false;
      break;
      }
      }



      if(flag)
      cout<<"Deletion succeeded\n";
      else
      cout<<"Deletion failed\n";

    return 0;
}
