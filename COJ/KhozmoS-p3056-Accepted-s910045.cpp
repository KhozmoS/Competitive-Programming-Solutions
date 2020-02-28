#include<bits/stdc++.h>

using namespace std;
char a [5] ; char b[5];
bool flag;
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
      for(int i = 0 ; i < 5 ; i++)
      {
          cin>> a[i];
      }
      for(int i = 0 ; i < 5 ; i++)
      {
          cin>> b[i];
      }
        for(int i = 0 ; i < 5 ; i++){
          if(a[i] == b[i])
          {
              flag = true;
              break;
          }
      }
       if(flag)
        cout<< 'N' << "\n";
       else
        cout<< 'Y' << "\n";
    return 0;
}
