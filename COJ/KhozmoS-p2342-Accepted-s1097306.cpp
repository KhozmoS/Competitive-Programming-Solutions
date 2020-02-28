#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

string a , b;
int ansa , ansb;
int sa , sb , n , t;
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>t;
   while(t--){
   cin>>n;
   cin>>a;
   ansa = -100;
   sa = 0;
   for(int i = 0 ; i < n ; i++)
   {
      int x;
      cin>>x;
      sa += x;
      if(sa > ansa) ansa = sa;
      //cout<<sa<<" .";
      if(sa < 0) sa = 0;
   }
  // cout<<"\n";
   cin>>b;
   ansb = -100;
   sb = 0;
   for(int i = 0 ; i < n ; i++)
   {
      int x;
      cin>>x;
      sb += x;
      if(sb > ansb) ansb = sb;

      if(sb < 0) sb = 0;
   }
   if(ansa > ansb) cout<<a<<" "<<ansa<<"\n";
   else if(ansb > ansa) cout<<b<<" "<<ansb<<"\n";
   else cout<<"Tied "<<ansa<<"\n";
   }
}
