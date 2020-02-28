#include<bits/stdc++.h>
using namespace std;
string sol = "625";
int n;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
     if(n == '1')
     cout<<'625'<<endl;
     else{
      for(int i = 1 ; i < n ; i++)
      {
         sol += '0';
      }
      cout<<sol<<"\n";
     }
    return 0;
}
