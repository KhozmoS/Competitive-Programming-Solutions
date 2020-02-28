//1279 - Fermat's Christmas GREATSHIT!!
//by KhozmoS

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int ans;
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   string a;
   cin>>a;
   int sza = a.size();
   string b;
   while(cin>>b)
   {
       for(int i = 0 ; i + sza <= b.size() ; i++)
       {
           if(b.substr(i , sza) == a)
               ans++;
       }
   }
   cout<<ans<<"\n";
}
