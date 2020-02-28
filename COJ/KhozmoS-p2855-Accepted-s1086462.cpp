#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll ans , num;
string m;
void F()
{
  if(m[0] == '0') return;

  num = 0;
  for(int i = 0 ; i < n ; i++){
     num = (num * 10) + (m[i] - '0');
  }
  ans += num;
}
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
  
   while(cin>>m)
   {
       if(m == "0") return 0;
       
       ans = 0;
       
       sort(m.begin() , m.end());
       
       n = m.size();
       
       do{
         F();
       }while(next_permutation(m.begin() , m.end()));
       
       cout<<ans<<"\n";
   }
}
