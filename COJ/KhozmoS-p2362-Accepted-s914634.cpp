#include<bits/stdc++.h>

using namespace std;
long long t , n , sol = 1 , ad = 0;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>t;
    while(t--)
    {
     cin>>n;
     for(int i = 0 ; i < n ; i++)
      {
          sol += ad;
          ad += 4;
      }
      cout<<sol<<"\n";
      sol = 1;
      ad = 0;
    }
 return 0;
}
