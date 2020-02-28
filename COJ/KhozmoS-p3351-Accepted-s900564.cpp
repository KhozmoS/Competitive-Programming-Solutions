#include<bits/stdc++.h>

using namespace std;
string a , b;
int t;
bool flag;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>t;
   while(t--)
   {
     flag = 0;
     cin>>a;
     int ta = a.size();
     for(int i = 0 ; i < ta ; i++)
     {
         //AHIMOTUVWXY
         if(a[i] == 'A' || a[i] == 'H' || a[i] == 'I' || a[i] == 'M' || a[i] == 'O' || a[i] == 'T' || a[i] == 'U' || a[i] == 'V' || a[i] == 'W' || a[i] == 'X' || a[i] == 'Y')
         {
           flag = true;
         }
         else flag = false;
     }
      if(flag){
        b = a;
       reverse(a.begin() , a.end());
      if(a == b)
        cout<<"YES\n";
      else cout<<"NO\n";
      }
      else cout<<"NO\n";
   }

    return 0;
}
