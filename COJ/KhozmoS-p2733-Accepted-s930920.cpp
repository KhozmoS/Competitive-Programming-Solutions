#include <bits/stdc++.h>

using namespace std;
const int MAXN = 13;
 string sub = "";
 string cad;
 bool check(string s)
 {
     int ta = s.size();
     int mult = 1;
     for(int i = 1 ; i < ta ; i++)
     mult *= 10;
     int n = 0;
     for(int i = 0 ; i < ta ; i++)
     {
         n += ((s[i] - '0') * mult);
         mult /= 10;
     }
    // cout<<n;
     if(n > 255 || n < 0)
     return false;
     return true;
 }
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //cout << "Hello world!" << endl;
   // cin>>ip;
   //check("256");
   int t;
   cin>>t;
   while(t--){
     cin>>cad;
      int contp = 0;bool flag = false;
      if(cad[0] == '.' || cad[cad.size() - 1] == '.')
      flag = true;
      for(int i = 0 ; i < cad.size() - 1 ; i++)
      {
          if(cad[i] == '.' && cad[i + 1] == '.')
          flag = true;
      }
     for(int i = 0 ; i < cad.size() ; i++)
     {

         if(cad[i] != '.')
          sub += cad[i];
         if(cad[i] == '.' || i == cad.size() - 1)
         {
             if(cad[i] == '.')
             contp++;
             if(check(sub))
             sub = "";
             else
             flag = true;
             sub = "";
         }
         if(flag)
         break;
     }
     if(!flag && (contp == 3 || contp == 5)) cout<<"SI\n";
     else cout<<"NO\n";
   }
    return 0;
}
